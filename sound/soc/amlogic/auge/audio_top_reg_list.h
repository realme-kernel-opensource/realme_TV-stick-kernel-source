/* SPDX-License-Identifier: (GPL-2.0+ OR MIT) */
/*
 * Copyright (c) 2019 Amlogic, Inc. All rights reserved.
 */

#ifndef __AML_AUDIO_TOP_REG_H_
#define __AML_AUDIO_TOP_REG_H_

#include "regs.h"

static const struct register_table top_register_table[] = {
{"AUDIO_CLK_GATE_EN0        ",  0x00},
{"AUDIO_CLK_GATE_EN1        ",  0x01},
{"AUDIO_MCLK_A_CTRL         ",  0x02},
{"AUDIO_MCLK_B_CTRL         ",  0x03},
{"AUDIO_MCLK_C_CTRL         ",  0x04},
{"AUDIO_MCLK_D_CTRL         ",  0x05},
{"AUDIO_MCLK_E_CTRL         ",  0x06},
{"AUDIO_MCLK_F_CTRL         ",  0x07},
{"AUDIO_PAD_CTRL0           ",  0x08},
{"AUDIO_PAD_CTRL1           ",  0x09},
{"AUDIO_SW_RESET0           ",  0x0a},
{"AUDIO_SW_RESET1           ",  0x0b},
{"AUDIO_CLK81_CTRL          ",  0x0c},
{"AUDIO_CLK81_EN            ",  0x0d},
{"AUDIO_RESV_ADDR_0xe       ",  0x0e},
{"AUDIO_RESV_ADDR_0xf       ",  0x0f},
{"AUDIO_MST_A_SCLK_CTRL0    ",  0x10},
{"AUDIO_MST_A_SCLK_CTRL1    ",  0x11},
{"AUDIO_MST_B_SCLK_CTRL0    ",  0x12},
{"AUDIO_MST_B_SCLK_CTRL1    ",  0x13},
{"AUDIO_MST_C_SCLK_CTRL0    ",  0x14},
{"AUDIO_MST_C_SCLK_CTRL1    ",  0x15},
{"AUDIO_MST_D_SCLK_CTRL0    ",  0x16},
{"AUDIO_MST_D_SCLK_CTRL1    ",  0x17},
{"AUDIO_MST_E_SCLK_CTRL0    ",  0x18},
{"AUDIO_MST_E_SCLK_CTRL1    ",  0x19},
{"AUDIO_MST_F_SCLK_CTRL0    ",  0x1a},
{"AUDIO_MST_F_SCLK_CTRL1    ",  0x1b},
{"AUDIO_RESV_ADDR_0x1c      ",  0x1c},
{"AUDIO_RESV_ADDR_0x1d      ",  0x1d},
{"AUDIO_RESV_ADDR_0x1e      ",  0x1e},
{"AUDIO_RESV_ADDR_0x1f      ",  0x1f},
{"AUDIO_CLK_TDMIN_A_CTRL    ",  0x20},
{"AUDIO_CLK_TDMIN_B_CTRL    ",  0x21},
{"AUDIO_CLK_TDMIN_C_CTRL    ",  0x22},
{"AUDIO_CLK_TDMIN_LB_CTRL   ",  0x23},
{"AUDIO_CLK_TDMOUT_A_CTRL   ",  0x24},
{"AUDIO_CLK_TDMOUT_B_CTRL   ",  0x25},
{"AUDIO_CLK_TDMOUT_C_CTRL   ",  0x26},
{"AUDIO_CLK_SPDIFIN_CTRL    ",  0x27},
{"AUDIO_CLK_SPDIFOUT_CTRL   ",  0x28},
{"AUDIO_CLK_RESAMPLEA_CTRL  ",  0x29},
{"AUDIO_CLK_LOCKER_CTRL     ",  0x2a},
{"AUDIO_CLK_PDMIN_CTRL0     ",  0x2b},
{"AUDIO_CLK_PDMIN_CTRL1     ",  0x2c},
{"AUDIO_CLK_SPDIFOUT_B_CTRL ",  0x2d},
{"AUDIO_CLK_RESAMPLEB_CTRL  ",  0x2e},
{"AUDIO_CLK_SPDIFIN_LB_CTRL ",  0x2f},
{"AUDIO_CLK_EQDRC_CTRL0     ",  0x30},
{"AUDIO_VAD_CLK_CTRL        ",  0x31},
{"AUDIO_RESV_ADDR_0x32      ",  0x32},
{"AUDIO_RESV_ADDR_0x33      ",  0x33},
{"AUDIO_RESV_ADDR_0x34      ",  0x34},
{"AUDIO_RESV_ADDR_0x35      ",  0x35},
{"AUDIO_RESV_ADDR_0x36      ",  0x36},
{"AUDIO_RESV_ADDR_0x37      ",  0x37},
{"AUDIO_RESV_ADDR_0x38      ",  0x38},
{"AUDIO_RESV_ADDR_0x39      ",  0x39},
{"AUDIO_RESV_ADDR_0x3a      ",  0x3a},
{"AUDIO_RESV_ADDR_0x3b      ",  0x3b},
{"AUDIO_RESV_ADDR_0x3c      ",  0x3c},
{"AUDIO_RESV_ADDR_0x3d      ",  0x3d},
{"AUDIO_RESV_ADDR_0x3e      ",  0x3e},
{"AUDIO_RESV_ADDR_0x3f      ",  0x3f},
{"AUDIO_TODDR_A_CTRL0       ",  0x40},
{"AUDIO_TODDR_A_CTRL1       ",  0x41},
{"AUDIO_TODDR_A_START_ADDR  ",  0x42},
{"AUDIO_TODDR_A_FINISH_ADDR ",  0x43},
{"AUDIO_TODDR_A_INT_ADDR    ",  0x44},
{"AUDIO_TODDR_A_STATUS1     ",  0x45},
{"AUDIO_TODDR_A_STATUS2     ",  0x46},
{"AUDIO_TODDR_A_START_ADDRB ",  0x47},
{"AUDIO_TODDR_A_FINISH_ADDRB",  0x48},
{"AUDIO_TODDR_A_INIT_ADDR   ",  0x49},
{"AUDIO_TODDR_A_CTRL2       ",  0x4a},
{"AUDIO_RESV_ADDR_0x4b      ",  0x4b},
{"AUDIO_RESV_ADDR_0x4c      ",  0x4c},
{"AUDIO_RESV_ADDR_0x4d      ",  0x4d},
{"AUDIO_RESV_ADDR_0x4e      ",  0x4e},
{"AUDIO_RESV_ADDR_0x4f      ",  0x4f},
{"AUDIO_TODDR_B_CTRL0       ",  0x50},
{"AUDIO_TODDR_B_CTRL1       ",  0x51},
{"AUDIO_TODDR_B_START_ADDR  ",  0x52},
{"AUDIO_TODDR_B_FINISH_ADDR ",  0x53},
{"AUDIO_TODDR_B_INT_ADDR    ",  0x54},
{"AUDIO_TODDR_B_STATUS1     ",  0x55},
{"AUDIO_TODDR_B_STATUS2     ",  0x56},
{"AUDIO_TODDR_B_START_ADDRB ",  0x57},
{"AUDIO_TODDR_B_FINISH_ADDRB",  0x58},
{"AUDIO_TODDR_B_INIT_ADDR   ",  0x59},
{"AUDIO_TODDR_B_CTRL2       ",  0x5a},
{"AUDIO_RESV_ADDR_0x5b      ",  0x5b},
{"AUDIO_RESV_ADDR_0x5c      ",  0x5c},
{"AUDIO_RESV_ADDR_0x5d      ",  0x5d},
{"AUDIO_RESV_ADDR_0x5e      ",  0x5e},
{"AUDIO_RESV_ADDR_0x5f      ",  0x5f},
{"AUDIO_TODDR_C_CTRL0       ",  0x60},
{"AUDIO_TODDR_C_CTRL1       ",  0x61},
{"AUDIO_TODDR_C_START_ADDR  ",  0x62},
{"AUDIO_TODDR_C_FINISH_ADDR ",  0x63},
{"AUDIO_TODDR_C_INT_ADDR    ",  0x64},
{"AUDIO_TODDR_C_STATUS1     ",  0x65},
{"AUDIO_TODDR_C_STATUS2     ",  0x66},
{"AUDIO_TODDR_C_START_ADDRB ",  0x67},
{"AUDIO_TODDR_C_FINISH_ADDRB",  0x68},
{"AUDIO_TODDR_C_INIT_ADDR   ",  0x69},
{"AUDIO_TODDR_C_CTRL2       ",  0x6a},
{"AUDIO_RESV_ADDR_0x6b      ",  0x6b},
{"AUDIO_RESV_ADDR_0x6c      ",  0x6c},
{"AUDIO_RESV_ADDR_0x6d      ",  0x6d},
{"AUDIO_RESV_ADDR_0x6e      ",  0x6e},
{"AUDIO_RESV_ADDR_0x6f      ",  0x6f},
{"AUDIO_FRDDR_A_CTRL0       ",  0x70},
{"AUDIO_FRDDR_A_CTRL1       ",  0x71},
{"AUDIO_FRDDR_A_START_ADDR  ",  0x72},
{"AUDIO_FRDDR_A_FINISH_ADDR ",  0x73},
{"AUDIO_FRDDR_A_INT_ADDR    ",  0x74},
{"AUDIO_FRDDR_A_STATUS1     ",  0x75},
{"AUDIO_FRDDR_A_STATUS2     ",  0x76},
{"AUDIO_FRDDR_A_START_ADDRB ",  0x77},
{"AUDIO_FRDDR_A_FINISH_ADDRB",  0x78},
{"AUDIO_FRDDR_A_INIT_ADDR   ",  0x79},
{"AUDIO_FRDDR_A_CTRL2       ",  0x7a},
{"AUDIO_RESV_ADDR_0x7b      ",  0x7b},
{"AUDIO_RESV_ADDR_0x7c      ",  0x7c},
{"AUDIO_RESV_ADDR_0x7d      ",  0x7d},
{"AUDIO_RESV_ADDR_0x7e      ",  0x7e},
{"AUDIO_RESV_ADDR_0x7f      ",  0x7f},
{"AUDIO_FRDDR_B_CTRL0       ",  0x80},
{"AUDIO_FRDDR_B_CTRL1       ",  0x81},
{"AUDIO_FRDDR_B_START_ADDR  ",  0x82},
{"AUDIO_FRDDR_B_FINISH_ADDR ",  0x83},
{"AUDIO_FRDDR_B_INT_ADDR    ",  0x84},
{"AUDIO_FRDDR_B_STATUS1     ",  0x85},
{"AUDIO_FRDDR_B_STATUS2     ",  0x86},
{"AUDIO_FRDDR_B_START_ADDRB ",  0x87},
{"AUDIO_FRDDR_B_FINISH_ADDRB",  0x88},
{"AUDIO_FRDDR_B_INIT_ADDR   ",  0x89},
{"AUDIO_FRDDR_B_CTRL2       ",  0x8a},
{"AUDIO_RESV_ADDR_0x8b      ",  0x8b},
{"AUDIO_RESV_ADDR_0x8c      ",  0x8c},
{"AUDIO_RESV_ADDR_0x8d      ",  0x8d},
{"AUDIO_RESV_ADDR_0x8e      ",  0x8e},
{"AUDIO_RESV_ADDR_0x8f      ",  0x8f},
{"AUDIO_FRDDR_C_CTRL0       ",  0x90},
{"AUDIO_FRDDR_C_CTRL1       ",  0x91},
{"AUDIO_FRDDR_C_START_ADDR  ",  0x92},
{"AUDIO_FRDDR_C_FINISH_ADDR ",  0x93},
{"AUDIO_FRDDR_C_INT_ADDR    ",  0x94},
{"AUDIO_FRDDR_C_STATUS1     ",  0x95},
{"AUDIO_FRDDR_C_STATUS2     ",  0x96},
{"AUDIO_FRDDR_C_START_ADDRB ",  0x97},
{"AUDIO_FRDDR_C_FINISH_ADDRB",  0x98},
{"AUDIO_FRDDR_C_INIT_ADDR   ",  0x99},
{"AUDIO_FRDDR_C_CTRL2       ",  0x9a},
{"AUDIO_RESV_ADDR_0x9b      ",  0x9b},
{"AUDIO_RESV_ADDR_0x9c      ",  0x9c},
{"AUDIO_RESV_ADDR_0x9d      ",  0x9d},
{"AUDIO_RESV_ADDR_0x9e      ",  0x9e},
{"AUDIO_RESV_ADDR_0x9f      ",  0x9f},
{"AUDIO_ARB_CTRL            ",  0xa0},
{"AUDIO_RESV_ADDR_0xa1      ",  0xa1},
{"AUDIO_RESV_ADDR_0xa2      ",  0xa2},
{"AUDIO_RESV_ADDR_0xa3      ",  0xa3},
{"AUDIO_RESV_ADDR_0xa4      ",  0xa4},
{"AUDIO_RESV_ADDR_0xa5      ",  0xa5},
{"AUDIO_RESV_ADDR_0xa6      ",  0xa6},
{"AUDIO_RESV_ADDR_0xa7      ",  0xa7},
{"AUDIO_RESV_ADDR_0xa8      ",  0xa8},
{"AUDIO_RESV_ADDR_0xa9      ",  0xa9},
{"AUDIO_RESV_ADDR_0xaa      ",  0xaa},
{"AUDIO_RESV_ADDR_0xab      ",  0xab},
{"AUDIO_RESV_ADDR_0xac      ",  0xac},
{"AUDIO_RESV_ADDR_0xad      ",  0xad},
{"AUDIO_RESV_ADDR_0xae      ",  0xae},
{"AUDIO_RESV_ADDR_0xaf      ",  0xaf},
{"AUDIO_LB_A_CTRL0          ",  0xb0},
{"AUDIO_LB_A_CTRL1          ",  0xb1},
{"AUDIO_LB_A_CTRL2          ",  0xb2},
{"AUDIO_LB_A_CTRL3          ",  0xb3},
{"AUDIO_LB_A_DAT_CH_ID0     ",  0xb4},
{"AUDIO_LB_A_DAT_CH_ID1     ",  0xb5},
{"AUDIO_LB_A_DAT_CH_ID2     ",  0xb6},
{"AUDIO_LB_A_DAT_CH_ID3     ",  0xb7},
{"AUDIO_LB_A_LB_CH_ID0      ",  0xb8},
{"AUDIO_LB_A_LB_CH_ID1      ",  0xb9},
{"AUDIO_LB_A_LB_CH_ID2      ",  0xba},
{"AUDIO_LB_A_LB_CH_ID3      ",  0xbb},
{"AUDIO_LB_A_STS            ",  0xbc},
{"AUDIO_RESV_ADDR_0xbd      ",  0xbd},
{"AUDIO_RESV_ADDR_0xbe      ",  0xbe},
{"AUDIO_RESV_ADDR_0xbf      ",  0xbf},
{"AUDIO_TDMIN_A_CTRL        ",  0xc0},
{"AUDIO_TDMIN_A_SWAP        ",  0xc1},
{"AUDIO_TDMIN_A_MASK0       ",  0xc2},
{"AUDIO_TDMIN_A_MASK1       ",  0xc3},
{"AUDIO_TDMIN_A_MASK2       ",  0xc4},
{"AUDIO_TDMIN_A_MASK3       ",  0xc5},
{"AUDIO_TDMIN_A_STAT        ",  0xc6},
{"AUDIO_TDMIN_A_MUTE_VAL    ",  0xc7},
{"AUDIO_TDMIN_A_MUTE0       ",  0xc8},
{"AUDIO_TDMIN_A_MUTE1       ",  0xc9},
{"AUDIO_TDMIN_A_MUTE2       ",  0xca},
{"AUDIO_TDMIN_A_MUTE3       ",  0xcb},
{"AUDIO_RESV_ADDR_0xcc      ",  0xcc},
{"AUDIO_RESV_ADDR_0xcd      ",  0xcd},
{"AUDIO_RESV_ADDR_0xce      ",  0xce},
{"AUDIO_RESV_ADDR_0xcf      ",  0xcf},
{"AUDIO_TDMIN_B_CTRL        ",  0xd0},
{"AUDIO_TDMIN_B_SWAP        ",  0xd1},
{"AUDIO_TDMIN_B_MASK0       ",  0xd2},
{"AUDIO_TDMIN_B_MASK1       ",  0xd3},
{"AUDIO_TDMIN_B_MASK2       ",  0xd4},
{"AUDIO_TDMIN_B_MASK3       ",  0xd5},
{"AUDIO_TDMIN_B_STAT        ",  0xd6},
{"AUDIO_TDMIN_B_MUTE_VAL    ",  0xd7},
{"AUDIO_TDMIN_B_MUTE0       ",  0xd8},
{"AUDIO_TDMIN_B_MUTE1       ",  0xd9},
{"AUDIO_TDMIN_B_MUTE2       ",  0xda},
{"AUDIO_TDMIN_B_MUTE3       ",  0xdb},
{"AUDIO_RESV_ADDR_0xdc      ",  0xdc},
{"AUDIO_RESV_ADDR_0xdd      ",  0xdd},
{"AUDIO_RESV_ADDR_0xde      ",  0xde},
{"AUDIO_RESV_ADDR_0xdf      ",  0xdf},
{"AUDIO_TDMIN_C_CTRL        ",  0xe0},
{"AUDIO_TDMIN_C_SWAP        ",  0xe1},
{"AUDIO_TDMIN_C_MASK0       ",  0xe2},
{"AUDIO_TDMIN_C_MASK1       ",  0xe3},
{"AUDIO_TDMIN_C_MASK2       ",  0xe4},
{"AUDIO_TDMIN_C_MASK3       ",  0xe5},
{"AUDIO_TDMIN_C_STAT        ",  0xe6},
{"AUDIO_TDMIN_C_MUTE_VAL    ",  0xe7},
{"AUDIO_TDMIN_C_MUTE0       ",  0xe8},
{"AUDIO_TDMIN_C_MUTE1       ",  0xe9},
{"AUDIO_TDMIN_C_MUTE2       ",  0xea},
{"AUDIO_TDMIN_C_MUTE3       ",  0xeb},
{"AUDIO_RESV_ADDR_0xec      ",  0xec},
{"AUDIO_RESV_ADDR_0xed      ",  0xed},
{"AUDIO_RESV_ADDR_0xee      ",  0xee},
{"AUDIO_RESV_ADDR_0xef      ",  0xef},
{"AUDIO_TDMIN_LB_CTRL       ",  0xf0},
{"AUDIO_TDMIN_LB_SWAP       ",  0xf1},
{"AUDIO_TDMIN_LB_MASK0      ",  0xf2},
{"AUDIO_TDMIN_LB_MASK1      ",  0xf3},
{"AUDIO_TDMIN_LB_MASK2      ",  0xf4},
{"AUDIO_TDMIN_LB_MASK3      ",  0xf5},
{"AUDIO_TDMIN_LB_STAT       ",  0xf6},
{"AUDIO_TDMIN_LB_MUTE_VAL   ",  0xf7},
{"AUDIO_TDMIN_LB_MUTE0      ",  0xf8},
{"AUDIO_TDMIN_LB_MUTE1      ",  0xf9},
{"AUDIO_TDMIN_LB_MUTE2      ",  0xfa},
{"AUDIO_TDMIN_LB_MUTE3      ",  0xfb},
{"AUDIO_RESV_ADDR_0xfc      ",  0xfc},
{"AUDIO_RESV_ADDR_0xfd      ",  0xfd},
{"AUDIO_RESV_ADDR_0xfe      ",  0xfe},
{"AUDIO_RESV_ADDR_0xff      ",  0xff},
{"AUDIO_SPDIFIN_CTRL0       ", 0x100},
{"AUDIO_SPDIFIN_CTRL1       ", 0x101},
{"AUDIO_SPDIFIN_CTRL2       ", 0x102},
{"AUDIO_SPDIFIN_CTRL3       ", 0x103},
{"AUDIO_SPDIFIN_CTRL4       ", 0x104},
{"AUDIO_SPDIFIN_CTRL5       ", 0x105},
{"AUDIO_SPDIFIN_CTRL6       ", 0x106},
{"AUDIO_SPDIFIN_STAT0       ", 0x107},
{"AUDIO_SPDIFIN_STAT1       ", 0x108},
{"AUDIO_SPDIFIN_STAT2       ", 0x109},
{"AUDIO_SPDIFIN_MUTE_VAL    ", 0x10a},
{"AUDIO_RESV_ADDR_0x10b     ", 0x10b},
{"AUDIO_RESV_ADDR_0x10c     ", 0x10c},
{"AUDIO_RESV_ADDR_0x10d     ", 0x10d},
{"AUDIO_RESV_ADDR_0x10e     ", 0x10e},
{"AUDIO_RESV_ADDR_0x10f     ", 0x10f},
{"AUDIO_RESAMPLEA_CTRL0     ", 0x110},
{"AUDIO_RESAMPLEA_CTRL1     ", 0x111},
{"AUDIO_RESAMPLEA_CTRL2     ", 0x112},
{"AUDIO_RESAMPLEA_CTRL3     ", 0x113},
{"AUDIO_RESAMPLEA_COEF0     ", 0x114},
{"AUDIO_RESAMPLEA_COEF1     ", 0x115},
{"AUDIO_RESAMPLEA_COEF2     ", 0x116},
{"AUDIO_RESAMPLEA_COEF3     ", 0x117},
{"AUDIO_RESAMPLEA_COEF4     ", 0x118},
{"AUDIO_RESAMPLEA_STATUS1   ", 0x119},
{"AUDIO_RESV_ADDR_0x11a     ", 0x11a},
{"AUDIO_RESV_ADDR_0x11b     ", 0x11b},
{"AUDIO_RESV_ADDR_0x11c     ", 0x11c},
{"AUDIO_RESV_ADDR_0x11d     ", 0x11d},
{"AUDIO_RESV_ADDR_0x11e     ", 0x11e},
{"AUDIO_RESV_ADDR_0x11f     ", 0x11f},
{"AUDIO_SPDIFOUT_STAT       ", 0x120},
{"AUDIO_SPDIFOUT_GAIN0      ", 0x121},
{"AUDIO_SPDIFOUT_GAIN1      ", 0x122},
{"AUDIO_SPDIFOUT_CTRL0      ", 0x123},
{"AUDIO_SPDIFOUT_CTRL1      ", 0x124},
{"AUDIO_SPDIFOUT_PREAMB     ", 0x125},
{"AUDIO_SPDIFOUT_SWAP       ", 0x126},
{"AUDIO_SPDIFOUT_CHSTS0     ", 0x127},
{"AUDIO_SPDIFOUT_CHSTS1     ", 0x128},
{"AUDIO_SPDIFOUT_CHSTS2     ", 0x129},
{"AUDIO_SPDIFOUT_CHSTS3     ", 0x12a},
{"AUDIO_SPDIFOUT_CHSTS4     ", 0x12b},
{"AUDIO_SPDIFOUT_CHSTS5     ", 0x12c},
{"AUDIO_SPDIFOUT_CHSTS6     ", 0x12d},
{"AUDIO_SPDIFOUT_CHSTS7     ", 0x12e},
{"AUDIO_SPDIFOUT_CHSTS8     ", 0x12f},
{"AUDIO_SPDIFOUT_CHSTS9     ", 0x130},
{"AUDIO_SPDIFOUT_CHSTSA     ", 0x131},
{"AUDIO_SPDIFOUT_CHSTSB     ", 0x132},
{"AUDIO_SPDIFOUT_MUTE_VAL   ", 0x133},
{"AUDIO_RESV_ADDR_0x134     ", 0x134},
{"AUDIO_RESV_ADDR_0x135     ", 0x135},
{"AUDIO_RESV_ADDR_0x136     ", 0x136},
{"AUDIO_RESV_ADDR_0x137     ", 0x137},
{"AUDIO_RESV_ADDR_0x138     ", 0x138},
{"AUDIO_RESV_ADDR_0x139     ", 0x139},
{"AUDIO_RESV_ADDR_0x13a     ", 0x13a},
{"AUDIO_RESV_ADDR_0x13b     ", 0x13b},
{"AUDIO_RESV_ADDR_0x13c     ", 0x13c},
{"AUDIO_RESV_ADDR_0x13d     ", 0x13d},
{"AUDIO_RESV_ADDR_0x13e     ", 0x13e},
{"AUDIO_RESV_ADDR_0x13f     ", 0x13f},
{"AUDIO_TDMOUT_A_CTRL0      ", 0x140},
{"AUDIO_TDMOUT_A_CTRL1      ", 0x141},
{"AUDIO_TDMOUT_A_SWAP       ", 0x142},
{"AUDIO_TDMOUT_A_MASK0      ", 0x143},
{"AUDIO_TDMOUT_A_MASK1      ", 0x144},
{"AUDIO_TDMOUT_A_MASK2      ", 0x145},
{"AUDIO_TDMOUT_A_MASK3      ", 0x146},
{"AUDIO_TDMOUT_A_STAT       ", 0x147},
{"AUDIO_TDMOUT_A_GAIN0      ", 0x148},
{"AUDIO_TDMOUT_A_GAIN1      ", 0x149},
{"AUDIO_TDMOUT_A_MUTE_VAL   ", 0x14a},
{"AUDIO_TDMOUT_A_MUTE0      ", 0x14b},
{"AUDIO_TDMOUT_A_MUTE1      ", 0x14c},
{"AUDIO_TDMOUT_A_MUTE2      ", 0x14d},
{"AUDIO_TDMOUT_A_MUTE3      ", 0x14e},
{"AUDIO_TDMOUT_A_MASK_VAL   ", 0x14f},
{"AUDIO_TDMOUT_B_CTRL0      ", 0x150},
{"AUDIO_TDMOUT_B_CTRL1      ", 0x151},
{"AUDIO_TDMOUT_B_SWAP       ", 0x152},
{"AUDIO_TDMOUT_B_MASK0      ", 0x153},
{"AUDIO_TDMOUT_B_MASK1      ", 0x154},
{"AUDIO_TDMOUT_B_MASK2      ", 0x155},
{"AUDIO_TDMOUT_B_MASK3      ", 0x156},
{"AUDIO_TDMOUT_B_STAT       ", 0x157},
{"AUDIO_TDMOUT_B_GAIN0      ", 0x158},
{"AUDIO_TDMOUT_B_GAIN1      ", 0x159},
{"AUDIO_TDMOUT_B_MUTE_VAL   ", 0x15a},
{"AUDIO_TDMOUT_B_MUTE0      ", 0x15b},
{"AUDIO_TDMOUT_B_MUTE1      ", 0x15c},
{"AUDIO_TDMOUT_B_MUTE2      ", 0x15d},
{"AUDIO_TDMOUT_B_MUTE3      ", 0x15e},
{"AUDIO_TDMOUT_B_MASK_VAL   ", 0x15f},
{"AUDIO_TDMOUT_C_CTRL0      ", 0x160},
{"AUDIO_TDMOUT_C_CTRL1      ", 0x161},
{"AUDIO_TDMOUT_C_SWAP       ", 0x162},
{"AUDIO_TDMOUT_C_MASK0      ", 0x163},
{"AUDIO_TDMOUT_C_MASK1      ", 0x164},
{"AUDIO_TDMOUT_C_MASK2      ", 0x165},
{"AUDIO_TDMOUT_C_MASK3      ", 0x166},
{"AUDIO_TDMOUT_C_STAT       ", 0x167},
{"AUDIO_TDMOUT_C_GAIN0      ", 0x168},
{"AUDIO_TDMOUT_C_GAIN1      ", 0x169},
{"AUDIO_TDMOUT_C_MUTE_VAL   ", 0x16a},
{"AUDIO_TDMOUT_C_MUTE0      ", 0x16b},
{"AUDIO_TDMOUT_C_MUTE1      ", 0x16c},
{"AUDIO_TDMOUT_C_MUTE2      ", 0x16d},
{"AUDIO_TDMOUT_C_MUTE3      ", 0x16e},
{"AUDIO_TDMOUT_C_MASK_VAL   ", 0x16f},
{"AUDIO_RESV_ADDR_0x170     ", 0x170},
{"AUDIO_RESV_ADDR_0x171     ", 0x171},
{"AUDIO_RESV_ADDR_0x172     ", 0x172},
{"AUDIO_RESV_ADDR_0x173     ", 0x173},
{"AUDIO_RESV_ADDR_0x174     ", 0x174},
{"AUDIO_RESV_ADDR_0x175     ", 0x175},
{"AUDIO_RESV_ADDR_0x176     ", 0x176},
{"AUDIO_RESV_ADDR_0x177     ", 0x177},
{"AUDIO_RESV_ADDR_0x178     ", 0x178},
{"AUDIO_RESV_ADDR_0x179     ", 0x179},
{"AUDIO_RESV_ADDR_0x17a     ", 0x17a},
{"AUDIO_RESV_ADDR_0x17b     ", 0x17b},
{"AUDIO_RESV_ADDR_0x17c     ", 0x17c},
{"AUDIO_RESV_ADDR_0x17d     ", 0x17d},
{"AUDIO_RESV_ADDR_0x17e     ", 0x17e},
{"AUDIO_RESV_ADDR_0x17f     ", 0x17f},
{"AUDIO_RESV_ADDR_0x180     ", 0x180},
{"AUDIO_RESV_ADDR_0x181     ", 0x181},
{"AUDIO_RESV_ADDR_0x182     ", 0x182},
{"AUDIO_RESV_ADDR_0x183     ", 0x183},
{"AUDIO_RESV_ADDR_0x184     ", 0x184},
{"AUDIO_RESV_ADDR_0x185     ", 0x185},
{"AUDIO_RESV_ADDR_0x186     ", 0x186},
{"AUDIO_RESV_ADDR_0x187     ", 0x187},
{"AUDIO_RESV_ADDR_0x188     ", 0x188},
{"AUDIO_RESV_ADDR_0x189     ", 0x189},
{"AUDIO_RESV_ADDR_0x18a     ", 0x18a},
{"AUDIO_RESV_ADDR_0x18b     ", 0x18b},
{"AUDIO_RESV_ADDR_0x18c     ", 0x18c},
{"AUDIO_RESV_ADDR_0x18d     ", 0x18d},
{"AUDIO_RESV_ADDR_0x18e     ", 0x18e},
{"AUDIO_RESV_ADDR_0x18f     ", 0x18f},
{"AUDIO_SECURITY_CTRL0      ", 0x190},
{"AUDIO_SECURITY_CTRL1      ", 0x191},
{"AUDIO_RESV_ADDR_0x192     ", 0x192},
{"AUDIO_RESV_ADDR_0x193     ", 0x193},
{"AUDIO_RESV_ADDR_0x194     ", 0x194},
{"AUDIO_RESV_ADDR_0x195     ", 0x195},
{"AUDIO_RESV_ADDR_0x196     ", 0x196},
{"AUDIO_RESV_ADDR_0x197     ", 0x197},
{"AUDIO_RESV_ADDR_0x198     ", 0x198},
{"AUDIO_RESV_ADDR_0x199     ", 0x199},
{"AUDIO_RESV_ADDR_0x19a     ", 0x19a},
{"AUDIO_RESV_ADDR_0x19b     ", 0x19b},
{"AUDIO_RESV_ADDR_0x19c     ", 0x19c},
{"AUDIO_RESV_ADDR_0x19d     ", 0x19d},
{"AUDIO_RESV_ADDR_0x19e     ", 0x19e},
{"AUDIO_RESV_ADDR_0x19f     ", 0x19f},
{"AUDIO_SPDIFOUT_B_STAT     ", 0x1a0},
{"AUDIO_SPDIFOUT_B_GAIN0    ", 0x1a1},
{"AUDIO_SPDIFOUT_B_GAIN1    ", 0x1a2},
{"AUDIO_SPDIFOUT_B_CTRL0    ", 0x1a3},
{"AUDIO_SPDIFOUT_B_CTRL1    ", 0x1a4},
{"AUDIO_SPDIFOUT_B_PREAMB   ", 0x1a5},
{"AUDIO_SPDIFOUT_B_SWAP     ", 0x1a6},
{"AUDIO_SPDIFOUT_B_CHSTS0   ", 0x1a7},
{"AUDIO_SPDIFOUT_B_CHSTS1   ", 0x1a8},
{"AUDIO_SPDIFOUT_B_CHSTS2   ", 0x1a9},
{"AUDIO_SPDIFOUT_B_CHSTS3   ", 0x1aa},
{"AUDIO_SPDIFOUT_B_CHSTS4   ", 0x1ab},
{"AUDIO_SPDIFOUT_B_CHSTS5   ", 0x1ac},
{"AUDIO_SPDIFOUT_B_CHSTS6   ", 0x1ad},
{"AUDIO_SPDIFOUT_B_CHSTS7   ", 0x1ae},
{"AUDIO_SPDIFOUT_B_CHSTS8   ", 0x1af},
{"AUDIO_SPDIFOUT_B_CHSTS9   ", 0x1b0},
{"AUDIO_SPDIFOUT_B_CHSTSA   ", 0x1b1},
{"AUDIO_SPDIFOUT_B_CHSTSB   ", 0x1b2},
{"AUDIO_SPDIFOUT_B_MUTE_VAL ", 0x1b3},
{"AUDIO_RESV_ADDR_0x1b4     ", 0x1b4},
{"AUDIO_RESV_ADDR_0x1b5     ", 0x1b5},
{"AUDIO_RESV_ADDR_0x1b6     ", 0x1b6},
{"AUDIO_RESV_ADDR_0x1b7     ", 0x1b7},
{"AUDIO_RESV_ADDR_0x1b8     ", 0x1b8},
{"AUDIO_RESV_ADDR_0x1b9     ", 0x1b9},
{"AUDIO_RESV_ADDR_0x1ba     ", 0x1ba},
{"AUDIO_RESV_ADDR_0x1bb     ", 0x1bb},
{"AUDIO_RESV_ADDR_0x1bc     ", 0x1bc},
{"AUDIO_RESV_ADDR_0x1bd     ", 0x1bd},
{"AUDIO_RESV_ADDR_0x1be     ", 0x1be},
{"AUDIO_RESV_ADDR_0x1bf     ", 0x1bf},
{"AUDIO_TORAM_CTRL0         ", 0x1c0},
{"AUDIO_TORAM_CTRL1         ", 0x1c1},
{"AUDIO_TORAM_START_ADDR    ", 0x1c2},
{"AUDIO_TORAM_FINISH_ADDR   ", 0x1c3},
{"AUDIO_TORAM_INT_ADDR      ", 0x1c4},
{"AUDIO_TORAM_STATUS1       ", 0x1c5},
{"AUDIO_TORAM_STATUS2       ", 0x1c6},
{"AUDIO_TORAM_INIT_ADDR     ", 0x1c7},
{"AUDIO_RESV_ADDR_0x1c8     ", 0x1c8},
{"AUDIO_RESV_ADDR_0x1c9     ", 0x1c9},
{"AUDIO_RESV_ADDR_0x1ca     ", 0x1ca},
{"AUDIO_RESV_ADDR_0x1cb     ", 0x1cb},
{"AUDIO_RESV_ADDR_0x1cc     ", 0x1cc},
{"AUDIO_RESV_ADDR_0x1cd     ", 0x1cd},
{"AUDIO_RESV_ADDR_0x1ce     ", 0x1ce},
{"AUDIO_RESV_ADDR_0x1cf     ", 0x1cf},
{"AUDIO_TOACODEC_CTRL0      ", 0x1d0},
{"AUDIO_TOHDMITX_CTRL0      ", 0x1d1},
{"AUDIO_TOVAD_CTRL0         ", 0x1d2},
{"AUDIO_FRATV_CTRL0         ", 0x1d3},
{"AUDIO_RESV_ADDR_0x1d4     ", 0x1d4},
{"AUDIO_RESV_ADDR_0x1d5     ", 0x1d5},
{"AUDIO_RESV_ADDR_0x1d6     ", 0x1d6},
{"AUDIO_RESV_ADDR_0x1d7     ", 0x1d7},
{"AUDIO_RESV_ADDR_0x1d8     ", 0x1d8},
{"AUDIO_RESV_ADDR_0x1d9     ", 0x1d9},
{"AUDIO_RESV_ADDR_0x1da     ", 0x1da},
{"AUDIO_RESV_ADDR_0x1db     ", 0x1db},
{"AUDIO_RESV_ADDR_0x1dc     ", 0x1dc},
{"AUDIO_RESV_ADDR_0x1dd     ", 0x1dd},
{"AUDIO_RESV_ADDR_0x1de     ", 0x1de},
{"AUDIO_RESV_ADDR_0x1df     ", 0x1df},
{"AUDIO_RESAMPLEB_CTRL0     ", 0x1e0},
{"AUDIO_RESAMPLEB_CTRL1     ", 0x1e1},
{"AUDIO_RESAMPLEB_CTRL2     ", 0x1e2},
{"AUDIO_RESAMPLEB_CTRL3     ", 0x1e3},
{"AUDIO_RESAMPLEB_COEF0     ", 0x1e4},
{"AUDIO_RESAMPLEB_COEF1     ", 0x1e5},
{"AUDIO_RESAMPLEB_COEF2     ", 0x1e6},
{"AUDIO_RESAMPLEB_COEF3     ", 0x1e7},
{"AUDIO_RESAMPLEB_COEF4     ", 0x1e8},
{"AUDIO_RESAMPLEB_STATUS1   ", 0x1e9},
{"AUDIO_RESV_ADDR_0x1ea     ", 0x1ea},
{"AUDIO_RESV_ADDR_0x1eb     ", 0x1eb},
{"AUDIO_RESV_ADDR_0x1ec     ", 0x1ec},
{"AUDIO_RESV_ADDR_0x1ed     ", 0x1ed},
{"AUDIO_RESV_ADDR_0x1ee     ", 0x1ee},
{"AUDIO_RESV_ADDR_0x1ef     ", 0x1ef},
{"AUDIO_SPDIFIN_LB_CTRL0    ", 0x1f0},
{"AUDIO_SPDIFIN_LB_CTRL1    ", 0x1f1},
{"AUDIO_RESV_ADDR_0x1f2     ", 0x1f2},
{"AUDIO_RESV_ADDR_0x1f3     ", 0x1f3},
{"AUDIO_RESV_ADDR_0x1f4     ", 0x1f4},
{"AUDIO_RESV_ADDR_0x1f5     ", 0x1f5},
{"AUDIO_SPDIFIN_LB_CTRL6    ", 0x1f6},
{"AUDIO_SPDIFIN_LB_STAT0    ", 0x1f7},
{"AUDIO_SPDIFIN_LB_STAT1    ", 0x1f8},
{"AUDIO_RESV_ADDR_0x1f9     ", 0x1f9},
{"AUDIO_SPDIFIN_LB_MUTE_VAL ", 0x1fa},
{"AUDIO_RESV_ADDR_0x1fb     ", 0x1fb},
{"AUDIO_RESV_ADDR_0x1fc     ", 0x1fc},
{"AUDIO_RESV_ADDR_0x1fd     ", 0x1fd},
{"AUDIO_RESV_ADDR_0x1fe     ", 0x1fe},
{"AUDIO_RESV_ADDR_0x1ff     ", 0x1ff},
{"AUDIO_FRHDMIRX_CTRL0      ", 0x200},
{"AUDIO_FRHDMIRX_CTRL1      ", 0x201},
{"AUDIO_FRHDMIRX_CTRL2      ", 0x202},
{"AUDIO_FRHDMIRX_CTRL3      ", 0x203},
{"AUDIO_FRHDMIRX_CTRL4      ", 0x204},
{"AUDIO_FRHDMIRX_CTRL5      ", 0x205},
{"AUDIO_RESV_ADDR_0x206     ", 0x206},
{"AUDIO_RESV_ADDR_0x207     ", 0x207},
{"AUDIO_RESV_ADDR_0x208     ", 0x208},
{"AUDIO_RESV_ADDR_0x209     ", 0x209},
{"AUDIO_FRHDMIRX_STAT0      ", 0x20a},
{"AUDIO_FRHDMIRX_STAT1      ", 0x20b},
{"AUDIO_RESV_ADDR_0x20c     ", 0x20c},
{"AUDIO_RESV_ADDR_0x20d     ", 0x20d},
{"AUDIO_RESV_ADDR_0x20e     ", 0x20e},
{"AUDIO_RESV_ADDR_0x20f     ", 0x20f},
{"AUDIO_TODDR_D_CTRL0       ", 0x210},
{"AUDIO_TODDR_D_CTRL1       ", 0x211},
{"AUDIO_TODDR_D_START_ADDR  ", 0x212},
{"AUDIO_TODDR_D_FINISH_ADDR ", 0x213},
{"AUDIO_TODDR_D_INT_ADDR    ", 0x214},
{"AUDIO_TODDR_D_STATUS1     ", 0x215},
{"AUDIO_TODDR_D_STATUS2     ", 0x216},
{"AUDIO_TODDR_D_START_ADDRB ", 0x217},
{"AUDIO_TODDR_D_FINISH_ADDRB", 0x218},
{"AUDIO_TODDR_D_INIT_ADDR   ", 0x219},
{"AUDIO_TODDR_D_CTRL2       ", 0x21a},
{"AUDIO_RESV_ADDR_0x21b     ", 0x21b},
{"AUDIO_RESV_ADDR_0x21c     ", 0x21c},
{"AUDIO_RESV_ADDR_0x21d     ", 0x21d},
{"AUDIO_RESV_ADDR_0x21e     ", 0x21e},
{"AUDIO_RESV_ADDR_0x21f     ", 0x21f},
{"AUDIO_FRDDR_D_CTRL0       ", 0x220},
{"AUDIO_FRDDR_D_CTRL1       ", 0x221},
{"AUDIO_FRDDR_D_START_ADDR  ", 0x222},
{"AUDIO_FRDDR_D_FINISH_ADDR ", 0x223},
{"AUDIO_FRDDR_D_INT_ADDR    ", 0x224},
{"AUDIO_FRDDR_D_STATUS1     ", 0x225},
{"AUDIO_FRDDR_D_STATUS2     ", 0x226},
{"AUDIO_FRDDR_D_START_ADDRB ", 0x227},
{"AUDIO_FRDDR_D_FINISH_ADDRB", 0x228},
{"AUDIO_FRDDR_D_INIT_ADDR   ", 0x229},
{"AUDIO_FRDDR_D_CTRL2       ", 0x22a},
{"AUDIO_RESV_ADDR_0x22b     ", 0x22b},
{"AUDIO_RESV_ADDR_0x22c     ", 0x22c},
{"AUDIO_RESV_ADDR_0x22d     ", 0x22d},
{"AUDIO_RESV_ADDR_0x22e     ", 0x22e},
{"AUDIO_RESV_ADDR_0x22f     ", 0x22f},
{"AUDIO_LB_B_CTRL0          ", 0x230},
{"AUDIO_LB_B_CTRL1          ", 0x231},
{"AUDIO_LB_B_CTRL2          ", 0x232},
{"AUDIO_LB_B_CTRL3          ", 0x233},
{"AUDIO_LB_B_DAT_CH_ID0     ", 0x234},
{"AUDIO_LB_B_DAT_CH_ID1     ", 0x235},
{"AUDIO_LB_B_DAT_CH_ID2     ", 0x236},
{"AUDIO_LB_B_DAT_CH_ID3     ", 0x237},
{"AUDIO_LB_B_LB_CH_ID0      ", 0x238},
{"AUDIO_LB_B_LB_CH_ID1      ", 0x239},
{"AUDIO_LB_B_LB_CH_ID2      ", 0x23a},
{"AUDIO_LB_B_LB_CH_ID3      ", 0x23b},
{"AUDIO_LB_B_STS            ", 0x23c},
};

#endif
