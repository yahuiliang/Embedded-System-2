/*
 * ringbuffer.h
 *
 *  Created on: Jan 29, 2017
 *      Author: Yahui Liang
 */

#ifndef RINGBUFFER_H_
#define RINGBUFFER_H_

#define BUF_SIZE 50

typedef struct {
    unsigned int put;
    unsigned int get;
    char buffer[BUF_SIZE];
} RingBuffer;

void put(RingBuffer* buffer, char element);
char get(RingBuffer* buffer);
int hasSpace(RingBuffer* buffer);
int hasElement(RingBuffer* buffer);

#endif /* RINGBUFFER_H_ */
