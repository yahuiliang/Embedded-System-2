/*
 * uart_driver.c
 *
 *  Created on: Nov 8, 2016
 *      Author: barnekow
 */
#include "uart_driver.h"
#include <inttypes.h>
#include <stdio.h>
#include "ringbuffer.h"

static volatile RingBuffer sendBuffer = {0, 0};

char usart2_getch() {
    char c;
    c = get(&sendBuffer);  // Read character from usart
    usart2_putch(c);  // Echo back

    if (c == '\r') {  // If character is CR
        usart2_putch('\n');  // send it
        c = '\n';   // Return LF. fgets is terminated by LF
    }

    return c;
}

void usart2_putch(char c) {
    put(&sendBuffer, c);
}

void init_usart2(uint32_t baud, uint32_t sysclk) {
    // Enable clocks for GPIOA and USART2
    *(RCC_AHB1ENR ) |= (1 << GPIOAEN);
    *(RCC_APB1ENR ) |= (1 << USART2EN);

    // Function 7 of PORTA pins is USART
    *(GPIOA_AFRL ) &= (0xFFFF00FF); // Clear the bits associated with PA3 and PA2
    *(GPIOA_AFRL ) |= (0b01110111 << 8); // Choose function 7 for both PA3 and PA2
    *(GPIOA_MODER ) &= (0xFFFFFF0F);  // Clear mode bits for PA3 and PA2
    *(GPIOA_MODER ) |= (0b1010 << 4);  // Both PA3 and PA2 in alt function mode

    // set global interrupt in NVIC.
    *ISER1 |= 1 << USART2_INTERRUPT;

    // Set up USART2
    //USART2_init();  //8n1 no flow control
    // over8 = 0..oversample by 16
    // M = 0..1 start bit, data size is 8, 1 stop bit
    // PCE= 0..Parity check not enabled
    // using interrupts here.
    *(USART_CR1 ) |= (1 << TXEIE | 1 << RXNEIE); // Enable receive and transmit interrupts.
    *(USART_CR1 ) = (1 << UE) | (1 << TE) | (1 << RE); // Enable UART, Tx and Rx
    *(USART_CR2 ) = 0;  // This is the default, but do it anyway
    *(USART_CR3 ) = 0;  // This is the default, but do it anyway
    *(USART_BRR ) = sysclk / baud;

    /* I'm not sure if this is needed for standard IO*/
    //setvbuf(stderr, NULL, _IONBF, 0);
    //setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
}

void USART2_IRQHandler(void) {
    *USART_CR1 |= (1 << TXEIE | 1 << RXNEIE);
    if (*USART_SR & (1 << TXE)) {
        int8_t character = get(&sendBuffer);
        if (character == -1) {
            *USART_CR1 &= ~(1 << TXEIE);
        } else {
            *USART_DR = character;
        }
    } else if (*USART_SR & (1 << RXNE)) {
        uint8_t character = *USART_DR;
        put(&sendBuffer, character);
        *USART_CR1 |= 1 << TXEIE;
    }
}

