
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

	if (getFreeBytesSize() == 0)
	{
		return false;
	}

	if (cbuffer.head == BUFFER_SIZE){
		cbuffer.head = 0;
	}

	int currHead = cbuffer.head;
	cbuffer.buffer[currHead] = data;
	cbuffer.head = cbuffer.head + 1;

	return true;
}

bool CircularBuffer::removeFromBuffer(uint8_t *data) {

	if (!getFilledBufferSize()) {
		return false; // no data available
	}

	if (cbuffer.tail == BUFFER_SIZE){
		cbuffer.tail = 0;
	}

	//cbuffer.tail = cbuffer.tail % BUFFER_SIZE;

	int currTail = cbuffer.tail;
	*data = cbuffer.buffer[currTail];

	cbuffer.tail = cbuffer.tail + 1;

	return true;
}

int CircularBuffer::getFreeBytesSize() {

	int freeBufferSize = 0;
	if (cbuffer.tail == 0 && cbuffer.head == BUFFER_SIZE) {
		freeBufferSize = 0;
	}
	else if (cbuffer.tail == cbuffer.head){
		freeBufferSize =  BUFFER_SIZE;
	}
	else if (cbuffer.head > cbuffer.tail){ // H > T
		freeBufferSize=  (BUFFER_SIZE - cbuffer.head + cbuffer.tail);
	}
	else if (cbuffer.head < cbuffer.tail){ // H < T
		freeBufferSize =  (cbuffer.tail - cbuffer.head);
	}

	printf("\nHead: %d Tail: %d\n", cbuffer.head, cbuffer.tail);
	printf("\nSize of Buffer: %d\n", freeBufferSize);
	return freeBufferSize;
}

bool CircularBuffer::isBufferFull() {
	return (this->getFreeBytesSize() == 0 ? true : false);
}

uint8_t CircularBuffer::getFilledBufferSize() {
	return (BUFFER_SIZE - this->getFreeBytesSize());
}

void CircularBuffer::resetBuffer() {
	memset(cbuffer.buffer, 0, sizeof(cbuffer.buffer));
	cbuffer.head = 0;
	cbuffer.tail = 0;
	cbuffer.isFull = false;
}

