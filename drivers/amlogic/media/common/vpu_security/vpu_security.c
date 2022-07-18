// SPDX-License-Identifier: (GPL-2.0+ OR MIT)
/*
 * Copyright (c) 2019 Amlogic, Inc. All rights reserved.
 */

#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/spinlock.h>
#include <linux/interrupt.h>
#include <linux/fs.h>
#include <linux/dma-mapping.h>

#include <linux/string.h>
#include <linux/io.h>
#include <linux/mm.h>
#include <linux/err.h>
#include <linux/mutex.h>
#include <linux/platform_device.h>
#include <linux/ctype.h>
#include <linux/sched.h>
#include <linux/poll.h>
#include <linux/clk.h>
#include <linux/kthread.h>
#include <linux/slab.h>
#include <linux/of.h>
#include <linux/of_fdt.h>
#include <linux/amlogic/iomap.h>
#include <linux/io.h>
#include <linux/delay.h>
#include <linux/arm-smccc.h>

#include <linux/amlogic/media/registers/regs/viu_regs.h>
#include <linux/amlogic/media/vpu_secure/vpu_secure.h>
#include <linux/amlogic/media/video_sink/video_signal_notify.h>
#include <linux/amlogic/media/registers/cpu_version.h>
#include <linux/amlogic/media/registers/regs/vpp_regs.h>
#include <linux/amlogic/media/utils/vdec_reg.h>

#include "vpu_security.h"

#define DEVICE_NAME "vpu_security"
#define CLASS_NAME  "vpu_security"

static struct vpu_security_device_info vpu_security_info;
static struct sec_dev_data_s sec_meson_dev;
static u32 secure_cfg;
static u32 log_level;

static struct vpu_sec_reg_s reg_v1[] = {
	{VIU_DATA_SEC, 1, 0, 1}, /* 00. OSD1 */
	{VIU_DATA_SEC, 1, 1, 1}, /* 01. OSD2 */
	{VIU_DATA_SEC, 1, 2, 1}, /* 02. VD1 */
	{VIU_DATA_SEC, 1, 3, 1}, /* 03. VD2 */
	{VIU_DATA_SEC, 1, 4, 1}, /* 04. OSD3 */
	{VIU_DATA_SEC, 1, 5, 1}, /* 05. VD AFBC, not used */
	{VIU_DATA_SEC, 1, 6, 1}, /* 06. DV */
	{VIU_DATA_SEC, 1, 7, 1}, /* 07. OSD AFBC */
	{VIU_DATA_SEC, 1, 8, 1}  /* 08. VPP_TOP */
};

static struct vpu_sec_reg_s reg_v2[] = {
	{MALI_AFBCD_TOP_CTRL,  1, 17, 1}, /* 00. OSD1 */
	{MALI_AFBCD_TOP_CTRL,  1, 22, 1}, /* 01. OSD2 */
	{VPP_VD1_DSC_CTRL,     1, 6,  1}, /* 02. VD1 */
	{VPP_VD2_DSC_CTRL,     1, 6,  1}, /* 03. VD2 */
	{MALI_AFBCD1_TOP_CTRL, 1, 22, 1}, /* 04. OSD3 */
	{0,                    1, 0,  1}, /* 05. VD AFBC, not used */
	{VPP_VD1_DSC_CTRL,     1, 7,  1}, /* 06. DV */
	{MALI_AFBCD_TOP_CTRL,  1, 18, 1}, /* 07. OSD AFBC */
	{VIU_FRM_CTRL,	       1, 26, 1}, /* 08. VPP_TOP */
	{MALI_AFBCD2_TOP_CTRL, 1, 22, 1}, /* 09. OSD4 */
	{VPP_VD3_DSC_CTRL,     1, 6,  1}, /* 10. VD3 */
	{VIU1_FRM_CTRL,        1, 26, 1}, /* 11. VPP_TOP1 */
	{VIU2_FRM_CTRL,        1, 26, 1}  /* 12. VPP_TOP2 */
};

