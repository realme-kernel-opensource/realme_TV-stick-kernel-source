/* SPDX-License-Identifier: (GPL-2.0+ OR MIT) */
/*
 * Copyright (c) 2019 Amlogic, Inc. All rights reserved.
 */

#ifndef SYS_REGS_HEADER_
#define SYS_REGS_HEADER_

/*
 * pay attention : the regs range has
 * changed to 0x04xx in txlx, it was
 * converted automatically based on
 * the platform at init.
 * #define RESET0_REGISTER 0x0401
 */

#define RESET0_REGISTER 0x1101
#define RESET1_REGISTER 0x1102
#define RESET2_REGISTER 0x1103
#define RESET3_REGISTER 0x1104
#define RESET4_REGISTER 0x1105
#define RESET5_REGISTER 0x1106
#define RESET6_REGISTER 0x1107
#define RESET7_REGISTER 0x1108

#define ASSIST_HW_REV 0x1f53
#endif

