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

	int ch_arr[ARSIZE],count1;
	int count2, stop, lastchar;

	lastchar = 0;
	stop = 0;
	/*
	* Read characters into array.
	* Stop if end of line, or array full.
	*/
	while(stop != 1){
		int character = getchar();
		ch_arr[lastchar] = character;
		if(ch_arr[lastchar] == '\n')
			stop = 1;
		else
			lastchar = lastchar + 1;
		if(lastchar == ARSIZE)
			stop = 1;
	}
	lastchar = lastchar-1;

	/*
	 * Now the traditional bubble sort.
	 */
	count1 = 0;
	while(count1 < lastchar){
		count2 = count1 + 1;
		while(count2 <= lastchar){
			if(ch_arr[count1] > ch_arr[count2]){
				/* swap */
				int temp;
				temp = ch_arr[count1];
				ch_arr[count1] = ch_arr[count2];
				ch_arr[count2] = temp;
			}
			count2 = count2 + 1;
		}
		count1 = count1 + 1;
	}

	count1 = 0;

	while(count1 <= lastchar){
		printf("%c\n", ch_arr[count1]);
		count1 = count1 + 1;
	}

	exit(EXIT_SUCCESS);

	return 0;
}