static struct sec_dev_data_s vpu_security_sc2 = {
	.version = VPU_SEC_V1,
};

static struct sec_dev_data_s vpu_security_s4 = {
	.version = VPU_SEC_V1,
};

static struct sec_dev_data_s vpu_security_t7 = {
	.version = VPU_SEC_V2,
};

static const struct of_device_id vpu_security_dt_match[] = {
	{
		.compatible = "amlogic, meson-sc2, vpu_security",
		.data = &vpu_security_sc2,
	},
	{
		.compatible = "amlogic, meson-s4, vpu_security",
		.data = &vpu_security_s4,
	},
	{
		.compatible = "amlogic, meson-t7, vpu_security",
		.data = &vpu_security_t7,
	},
	{}
};

static bool is_vpu_secure_support(void)
{
	return sec_meson_dev.version ? true : false;
}

static u32 vpu_secure_version(void)
{
	return sec_meson_dev.version;
}

bool get_secure_state(enum module_port_e port)
{
	bool secure_enable = false;

	switch (port) {
	case VD1_OUT:
		if (secure_cfg & VD1_INPUT_SECURE)
			secure_enable = true;
		break;
	case VD2_OUT:
		if (secure_cfg & VD2_INPUT_SECURE)
			secure_enable = true;
		break;
	case VD3_OUT:
		if (secure_cfg & VD3_INPUT_SECURE)
			secure_enable = true;
		break;
	case OSD1_VPP_OUT:
		if ((secure_cfg & OSD1_INPUT_SECURE) ||
		    (secure_cfg & OSD2_INPUT_SECURE) ||
		    (secure_cfg & OSD3_INPUT_SECURE) ||
		    (secure_cfg & OSD4_INPUT_SECURE))
			secure_enable = true;
		break;
	case OSD2_VPP_OUT:
		break;
	case POST_BLEND_OUT:
		if (secure_cfg)
			secure_enable = true;
		break;
	default:
		break;
	}
	return secure_enable;
}

static void secure_reg_update(struct vpu_secure_ins *ins,
			      struct vpu_sec_bit_s *change,
			      u32 vpp_index)
{
	enum vpu_security_version_e version;
	int i, en = 0, reg_val = 0;

	if (!is_vpu_secure_support())
		return;

	if (!ins->reg_wr_op[vpp_index]) {
		pr_err("%s, reg_wr_op is NULL\n", __func__);
		return;
	}

	version = vpu_secure_version();
	if (version == VPU_SEC_V1) {
		/* write all bits together */
		ins->reg_wr_op[vpp_index](reg_v1[0].reg,
					  change->current_val,
					  0, ARRAY_SIZE(reg_v1));
	} else if (version == VPU_SEC_V2) {
		/* work through the array and write bit(s) */
		for (i = 0; i < ARRAY_SIZE(reg_v2); i++) {
			if (BIT(i) & change->bit_changed) {
				en = BIT(i) & change->current_val;
				reg_val = en ? reg_v2[i].en : (!reg_v2[i].en);
				if (!reg_v2[i].reg)
					continue;
				ins->reg_wr_op[vpp_index](reg_v2[i].reg,
							  reg_val,
							  reg_v2[i].start,
							  reg_v2[i].len);
			}
		}
	} else {
		pr_err("%s, wrong version\n", __func__);
		return;
	}
}

