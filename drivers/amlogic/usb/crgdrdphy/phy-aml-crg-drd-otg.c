// SPDX-License-Identifier: (GPL-2.0+ OR MIT)
/*
 * Copyright (c) 2019 Amlogic, Inc. All rights reserved.
 */

#include <linux/module.h>
#include <linux/io.h>
#include <linux/irq.h>
#include <linux/irqreturn.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/of.h>
#include <linux/clk.h>
#include <linux/err.h>
#include <linux/pm_runtime.h>
#include <linux/delay.h>
#include <linux/usb/phy.h>
#include <linux/amlogic/usb-v2.h>
#include <linux/amlogic/aml_gpio_consumer.h>
#include <linux/workqueue.h>
#include <linux/notifier.h>
#include <linux/amlogic/usbtype.h>
#include "../phy/phy-aml-new-usb-v2.h"

#include <linux/amlogic/gki_module.h>
#define HOST_MODE	0
#define DEVICE_MODE	1

struct amlogic_crg_otg {
	struct device           *dev;
	void __iomem    *phy3_cfg;
	void __iomem    *phy3_cfg_r1;
	void __iomem    *phy3_cfg_r2;
	void __iomem    *phy3_cfg_r4;
	void __iomem    *phy3_cfg_r5;
	void __iomem    *usb2_phy_cfg;
	struct delayed_work     work;
};

bool crg_force_device_mode;
module_param_named(otg_device, crg_force_device_mode,
		bool, 0644);

static char otg_mode_string[2] = "0";
static int force_otg_mode(char *s)
{
	if (s)
		sprintf(otg_mode_string, "%s", s);
	if (strncmp(otg_mode_string, "0", 1) == 0)
		crg_force_device_mode = 0;
	else
		crg_force_device_mode = 1;
	return 0;
}
__setup("otg_device=", force_otg_mode);

static void set_mode
	(unsigned long reg_addr, int mode, unsigned long phy3_addr);

static int amlogic_crg_otg_init(struct amlogic_crg_otg *phy)
{
	union usb_r1_v2 r1 = {.d32 = 0};
	union u2p_r2_v2 reg2 = {.d32 = 0};
	struct usb_aml_regs_v2 usb_crg_otg_aml_regs;

	usb_crg_otg_aml_regs.usb_r_v2[1] = phy->phy3_cfg + 4;

	r1.d32 = readl(usb_crg_otg_aml_regs.usb_r_v2[1]);
	r1.b.u3h_fladj_30mhz_reg = 0x20;
	writel(r1.d32, usb_crg_otg_aml_regs.usb_r_v2[1]);

	reg2.d32 = readl((void __iomem *)((unsigned long)phy->usb2_phy_cfg + 8));
	reg2.b.iddig_en0 = 1;
	reg2.b.iddig_en1 = 1;
	reg2.b.iddig_th = 255;
	writel(reg2.d32, (void __iomem *)((unsigned long)phy->usb2_phy_cfg + 8));

	return 0;
}

static void set_mode(unsigned long reg_addr, int mode, unsigned long phy3_addr)
{
	struct u2p_aml_regs_v2 u2p_aml_regs;
	union u2p_r0_v2 reg0;

	u2p_aml_regs.u2p_r_v2[0] = (void __iomem *)((unsigned long)reg_addr);

	reg0.d32 = readl(u2p_aml_regs.u2p_r_v2[0]);
	if (mode == DEVICE_MODE) {
		reg0.b.host_device = 0;
		reg0.b.POR = 0;
	} else {
		reg0.b.host_device = 1;
		reg0.b.POR = 0;
	}
	writel(reg0.d32, u2p_aml_regs.u2p_r_v2[0]);

	usleep_range(500, 600);
}

