/* SPDX-License-Identifier: GPL-2.0+ OR MIT */
/*
 * Meson-G12A clock tree IDs
 *
 * Copyright (c) 2018 Amlogic, Inc. All rights reserved.
 */

#ifndef __G12A_CLKC_H
#define __G12A_CLKC_H

#define CLKID_SYS_PLL				0
#define CLKID_FIXED_PLL				1
#define CLKID_FCLK_DIV2				2
#define CLKID_FCLK_DIV3				3
#define CLKID_FCLK_DIV4				4
#define CLKID_FCLK_DIV5				5
#define CLKID_FCLK_DIV7				6
#define CLKID_GP0_PLL				7
#define CLKID_CLK81				10
#define CLKID_MPLL0				11
#define CLKID_MPLL1				12
#define CLKID_MPLL2				13
#define CLKID_MPLL3				14
#define CLKID_DDR				15
#define CLKID_DOS				16
#define CLKID_AUDIO_LOCKER			17
#define CLKID_MIPI_DSI_HOST			18
#define CLKID_ETH_PHY				19
#define CLKID_ISA				20
#define CLKID_PL301				21
#define CLKID_PERIPHS				22
#define CLKID_SPICC0				23
#define CLKID_I2C				24
#define CLKID_SANA				25
#define CLKID_SD				26
#define CLKID_RNG0				27
#define CLKID_UART0				28
#define CLKID_SPICC1				29
#define CLKID_HIU_IFACE				30
#define CLKID_MIPI_DSI_PHY			31
#define CLKID_ASSIST_MISC			32
#define CLKID_SD_EMMC_A				33
#define CLKID_SD_EMMC_B				34
#define CLKID_SD_EMMC_C				35
#define CLKID_AUDIO_CODEC			36
#define CLKID_AUDIO				37
#define CLKID_ETH				38
#define CLKID_DEMUX				39
#define CLKID_AUDIO_IFIFO			40
#define CLKID_ADC				41
#define CLKID_UART1				42
#define CLKID_G2D				43
#define CLKID_RESET				44
#define CLKID_PCIE_COMB				45
#define CLKID_PARSER				46
#define CLKID_USB				47
#define CLKID_PCIE_PHY				48
#define CLKID_AHB_ARB0				49
#define CLKID_AHB_DATA_BUS			50
#define CLKID_AHB_CTRL_BUS			51
#define CLKID_HTX_HDCP22			52
#define CLKID_HTX_PCLK				53
#define CLKID_BT656				54
#define CLKID_USB1_DDR_BRIDGE			55
#define CLKID_MMC_PCLK				56
#define CLKID_UART2				57
#define CLKID_VPU_INTR				58
#define CLKID_GIC				59
#define CLKID_SD_EMMC_A_CLK0			60
#define CLKID_SD_EMMC_B_CLK0			61
#define CLKID_SD_EMMC_C_CLK0			62
#define CLKID_SD_EMMC_A_CLK0_SEL		63
#define CLKID_SD_EMMC_A_CLK0_DIV		64
#define CLKID_SD_EMMC_B_CLK0_SEL		65
#define CLKID_SD_EMMC_B_CLK0_DIV		66
#define CLKID_SD_EMMC_C_CLK0_SEL		67
#define CLKID_SD_EMMC_C_CLK0_DIV		68
#define CLKID_HIFI_PLL				74
#define CLKID_VCLK2_VENCI0			80
#define CLKID_VCLK2_VENCI1			81
#define CLKID_VCLK2_VENCP0			82
#define CLKID_VCLK2_VENCP1			83
#define CLKID_VCLK2_VENCT0			84
#define CLKID_VCLK2_VENCT1			85
#define CLKID_VCLK2_OTHER			86
#define CLKID_VCLK2_ENCI			87
#define CLKID_VCLK2_ENCP			88
#define CLKID_DAC_CLK				89
#define CLKID_AOCLK				90
#define CLKID_IEC958				91
#define CLKID_ENC480P				92
#define CLKID_RNG1				93
#define CLKID_VCLK2_ENCT			94
#define CLKID_VCLK2_ENCL			95
#define CLKID_VCLK2_VENCLMMC			96
#define CLKID_VCLK2_VENCL			97
#define CLKID_VCLK2_OTHER1			98
#define CLKID_FCLK_DIV2P5			99
#define CLKID_DMA				105
#define CLKID_EFUSE				106
#define CLKID_ROM_BOOT				107
#define CLKID_RESET_SEC				108
#define CLKID_SEC_AHB_APB3			109
#define CLKID_VPU_0_SEL				110
#define CLKID_VPU_0				112
#define CLKID_VPU_1_SEL				113
#define CLKID_VPU_1				115
#define CLKID_VPU				116
#define CLKID_VAPB_0_SEL			117
#define CLKID_VAPB_0				119
#define CLKID_VAPB_1_SEL			120
#define CLKID_VAPB_1				122
#define CLKID_VAPB_SEL				123
#define CLKID_VAPB				124
#define CLKID_HDMI_PLL				128
#define CLKID_VID_PLL				129
#define CLKID_VCLK				138
#define CLKID_VCLK2				139
#define CLKID_VCLK_DIV1				148
#define CLKID_VCLK_DIV2				149
#define CLKID_VCLK_DIV4				150
#define CLKID_VCLK_DIV6				151
#define CLKID_VCLK_DIV12			152
#define CLKID_VCLK2_DIV1			153
#define CLKID_VCLK2_DIV2			154
#define CLKID_VCLK2_DIV4			155
#define CLKID_VCLK2_DIV6			156
#define CLKID_VCLK2_DIV12			157
#define CLKID_CTS_ENCI				162
#define CLKID_CTS_ENCP				163
#define CLKID_CTS_VDAC				164
#define CLKID_HDMI_TX				165
#define CLKID_HDMI				168
#define CLKID_MALI_0_SEL			169
#define CLKID_MALI_0				171
#define CLKID_MALI_1_SEL			172
#define CLKID_MALI_1				174
#define CLKID_MALI				175
#define CLKID_MPLL_50M				177
#define CLKID_CPU_CLK_DYN                       186
#define CLKID_CPU_CLK				187
#define CLKID_PCIE_PLL				201
#define CLKID_VDEC_1				204
#define CLKID_VDEC_HEVC				207
#define CLKID_VDEC_HEVCF			210
#define CLKID_TS				212
#define CLKID_CPUB_CLK				224
#define CLKID_GP1_PLL				243
#define CLKID_DSU_CLK_FINAL			251
#define CLKID_DSU_CLK				252
#define CLKID_CPU1_CLK				253
#define CLKID_CPU2_CLK				254
#define CLKID_CPU3_CLK				255
#define CLKID_PCIE_HCSL				256
/* Media clocks */
#define MEDIA_BASE				(256 + 1)
#define CLKID_DSI_MEAS_MUX			(MEDIA_BASE + 0)
#define CLKID_DSI_MEAS_DIV			(MEDIA_BASE + 1)
#define CLKID_DSI_MEAS				(MEDIA_BASE + 2)
#define CLKID_VDEC_P1_MUX			(MEDIA_BASE + 3)
#define CLKID_VDEC_P1_DIV			(MEDIA_BASE + 4)
#define CLKID_VDEC_P1				(MEDIA_BASE + 5)
#define CLKID_VDEC_MUX				(MEDIA_BASE + 6)
#define CLKID_HCODEC_P0_MUX			(MEDIA_BASE + 7)
#define CLKID_HCODEC_P0_DIV			(MEDIA_BASE + 8)
#define CLKID_HCODEC_P0				(MEDIA_BASE + 9)
#define CLKID_HCODEC_P1_MUX			(MEDIA_BASE + 10)
#define CLKID_HCODEC_P1_DIV			(MEDIA_BASE + 11)
#define CLKID_HCODEC_P1				(MEDIA_BASE + 12)
#define CLKID_HCODEC_MUX			(MEDIA_BASE + 13)
#define CLKID_HEVC_P1_MUX			(MEDIA_BASE + 14)
#define CLKID_HEVC_P1_DIV			(MEDIA_BASE + 15)
#define CLKID_HEVC_P1				(MEDIA_BASE + 16)
#define CLKID_HEVC_MUX				(MEDIA_BASE + 17)
#define CLKID_HEVCF_P1_MUX			(MEDIA_BASE + 18)
#define CLKID_HEVCF_P1_DIV			(MEDIA_BASE + 19)
#define CLKID_HEVCF_P1				(MEDIA_BASE + 20)
#define CLKID_HEVCF_MUX				(MEDIA_BASE + 21)
#define CLKID_VPU_CLKB_TMP_MUX			(MEDIA_BASE + 22)
#define CLKID_VPU_CLKB_TMP_DIV			(MEDIA_BASE + 23)
#define CLKID_VPU_CLKB_TMP			(MEDIA_BASE + 24)
#define CLKID_VPU_CLKB_DIV			(MEDIA_BASE + 25)
#define CLKID_VPU_CLKB				(MEDIA_BASE + 26)
#define CLKID_VPU_CLKC_P0_MUX			(MEDIA_BASE + 27)
#define CLKID_VPU_CLKC_P0_DIV			(MEDIA_BASE + 28)
#define CLKID_VPU_CLKC_P0			(MEDIA_BASE + 29)
#define CLKID_VPU_CLKC_P1_MUX			(MEDIA_BASE + 30)
#define CLKID_VPU_CLKC_P1_DIV			(MEDIA_BASE + 31)
#define CLKID_VPU_CLKC_P1			(MEDIA_BASE + 32)
#define CLKID_VPU_CLKC_MUX			(MEDIA_BASE + 33)
#define CLKID_VDIN_MEAS_MUX			(MEDIA_BASE + 34)
#define CLKID_VDIN_MEAS_DIV			(MEDIA_BASE + 35)
#define CLKID_VDIN_MEAS_GATE			(MEDIA_BASE + 36)
#define CLKID_WAVE_A_SEL			(MEDIA_BASE + 37)
#define CLKID_WAVE_A_DIV			(MEDIA_BASE + 38)
#define CLKID_WAVE_A_CLK			(MEDIA_BASE + 39)
#define CLKID_WAVE_B_SEL			(MEDIA_BASE + 40)
#define CLKID_WAVE_B_DIV			(MEDIA_BASE + 41)
#define CLKID_WAVE_B_CLK			(MEDIA_BASE + 42)
#define CLKID_WAVE_C_SEL			(MEDIA_BASE + 43)
#define CLKID_WAVE_C_DIV			(MEDIA_BASE + 44)
#define CLKID_WAVE_C_CLK			(MEDIA_BASE + 45)

/*misc clocks*/
#define MISC_BASE				(MEDIA_BASE + 46)
#define CLKID_SPICC0_MUX			(MISC_BASE + 0)
#define CLKID_SPICC0_DIV			(MISC_BASE + 1)
#define CLKID_SPICC0_GATE			(MISC_BASE + 2)
#define CLKID_SPICC1_MUX			(MISC_BASE + 3)
#define CLKID_SPICC1_DIV			(MISC_BASE + 4)
#define CLKID_SPICC1_GATE			(MISC_BASE + 5)
#define CLKID_BT656_MUX				(MISC_BASE + 6)
#define CLKID_BT656_DIV				(MISC_BASE + 7)
#define CLKID_BT656_GATE			(MISC_BASE + 8)

#define CLKID_END				(MISC_BASE + 9)

#endif /* __G12A_CLKC_H */
