/*
 * rotary_api.c
 *
 *  Created on: Feb 6, 2017
 *      Author: Yahui Liang
 */

#include "rotary_api.h"
#include "gpio_api.h"
#include <inttypes.h>
#include "tim2to5_api.h"

static void tim_init();

void rotary_init() {
    init_gpiox(0); // enable GPIOA
    set_gpio_pointer(GPIOA_BASE);
    set_to_input_mode(0); // sets channel A to alternate function mode.
    set_to_input_mode(1); // sets channel B to alternate function mode.
    tim_init();
}

static void tim_init() {
    init_timer2();
    set_timer_pointer(TIM2_BASE);
    set_to_encoder_interface_mode();
    set_arr(24);
    start_counter();
}