static void amlogic_crg_otg_work(struct work_struct *work)
{
	struct amlogic_crg_otg *phy =
		container_of(work, struct amlogic_crg_otg, work.work);
	union u2p_r2_v2 reg2;
	unsigned long reg_addr = ((unsigned long)phy->usb2_phy_cfg);
	unsigned long phy3_addr = ((unsigned long)phy->phy3_cfg);

	reg2.d32 = readl((void __iomem *)(reg_addr + 8));
	if (reg2.b.iddig_curr == 0) {
		/* to do*/
		crg_gadget_exit();
		set_mode(reg_addr, HOST_MODE, phy3_addr);
		crg_init();
	} else {
		/* to do*/
		crg_exit();
		set_mode(reg_addr, DEVICE_MODE, phy3_addr);
		crg_gadget_init();
	}
	reg2.b.usb_iddig_irq = 0;
	writel(reg2.d32, (void __iomem *)(reg_addr + 8));
}

static irqreturn_t amlogic_crgotg_detect_irq(int irq, void *dev)
{
	struct amlogic_crg_otg *phy = (struct amlogic_crg_otg *)dev;
	union u2p_r2_v2 reg2;

	reg2.d32 = readl((void __iomem *)((unsigned long)phy->usb2_phy_cfg + 8));
	reg2.b.usb_iddig_irq = 0;
	writel(reg2.d32, (void __iomem *)((unsigned long)phy->usb2_phy_cfg + 8));

	schedule_delayed_work(&phy->work, msecs_to_jiffies(10));

	return IRQ_HANDLED;
}

static int amlogic_crg_otg_probe(struct platform_device *pdev)
{
	struct amlogic_crg_otg			*phy;
	struct device *dev = &pdev->dev;
	void __iomem *usb2_phy_base;
	unsigned int usb2_phy_mem;
	unsigned int usb2_phy_mem_size = 0;
	void __iomem *usb3_phy_base;
	unsigned int usb3_phy_mem;
	unsigned int usb3_phy_mem_size = 0;
	const void *prop;
	int irq;
	int retval;
	int otg = 0;
	int controller_type = USB_NORMAL;
	union u2p_r2_v2 reg2;
	unsigned long reg_addr;

	prop = of_get_property(dev->of_node, "controller-type", NULL);
	if (prop)
		controller_type = of_read_ulong(prop, 1);

	retval = of_property_read_u32
				(dev->of_node, "usb2-phy-reg", &usb2_phy_mem);
	if (retval < 0)
		return -EINVAL;

	retval = of_property_read_u32
		(dev->of_node, "usb2-phy-reg-size", &usb2_phy_mem_size);
	if (retval < 0)
		return -EINVAL;

	usb2_phy_base = devm_ioremap_nocache
				(&pdev->dev, (resource_size_t)usb2_phy_mem,
				(unsigned long)usb2_phy_mem_size);
	if (!usb2_phy_base)
		return -ENOMEM;

	retval = of_property_read_u32
				(dev->of_node, "usb3-phy-reg", &usb3_phy_mem);
	if (retval < 0)
		return -EINVAL;

	retval = of_property_read_u32
		(dev->of_node, "usb3-phy-reg-size", &usb3_phy_mem_size);
	if (retval < 0)
		return -EINVAL;

	usb3_phy_base = devm_ioremap_nocache
				(&pdev->dev, (resource_size_t)usb3_phy_mem,
				(unsigned long)usb3_phy_mem_size);
	if (!usb3_phy_base)
		return -ENOMEM;

	phy = devm_kzalloc(&pdev->dev, sizeof(*phy), GFP_KERNEL);
	if (!phy)
		return -ENOMEM;

	if (controller_type == USB_OTG)
		otg = 1;

	dev_info(&pdev->dev, "controller_type is %d\n", controller_type);
	dev_info(&pdev->dev, "crg_force_device_mode is %d\n", crg_force_device_mode);
	dev_info(&pdev->dev, "otg is %d\n", otg);

	dev_info(&pdev->dev, "phy2_mem:0x%lx, iomap phy2_base:0x%lx\n",
		 (unsigned long)usb2_phy_mem,
		 (unsigned long)usb2_phy_base);

	dev_info(&pdev->dev, "phy3_mem:0x%lx, iomap phy3_base:0x%lx\n",
		 (unsigned long)usb3_phy_mem,
		 (unsigned long)usb3_phy_base);

	phy->dev		= dev;
	phy->usb2_phy_cfg	= usb2_phy_base;
	phy->phy3_cfg = usb3_phy_base;

	INIT_DELAYED_WORK(&phy->work, amlogic_crg_otg_work);

	platform_set_drvdata(pdev, phy);

	pm_runtime_enable(phy->dev);

	if (otg) {
		irq = platform_get_irq(pdev, 0);
		if (irq < 0)
			return -ENODEV;
		retval = request_irq(irq, amlogic_crgotg_detect_irq,
				 IRQF_SHARED, "amlogic_botg_detect", phy);

		if (retval) {
			dev_err(&pdev->dev, "request of irq%d failed\n", irq);
			retval = -EBUSY;
			return retval;
		}
	}

	amlogic_crg_otg_init(phy);

	if (otg == 0) {
		if (crg_force_device_mode || controller_type == USB_DEVICE_ONLY) {
			set_mode((unsigned long)phy->usb2_phy_cfg,
				DEVICE_MODE, (unsigned long)phy->phy3_cfg);
			crg_gadget_init();
		} else if (controller_type == USB_HOST_ONLY) {
			crg_init();
			set_mode((unsigned long)phy->usb2_phy_cfg,
				HOST_MODE, (unsigned long)phy->phy3_cfg);
		}
	} else {
		reg_addr = ((unsigned long)phy->usb2_phy_cfg);
		reg2.d32 = readl((void __iomem *)(reg_addr + 8));
		if (reg2.b.iddig_curr == 0) {
			set_mode(reg_addr, HOST_MODE,
				(unsigned long)phy->phy3_cfg);
			crg_init();
		} else {
			set_mode(reg_addr, DEVICE_MODE,
				(unsigned long)phy->phy3_cfg);
			crg_gadget_init();
		}
		reg2.b.usb_iddig_irq = 0;
		writel(reg2.d32, (void __iomem *)(reg_addr + 8));
	}

	return 0;
}

