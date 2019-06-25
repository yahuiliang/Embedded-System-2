/*
 * CE2812 - 021
 * Winter 2016
 * Name: Yahui Liang
 */

#ifndef REG_STRUCT_H_
#define REG_STRUCT_H_

#include <inttypes.h>

/* GPIO structure */
typedef struct {
	uint32_t MODER;
	uint32_t OTYPER;
	uint32_t OSPEEDR;
	uint32_t PUPDR;
	uint32_t IDR;
	uint32_t ODR;
	uint32_t BSRR;
	uint32_t LCKR;
	uint32_t AFRL;
	uint32_t AFRH;
} GPIOx;

/* SYSTICK structure */
typedef struct {
	uint32_t STK_CTRL;
	uint32_t STK_LOAD;
	uint32_t STK_VAL;
	const uint32_t CALIB;
} SYSTICK;

#endif /* REG_STRUCT_H_ */
