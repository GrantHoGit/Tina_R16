/*
 * arch/sparc/include/asm/barrier.h
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#ifndef ___ASM_SPARC_BARRIER_H
#define ___ASM_SPARC_BARRIER_H
#if defined(__sparc__) && defined(__arch64__)
#include <asm/barrier_64.h>
#else
#include <asm/barrier_32.h>
#endif
#endif