static int amlogic_crg_otg_remove(struct platform_device *pdev)
{
	return 0;
}

#ifdef CONFIG_PM_RUNTIME

static int amlogic_crg_otg_runtime_suspend(struct device *dev)
{
	return 0;
}

static int amlogic_crg_otg_runtime_resume(struct device *dev)
{
	u32 ret = 0;

	return ret;
}

static const struct dev_pm_ops amlogic_crg_otg_pm_ops = {
	SET_RUNTIME_PM_OPS(amlogic_crg_otg_runtime_suspend,
			   amlogic_crg_otg_runtime_resume,
			   NULL)
};

#define DEV_PM_OPS     (&amlogic_new_otg_pm_ops)
#else
#define DEV_PM_OPS     NULL
#endif

#ifdef CONFIG_OF
static const struct of_device_id amlogic_crg_otg_id_table[] = {
	{ .compatible = "amlogic, amlogic-crg-otg" },
	{}
};
MODULE_DEVICE_TABLE(of, amlogic_crg_otg_id_table);
#endif

static struct platform_driver amlogic_crg_otg_driver = {
	.probe		= amlogic_crg_otg_probe,
	.remove		= amlogic_crg_otg_remove,
	.driver		= {
		.name	= "amlogic-crg-otg",
		.owner	= THIS_MODULE,
		.pm	= DEV_PM_OPS,
		.of_match_table = of_match_ptr(amlogic_crg_otg_id_table),
	},
};

static int __init crg_otg_init(void)
{
	platform_driver_register(&amlogic_crg_otg_driver);

	return 0;
}
late_initcall(crg_otg_init);


MODULE_ALIAS("platform: amlogic crg otg");
MODULE_AUTHOR("Amlogic Inc.");
MODULE_DESCRIPTION("amlogic crg otg driver");
MODULE_LICENSE("GPL v2");
