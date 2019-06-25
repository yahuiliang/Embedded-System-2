/*
 * ringbuffer.c
 *
 *  Created on: Jan 29, 2017
 *      Author: Yahui Liang
 */

#include "ringbuffer.h"

void put(RingBuffer* buffer, char element) {
    if (hasSpace(buffer)) {
        buffer->buffer[buffer->put] = element;
        buffer->put++;
        if (buffer->put > BUF_SIZE - 1) {
            buffer->put = 0;
        }
    }
}

char get(RingBuffer* buffer) {
    char element;
    if (hasElement(buffer)) {
        element = buffer->buffer[buffer->get];
        buffer->get++;
        if (buffer->get > BUF_SIZE - 1) {
            buffer->get = 0;
        }
    } else {
        element = -1;
    }
    return element;
}

int hasSpace(RingBuffer* buffer) {
    int hasSpace;
    if ((buffer->get - buffer->put) == 1 || (buffer->put == BUF_SIZE - 1 && buffer->get == 0)) {
        hasSpace = 0;
    } else {
        hasSpace = 1;
    }
    return hasSpace;
}

int hasElement(RingBuffer* buffer) {
    int hasElement;
    if ((buffer->put - buffer->get) == 0) {
        hasElement = 0;
    } else {
        hasElement = 1;
    }
    return hasElement;
}
