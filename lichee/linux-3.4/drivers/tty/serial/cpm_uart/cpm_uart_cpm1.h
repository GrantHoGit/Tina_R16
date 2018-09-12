/*
 * drivers/tty/serial/cpm_uart/cpm_uart_cpm1.h
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
/*
 * Driver for CPM (SCC/SMC) serial ports
 *
 * definitions for cpm1
 *
 */

#ifndef CPM_UART_CPM1_H
#define CPM_UART_CPM1_H

#include <asm/cpm1.h>

static inline void cpm_set_brg(int brg, int baud)
{
	cpm_setbrg(brg, baud);
}

static inline void cpm_set_scc_fcr(scc_uart_t __iomem * sup)
{
	out_8(&sup->scc_genscc.scc_rfcr, SMC_EB);
	out_8(&sup->scc_genscc.scc_tfcr, SMC_EB);
}

static inline void cpm_set_smc_fcr(smc_uart_t __iomem * up)
{
	out_8(&up->smc_rfcr, SMC_EB);
	out_8(&up->smc_tfcr, SMC_EB);
}

#define DPRAM_BASE	((u8 __iomem __force *)cpm_dpram_addr(0))

#endif