#ifndef DEFINES_H_
#define DEFINES_H_
#include <stdint.h>

#define BuffER_SIZE 20

typedef struct {
    uint8_t buffer[BuffER_SIZE];
    int head;
    int tail;
    int size;
    bool isFull;
} cBuffer_t;


#endif /* DEFINES_H_ */