u32 set_vpu_module_security(struct vpu_secure_ins *ins,
			    enum secure_module_e module,
			    u32 secure_src, u32 vpp_index)
{
	static u32 osd_secure, video_secure;
	static bool osd_secure_en[VPP_TOP_MAX] = {0,};
	static bool video_secure_en[VPP_TOP_MAX] = {0,};
	static int value_save;
	u32 value = 0;
	int secure_update = 0;
	struct vd_secure_info_s vd_secure[MAX_SECURE_OUT];
	bool vpp_top_en = 0;
	struct vpu_sec_bit_s change;

	if (is_vpu_secure_support()) {
		switch (module) {
		case OSD_MODULE:
			if ((secure_src & OSD1_INPUT_SECURE) ||
			    (secure_src & OSD2_INPUT_SECURE) ||
			    (secure_src & OSD3_INPUT_SECURE) ||
			    (secure_src & OSD4_INPUT_SECURE) ||
			    (secure_src & MALI_AFBCD_SECURE)) {
				/* for T7 revA */
				if (is_meson_t7_cpu() && is_meson_rev_a() &&
				    (secure_src & (OSD1_INPUT_SECURE |
						   OSD2_INPUT_SECURE)))
					secure_src |= OSD4_INPUT_SECURE;

				/* OSD module secure */
				osd_secure = secure_src;
				value = osd_secure | video_secure;
				ins->secure_enable = 1;
				ins->secure_status = value;
				osd_secure_en[vpp_index] = 1;
			} else {
				/* OSD none secure */
				osd_secure = secure_src;
				value = osd_secure | video_secure;
				ins->secure_enable = 0;
				ins->secure_status = value;
				osd_secure_en[vpp_index] = 0;
			}
			break;
		case VIDEO_MODULE:
			if ((secure_src & DV_INPUT_SECURE) ||
			    (secure_src & AFBCD_INPUT_SECURE) ||
			    (secure_src & VD3_INPUT_SECURE) ||
			    (secure_src & VD2_INPUT_SECURE) ||
			    (secure_src & VD1_INPUT_SECURE)) {
				/* video module secure */
				video_secure = secure_src;
				value = video_secure | osd_secure;
				ins->secure_enable = 1;
				ins->secure_status = value;
				video_secure_en[vpp_index] = 1;
			} else {
				/* video module secure */
				video_secure = secure_src;
				value = video_secure | osd_secure;
				ins->secure_enable = 0;
				ins->secure_status = value;
				video_secure_en[vpp_index] = 0;
			}
			break;
		case DI_MODULE:
			break;
		case VDIN_MODULE:
			break;
		default:
			break;
		}

		vpp_top_en = osd_secure_en[vpp_index] ||
			     video_secure_en[vpp_index];
		if (vpp_index == 0) {
			if (vpp_top_en)
				value |= VPP_OUTPUT_SECURE;
			else
				value &= ~VPP_OUTPUT_SECURE;
		}
		if (vpp_index == 1) {
			if (vpp_top_en)
				value |= VPP1_OUTPUT_SECURE;
			else
				value &= ~VPP1_OUTPUT_SECURE;
		}
		if (vpp_index == 2) {
			if (vpp_top_en)
				value |= VPP2_OUTPUT_SECURE;
			else
				value &= ~VPP2_OUTPUT_SECURE;
		}

		if (module == OSD_MODULE ||
			module == VIDEO_MODULE ||
			module == DI_MODULE) {
			if (value_save != value) {
				/* record changed bit and current val */
				change.bit_changed = value ^ value_save;
				change.current_val = value;
				secure_reg_update(ins, &change, vpp_index);
				secure_update = 1;
			}
			value_save = value;
		}
	}

	if (log_level >= 2)
		pr_info("vpu secure bit 0x%x\n", value);

	secure_cfg = value;
	if (secure_update) {
		int i;

		for (i = 0; i < MAX_SECURE_OUT; i++) {
			vd_secure[i].secure_type = i;
			vd_secure[i].secure_enable = get_secure_state(i);
		}
		vd_signal_notifier_call_chain
			(VIDEO_SECURE_TYPE_CHANGED,
			&vd_secure[0]);
	}
	return value;
}

