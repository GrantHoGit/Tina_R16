/*
 * arch/powerpc/include/asm/cache.h
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#ifndef _ASM_POWERPC_CACHE_H
#define _ASM_POWERPC_CACHE_H

#ifdef __KERNEL__


/* bytes per L1 cache line */
#if defined(CONFIG_8xx) || defined(CONFIG_403GCX)
#define L1_CACHE_SHIFT		4
#define MAX_COPY_PREFETCH	1
#elif defined(CONFIG_PPC_E500MC)
#define L1_CACHE_SHIFT		6
#define MAX_COPY_PREFETCH	4
#elif defined(CONFIG_PPC32)
#define MAX_COPY_PREFETCH	4
#if defined(CONFIG_PPC_47x)
#define L1_CACHE_SHIFT		7
#else
#define L1_CACHE_SHIFT		5
#endif
#else /* CONFIG_PPC64 */
#define L1_CACHE_SHIFT		7
#endif

#define	L1_CACHE_BYTES		(1 << L1_CACHE_SHIFT)

#define	SMP_CACHE_BYTES		L1_CACHE_BYTES

#if defined(__powerpc64__) && !defined(__ASSEMBLY__)
struct ppc64_caches {
	u32	dsize;			/* L1 d-cache size */
	u32	dline_size;		/* L1 d-cache line size	*/
	u32	log_dline_size;
	u32	dlines_per_page;
	u32	isize;			/* L1 i-cache size */
	u32	iline_size;		/* L1 i-cache line size	*/
	u32	log_iline_size;
	u32	ilines_per_page;
};

extern struct ppc64_caches ppc64_caches;
#endif /* __powerpc64__ && ! __ASSEMBLY__ */

#if !defined(__ASSEMBLY__)

#define __read_mostly __attribute__((__section__(".data..read_mostly")))

#ifdef CONFIG_6xx
extern long _get_L2CR(void);
extern long _get_L3CR(void);
extern void _set_L2CR(unsigned long);
extern void _set_L3CR(unsigned long);
#else
#define _get_L2CR()	0L
#define _get_L3CR()	0L
#define _set_L2CR(val)	do { } while(0)
#define _set_L3CR(val)	do { } while(0)
#endif

extern void cacheable_memzero(void *p, unsigned int nb);
extern void *cacheable_memcpy(void *, const void *, unsigned int);

#endif /* !__ASSEMBLY__ */
#endif /* __KERNEL__ */
#endif /* _ASM_POWERPC_CACHE_H */