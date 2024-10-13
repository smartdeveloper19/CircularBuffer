#ifndef CIRCULARBUFFER_H_
#define CIRCULARBUFFER_H_

#include "AbsBuffer.h"

#define BUFFER_SIZE 5

class CircularBuffer:public AbsBuffer {

private:
    int buffer[BUFFER_SIZE];
    int head;
    int tail;
    int byteCounter = 0;

	int getFreeBytesSize();
public:
	bool addToBuffer(int data);
	bool removeFromBuffer(int *data);
	bool isBufferFull();
	int getFilledBufferSize();
	~CircularBuffer();
	CircularBuffer();
};

#endif /* CIRCULARBUFFER_H_ */
