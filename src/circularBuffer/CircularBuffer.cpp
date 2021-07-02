
#include <string.h>
#include <stdio.h>
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
	cbuffer.isFull = false;
}

bool CircularBuffer::addToBuffer(uint8_t data) {

	if (bufferBytesAvailable() == 0)
	{
		return false;
	}
	int currIndex = cbuffer.head;
	if (currIndex == BUFFER_SIZE){
		cbuffer.head = 0;
	}
	cbuffer.buffer[currIndex] = data;
	cbuffer.head = cbuffer.head + 1;

	return true;
}

bool CircularBuffer::removeFromBuffer(uint8_t *data) {

	if (cbuffer.head == cbuffer.tail) {
		return false; // no data available
	}

	int currIndex = cbuffer.tail;
	if (currIndex == BUFFER_SIZE){
		cbuffer.tail = 0;
	}
	*data = cbuffer.buffer[currIndex];
	cbuffer.tail = cbuffer.tail + 1;

	return true;
}

int CircularBuffer::bufferBytesAvailable() {

	int buffSize = 0;
	if (cbuffer.tail == 0 && cbuffer.head == BUFFER_SIZE) {
		buffSize = 0;
	}
	else if (cbuffer.tail == cbuffer.head){
		buffSize =  BUFFER_SIZE;
	}
	else if (cbuffer.head > cbuffer.tail){ // H > T
		buffSize=  (BUFFER_SIZE - cbuffer.head + cbuffer.tail);
	}
	else if (cbuffer.head < cbuffer.tail){ // H < T
		buffSize =  (cbuffer.tail - cbuffer.head);
	}

	printf("\nHead: %d Tail: %d\n", cbuffer.head, cbuffer.tail);
	printf("\nSize of Buffer: %d\n", buffSize);
	return buffSize;
}

bool CircularBuffer::isBufferFull() {

	return (this->bufferBytesAvailable() == 0 ? true : false);
}

uint8_t CircularBuffer::getFilledBufferSize() {
	return (BUFFER_SIZE - this->bufferBytesAvailable());
}

void CircularBuffer::resetBuffer() {
	memset(cbuffer.buffer, 0, sizeof(cbuffer.buffer));
	cbuffer.head = 0;
	cbuffer.tail = 0;
	cbuffer.isFull = false;
}

