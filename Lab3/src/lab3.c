/*
 * CE2812 - 021
 * Winter 2016
 * Lab 3 - LCD API
 * Name: Yahui Liang
 * Created: 12/17/2016
 */

/* All header files */
#include "uart_driver.h"
#include "delay_api.h"
#include "lcd_api.h"
#include <stdio.h>

/**
 * The program is a count down timer which counts from 10.
 */
int main() {
	lcd_init();
	/* Show welcome message */
	lcd_print_string("Start");
	lcd_set_position(1, 3);
	lcd_print_string("Counter!");
	delay_ms(1000);
	lcd_clear();
	lcd_home();
	int time = 10;
	/* Counts down */
	for (int i = 0; i < 10; i++) {
		lcd_print_num(time);
		delay_ms(1000);
		lcd_clear();
		lcd_home();
		time--;
	}
	/* Show end message */
	lcd_print_string("Finished!");
	while(1); // infinite loop
	return 0;
}
