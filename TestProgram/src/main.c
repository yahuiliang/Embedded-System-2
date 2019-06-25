/*
 * main.c
 *
 *  Created on: Nov 7, 2016
 *      Author: barnekow
 */
#include <stdio.h>
#include "uart_driver.h"
#include <stdlib.h>

#define ARSIZE 10
#define F_CPU 16000000UL

// main
int main(void){
	init_usart2(19200,F_CPU);
	printf("Hello World!!\n");
	printf("Hello World!!\n");
	printf("Hello World!!\n");

	// never return
	for(;;){}

	return 0;
}

