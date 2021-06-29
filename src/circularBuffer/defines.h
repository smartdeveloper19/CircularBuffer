#ifndef DEFINES_H_
#define DEFINES_H_
#include <stdint.h>

#define PACKET_SIZE 10

typedef struct {
    uint8_t const packet[PACKET_SIZE];
    int head;
    int tail;
    bool isFull;
} buffer_t;


#endif /* DEFINES_H_ */
