#ifndef CIRCULARBUFFER_H_
#define CIRCULARBUFFER_H_

#include "AbsBuffer.h"
#include "defines.h"

class CircularBuffer:public AbsBuffer {

private:
	cBuffer_t cbuffer;
public:
	void initializeBuffer();
	bool addToBuffer(uint8_t data);
	bool removeFromBuffer(uint8_t *data);
	bool isBufferFull();
	uint8_t getBufferSize();
	void resetBuffer();
	~CircularBuffer();
	CircularBuffer();
};

#endif /* CIRCULARBUFFER_H_ */
