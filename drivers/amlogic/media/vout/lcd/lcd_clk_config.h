/* SPDX-License-Identifier: GPL-2.0+ */
/*
 *
 * Copyright (C) 2019 Amlogic, Inc. All rights reserved.
 *
 */

#ifndef _LCD_CLK_CONFIG_H
#define _LCD_CLK_CONFIG_H

#include <linux/types.h>
#include <linux/amlogic/media/vout/lcd/lcd_vout.h>

/* **********************************
 * clk config
 * **********************************
 */
#define LCD_PLL_MODE_DEFAULT         BIT(0)
#define LCD_PLL_MODE_SPECIAL_CNTL    BIT(1)
#define LCD_PLL_MODE_FRAC_SHIFT      BIT(2)

#define PLL_RETRY_MAX		20
#define LCD_CLK_CTRL_EN      0
#define LCD_CLK_CTRL_RST     1
#define LCD_CLK_CTRL_M	     2
#define LCD_CLK_CTRL_FRAC    3
#define LCD_CLK_CTRL_END     0xffff

#define LCD_CLK_REG_END      0xffff
#define LCD_CLK_CTRL_CNT_MAX 10
struct lcd_clk_ctrl_s {
	unsigned int flag;
	unsigned int reg;
	unsigned int bit;
	unsigned int len;
};

#define LCD_PRBS_MODE_LVDS    BIT(0)
#define LCD_PRBS_MODE_VX1     BIT(1)
#define LCD_PRBS_MODE_MAX     2

struct lcd_clk_config_s { /* unit: kHz */
	/* IN-OUT parameters */
	unsigned int fin;
	unsigned int fout;

	/* pll parameters */
	unsigned int pll_mode; /* txl */
	unsigned int pll_od_fb;
	unsigned int pll_m;
	unsigned int pll_n;
	unsigned int pll_fvco;
	unsigned int pll_od1_sel;
	unsigned int pll_od2_sel;
	unsigned int pll_od3_sel;
	unsigned int pll_tcon_div_sel;
	unsigned int pll_level;
	unsigned int pll_frac;
	unsigned int pll_frac_half_shift;
	unsigned int pll_fout;
	unsigned int ss_level;
	unsigned int ss_freq;
	unsigned int ss_mode;
	unsigned int div_sel;
	unsigned int xd;
	unsigned int div_sel_max;
	unsigned int xd_max;
	unsigned int err_fmin;

	struct lcd_clk_data_s *data;
};

struct lcd_clktree_s {
	unsigned char clk_gate_state;
	unsigned char clk_gate_optional_state;

	struct clk *encl_top_gate;
	struct clk *encl_int_gate;

	struct clk *dsi_host_gate;
	struct clk *dsi_phy_gate;
	struct clk *dsi_meas;
	struct clk *mipi_enable_gate;
	struct clk *mipi_bandgap_gate;
	struct clk *gp0_pll;
	struct clk *tcon_gate;
	struct clk *tcon_clk;
};

struct lcd_clk_data_s {
	/* clk path node parameters */
	unsigned int pll_od_fb;
	unsigned int pll_m_max;
	unsigned int pll_m_min;
	unsigned int pll_n_max;
	unsigned int pll_n_min;
	unsigned int pll_frac_range;
	unsigned int pll_frac_sign_bit;
	unsigned int pll_od_sel_max;
	unsigned int pll_ref_fmax;
	unsigned int pll_ref_fmin;
	unsigned int pll_vco_fmax;
	unsigned int pll_vco_fmin;
	unsigned int pll_out_fmax;
	unsigned int pll_out_fmin;
	unsigned int div_in_fmax;
	unsigned int div_out_fmax;
	unsigned int xd_out_fmax;

	unsigned char clk_path_valid;
	unsigned char vclk_sel;
	struct lcd_clk_ctrl_s *pll_ctrl_table;

	unsigned int ss_level_max;
	unsigned int ss_freq_max;
	unsigned int ss_mode_max;
	char **ss_level_table;
	char **ss_freq_table;
	char **ss_mode_table;

	void (*clk_generate_parameter)(struct lcd_config_s *pconf);
	void (*pll_frac_generate)(struct lcd_config_s *pconf);
	void (*set_ss_level)(unsigned int level);
	void (*set_ss_advance)(unsigned int freq, unsigned int mode);
	void (*clk_set)(struct lcd_config_s *pconf);
	void (*vclk_crt_set)(struct lcd_clk_config_s *cconf);
	void (*clk_gate_switch)(struct aml_lcd_drv_s *lcd_drv, int status);
	void (*clk_gate_optional_switch)(struct aml_lcd_drv_s *lcd_drv,
					 int status);
	void (*clktree_probe)(void);
	void (*clktree_remove)(void);
	void (*clk_config_init_print)(void);
	void (*prbs_clk_config)(unsigned int prbs_mode);
	int (*clk_config_print)(char *buf, int offset);
};

/* ******** api ******** */
int meson_clk_measure(unsigned int clk_mux);
int lcd_debug_info_len(int num);

struct lcd_clk_config_s *get_lcd_clk_config(void);
int lcd_clk_config_print(char *buf, int offset);
int lcd_encl_clk_msr(void);
void lcd_pll_reset(void);
int lcd_get_ss(char *buf);
int lcd_set_ss(unsigned int level, unsigned int freq, unsigned int mode);
void lcd_clk_update(struct lcd_config_s *pconf);
void lcd_clk_set(struct lcd_config_s *pconf);
void lcd_clk_disable(void);
void lcd_clk_generate_parameter(struct lcd_config_s *pconf);
void lcd_clk_gate_switch(int status);

int lcd_clk_path_change(int sel);
void lcd_clk_config_probe(void);
void lcd_clk_config_remove(void);

#endif
