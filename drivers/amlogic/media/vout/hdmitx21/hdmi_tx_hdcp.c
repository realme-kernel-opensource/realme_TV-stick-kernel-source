// SPDX-License-Identifier: (GPL-2.0+ OR MIT)
/*
 * Copyright (c) 2019 Amlogic, Inc. All rights reserved.
 */

#include <linux/version.h>
#include <linux/module.h>
#include <linux/irq.h>
#include <linux/types.h>
#include <linux/input.h>
#include <linux/kernel.h>
#include <linux/kthread.h>
#include <linux/delay.h>
#include <linux/interrupt.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/device.h>
#include <linux/mm.h>
#include <linux/major.h>
#include <linux/platform_device.h>
#include <linux/mutex.h>
#include <linux/cdev.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/list.h>
#include <linux/spinlock.h>
#include <linux/spinlock_types.h>
#include <linux/extcon-provider.h>
#include <linux/amlogic/media/vout/hdmi_tx21/hdmi_info_global.h>
#include <linux/amlogic/media/vout/hdmi_tx21/hdmi_tx_module.h>
#include "hdmi_tx.h"
/*
 * hdmi_tx_hdcp.c
 * version 1.1
 */

static int hdmi21_authenticated;

u32 hdcp_getdownstream_ver(void)
{
	u32 ret = 14;

	struct hdmitx_dev *hdev = get_hdmitx21_device();

	/* if TX don't have HDCP22 key, skip RX hdcp22 ver */
	if (hdev->hwop.cntlddc(hdev, DDC_HDCP_22_LSTORE, 0) == 0)
		if (hdcp21_rd_hdcp22_ver())
			ret = 22;
		else
			ret = 14;
	else
		ret = 14;
	return ret;
}

/* Notic: the HDCP key setting has been moved to uboot
 * On MBX project, it is too late for HDCP get from
 * other devices
 */

/* verify ksv, 20 ones and 20 zeroes */
int hdcpksv_valid(u8 *dat)
{
	int i, j, one_num = 0;

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 8; j++) {
			if ((dat[i] >> j) & 0x1)
				one_num++;
		}
	}
	return one_num == 20;
}

static void _hdcp_do_work(struct work_struct *work)
{
}

void hdmitx22_hdcp_do_work(struct hdmitx_dev *hdev)
{
	_hdcp_do_work(&hdev->work_do_hdcp.work);
}

static int hdmitx_hdcp_task(void *data)
{
	static int auth_trigger;
	struct hdmitx_dev *hdev = (struct hdmitx_dev *)data;

	INIT_DELAYED_WORK(&hdev->work_do_hdcp, _hdcp_do_work);
	while (hdev->hpd_event != 0xff) {
		hdmi21_authenticated = hdev->hwop.cntlddc(hdev,
			DDC_HDCP_GET_AUTH, 0);
		hdmitx21_hdcp_status(hdmi21_authenticated);
		if (auth_trigger != hdmi21_authenticated) {
			auth_trigger = hdmi21_authenticated;
			pr_info("hdcptx: %d  auth: %d\n", hdev->hdcp_mode,
				auth_trigger);
		}
		msleep_interruptible(200);
	}

	return 0;
}

int hdmitx21_hdcp_init(void)
{
	struct hdmitx_dev *hdev = get_hdmitx21_device();

	pr_info("%s\n", __func__);
	if (!hdev->hdtx_dev) {
		pr_info("exit for null device of hdmitx!\n");
		return -ENODEV;
	}

	hdev->task_hdcp = kthread_run(hdmitx_hdcp_task,	(void *)hdev,
				      "kthread_hdcp");

	return 0;
}

void __exit hdmitx21_hdcp_exit(void)
{
	struct hdmitx_dev *hdev = get_hdmitx21_device();

	if (hdev)
		cancel_delayed_work_sync(&hdev->work_do_hdcp);
}

MODULE_PARM_DESC(hdmi21_authenticated, "\n hdmi21_authenticated\n");
module_param(hdmi21_authenticated, int, 0444);
