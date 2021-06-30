
#include <string.h>
#include "CircularBuffer.h"

CircularBuffer::CircularBuffer() {
	// TODO Auto-generated constructor stub

}

CircularBuffer::~CircularBuffer() {
	// TODO Auto-generated destructor stub
}

void CircularBuffer::initializeBuffer() {
	memset(cbuffer.buffer, 0, sizeof(cbuffer.buffer));
	cbuffer.head = 0;
	cbuffer.tail = 0;
	cbuffer.size = 0;
	cbuffer.isFull = false;
}

bool CircularBuffer::addToBuffer(uint8_t data) {

	if (this->isBufferFull()){
		return false;
	}

	int currIndex = cbuffer.head;
	cbuffer.buffer[currIndex] = data;
	cbuffer.head =+ 1;
	cbuffer.size++;

	return true;
}

bool CircularBuffer::removeFromBuffer(uint8_t *data) {

	int currIndex = cbuffer.tail;
	*data = cbuffer.buffer[currIndex];
	cbuffer.tail =+ 1;
	cbuffer.size--;

	return true;
}

bool CircularBuffer::isBufferFull() {
	if (cbuffer.head + 1 == cbuffer.tail){
		cbuffer.isFull = true;
	}
	return cbuffer.isFull;
}

uint8_t CircularBuffer::getBufferSize() {
	return cbuffer.size;
}

void CircularBuffer::resetBuffer() {
	memset(cbuffer.buffer, 0, sizeof(cbuffer.buffer));
	cbuffer.head = 0;
	cbuffer.tail = 0;
	cbuffer.size = 0;
	cbuffer.isFull = false;
}

