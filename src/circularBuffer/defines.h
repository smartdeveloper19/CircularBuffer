#ifndef DEFINES_H_
#define DEFINES_H_
#include <stdint.h>

#define BUFFER_SIZE 50

typedef struct {
    uint8_t buffer[BUFFER_SIZE];
    int head;
    int tail;
    bool isFull;
} cBuffer_t;


#endif /* DEFINES_H_ */
