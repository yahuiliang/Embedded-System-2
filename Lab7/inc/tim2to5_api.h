/*
 * tim2to5_api.h
 *
 *  Created on: Jan 17, 2017
 *      Author: liangy
 */

#ifndef TIM2TO5_API_H_
#define TIM2TO5_API_H_

#define RCC_APB1ENR 0x40023840
#define TIM3_BASE 0x40000400

/* The structure for TIMER2 to 5 */
typedef struct {
    uint32_t CR1;
    uint32_t CR2;
    uint32_t SMCR;
    uint32_t DIER;
    uint32_t SR;
    uint32_t EGR;
    uint32_t CCMR1;
    uint32_t CCMR2;
    uint32_t CCER;
    uint32_t CNT;
    uint32_t PSC;
    uint32_t ARR;
    uint32_t reserved1;
    uint32_t CCR1;
    uint32_t CCR2;
    uint32_t CCR3;
    uint32_t CCR4;
    uint32_t reserved2;
    uint32_t DCR;
    uint32_t DMAR;
} TIMER2to5;

/**
 * Sets the internal timer pointer.
 * Args:
 * timer_base: the base address of the timer.
 */
void set_timer_pointer(uint32_t);

/**
 * Configure the clock for the timer 3.
 */
void init_timer3();

/**
 * Sets the value in CCR1.
 * Args:
 * ticks: the number of ticks needs to be set in CCR1.
 */
void set_ccr1(uint32_t);

/**
 * Sets the value in ARR.
 * Args:
 * ticks: the number of ticks needs to be set in ARR.
 */
void set_arr(uint32_t);

/**
 * Sets the timer into output compare mode.
 */
void set_to_output_cmp_mode();

/**
 * Starts counting.
 */
void start_counter();

/**
 * Stops counting.
 */
void stop_counter();

/**
 * Enables the output of the timer.
 */
void enable_output();

/**
 * Disable the output of the timer.
 */
void disable_output();

#endif /* TIM2TO5_API_H_ */