int secure_register(enum secure_module_e module,
		    int config_delay,
		    void **reg_op,
		    void *cb)
{
	struct vpu_security_device_info *info = &vpu_security_info;
	struct vpu_secure_ins *ins = NULL;
	struct mutex *lock = NULL;
	int i;

	if (!is_vpu_secure_support())
		return -1;
	if (!info->probed)
		return -1;
	if (module >= MODULE_NUM) {
		pr_info("%s failed, module = %d\n", __func__, module);
		return -1;
	}
	ins = &info->ins[module];
	if (!ins->registered) {
		lock = &info->ins[module].secure_lock;
		mutex_lock(lock);
		ins->registered = 1;
		ins->config_delay = config_delay;
		for (i = 0; i < VPP_TOP_MAX; i++)
			ins->reg_wr_op[i] = reg_op[i];
		ins->secure_cb = cb;
		mutex_unlock(lock);
	}
	pr_info("%s module=%d ok\n", __func__, module);
	return 0;
}

int secure_unregister(enum secure_module_e module)
{
	struct vpu_security_device_info *info = &vpu_security_info;
	struct vpu_secure_ins *ins = NULL;
	struct mutex *lock = NULL;
	int i;

	if (!is_vpu_secure_support())
		return -1;
	if (!info->probed)
		return -1;
	if (module >= MODULE_NUM)
		return -1;
	ins = &info->ins[module];
	if (ins->registered) {
		lock = &info->ins[module].secure_lock;
		mutex_lock(lock);
		ins->registered = 0;
		ins->config_delay = 0;
		for (i = 0; i < VPP_TOP_MAX; i++)
			ins->reg_wr_op[i] = NULL;
		ins->secure_cb = NULL;
		mutex_unlock(lock);
	}
	return 0;
}

int secure_config(enum secure_module_e module, int secure_src, u32 vpp_index)
{
	struct vpu_security_device_info *info = &vpu_security_info;
	struct vpu_secure_ins *ins = NULL;
	u32 reg_value = -1;

	if (module >= MODULE_NUM)
		return -1;
	ins = &info->ins[module];
	if (ins->registered)
		reg_value = set_vpu_module_security(ins, module, secure_src,
						    vpp_index);
	return 0;
}

static ssize_t vpu_security_info_show(struct class *cla,
				      struct class_attribute *attr, char *buf)
{
	struct vpu_security_device_info *info = &vpu_security_info;

	return snprintf(buf, PAGE_SIZE, "vpu_security mismatch cnt:%d\n",
		info->mismatch_cnt);
}

static ssize_t log_level_show(struct class *cla,
			      struct class_attribute *attr, char *buf)
{
	return snprintf(buf, 40, "%d\n", log_level);
}

static ssize_t log_level_store(struct class *cla,
			       struct class_attribute *attr,
			       const char *buf, size_t count)
{
	int res = 0;
	int ret = 0;

	ret = kstrtoint(buf, 0, &res);
	pr_info("log_level: %d->%d\n", log_level, res);
	log_level = res;
	return count;
}

static struct class_attribute vpu_security_attrs[] = {
	__ATTR(security_info, 0444,
	       vpu_security_info_show, NULL),
	__ATTR(log_level, 0644,
	       log_level_show, log_level_store),
};

irqreturn_t vpu_security_isr(int irq, void *dev_id)
{
	struct vpu_security_device_info *info = &vpu_security_info;
	struct vpu_secure_ins *ins = NULL;
	int i;
	enum vpu_security_version_e version;
	u32 error_bit = 0;

	version = vpu_secure_version();

	info->mismatch_cnt++;
	if (version == VPU_SEC_V1) {
		if (log_level >= 1)
			pr_err("sec: mismatch(%d)\n", info->mismatch_cnt);
	} else if (version == VPU_SEC_V2) {
		error_bit = READ_VCBUS_REG(VPU_SEC_INT_STAT);
		for (i = 0; i < VPP_TOP_MAX; i++) {
			if (error_bit & BIT(i)) {
				if (log_level >= 1)
					pr_err("sec: VPP_TOP%x mismatch\n", i);
				/* clear interrupt bit */
				WRITE_VCBUS_REG_BITS(VPU_SEC_INT_STAT, 1, i, 1);
			}
		}
	}

	for (i = 0; i < MODULE_NUM; i++) {
		ins = &info->ins[i];
		if (ins->registered) {
			if (ins->secure_cb)
				ins->secure_cb(ins->secure_status);
		}
	}
	return IRQ_HANDLED;
}

static int vpu_security_probe(struct platform_device *pdev)
{
	int i, ret = 0, err = 0;
	int int_vpu_security;
	struct vpu_security_device_info *info = &vpu_security_info;

	if (pdev->dev.of_node) {
		const struct of_device_id *match;
		struct sec_dev_data_s *sec_meson;
		struct device_node	*of_node = pdev->dev.of_node;

		match = of_match_node(vpu_security_dt_match, of_node);
		if (match) {
			sec_meson =
				(struct sec_dev_data_s *)match->data;
			if (sec_meson)
				memcpy(&sec_meson_dev, sec_meson,
				       sizeof(struct sec_dev_data_s));
			else
				err = 1;

		} else {
			err = 2;
		}
	} else {
		err = 3;
	}
	if (err) {
		pr_err("dev %s NOT match, err=%d\n", __func__, err);
		return -ENODEV;
	}

	info->pdev = pdev;
	int_vpu_security = platform_get_irq_byname(pdev, "vpu_security");
	if (request_irq(int_vpu_security, &vpu_security_isr,
			IRQF_SHARED, "vpu_security", (void *)"vpu_security")) {
		dev_err(&pdev->dev, "can't request irq for vpu_security\n");
		return -ENODEV;
	}

	info->clsp = class_create(THIS_MODULE,
				  CLASS_NAME);
	if (IS_ERR(info->clsp)) {
		ret = PTR_ERR(info->clsp);
		pr_err("fail to create class\n");
		goto fail_create_class;
	}
	for (i = 0; i < ARRAY_SIZE(vpu_security_attrs); i++) {
		if (class_create_file
			(info->clsp,
			&vpu_security_attrs[i]) < 0) {
			pr_err("fail to class_create_file\n");
			goto fail_class_create_file;
		}
	}
	for (i = 0; i < MODULE_NUM; i++)
		mutex_init(&info->ins[i].secure_lock);

	info->probed = 1;
	pr_info("%s ok.\n", __func__);
	return 0;
fail_class_create_file:
	for (i = 0; i < ARRAY_SIZE(vpu_security_attrs); i++)
		class_remove_file
			(info->clsp, &vpu_security_attrs[i]);
	class_destroy(info->clsp);
	info->clsp = NULL;
fail_create_class:
	return ret;
}

static int vpu_security_remove(struct platform_device *pdev)
{
	int i;
	struct vpu_security_device_info *info = &vpu_security_info;

	for (i = 0; i < ARRAY_SIZE(vpu_security_attrs); i++)
		class_remove_file
			(info->clsp, &vpu_security_attrs[i]);
	class_destroy(info->clsp);
	info->clsp = NULL;
	info->probed = 0;
	return 0;
}

static struct platform_driver vpu_security_driver = {
	.probe = vpu_security_probe,
	.remove = vpu_security_remove,
	.driver = {
		.name = "amlogic_vpu_security",
		.of_match_table = vpu_security_dt_match,
	},
};

int __init vpu_security_init(void)
{
	int r;

	r = platform_driver_register(&vpu_security_driver);
	if (r) {
		pr_err("Unable to register vpu_security driver\n");
		return r;
	}
	return 0;
}

void __exit vpu_security_exit(void)
{
	platform_driver_unregister(&vpu_security_driver);
}

//MODULE_DESCRIPTION("AMLOGIC VPU SECURITY driver");
//MODULE_LICENSE("GPL");
//MODULE_AUTHOR("PengCheng.Chen <pengcheng.chen@amlogic.com>");
