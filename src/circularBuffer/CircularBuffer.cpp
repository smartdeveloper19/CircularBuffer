
#include <string.h>
#include <iostream>
#include "CircularBuffer.h"

CircularBuffer::CircularBuffer() {
	memset(buffer, 0, sizeof(buffer));
	head = 0;
	tail = 0;
	byteCounter = 0;
}

CircularBuffer::~CircularBuffer() {
	memset(buffer, 0, sizeof(buffer));
	head = 0;
	tail = 0;
	byteCounter = 0;
}

bool CircularBuffer::addToBuffer(int data) {

	if (getFreeBytesSize() == 0) {
		return false;
	}

	if (head == BUFFER_SIZE) {
		head = 0;
	}

	int currHead = head;
	buffer[currHead] = data;
	head = head + 1;
//	head = (head + 1) % BUFFER_SIZE;
	byteCounter++;
#ifdef _DEBUG_
	std::cout<<"Add: head: "<<head<<" tail: "<<tail<<std::endl;
#endif

	return true;
}

bool CircularBuffer::removeFromBuffer(int *data) {

	if (!getFilledBufferSize()) {
		return false; // no data available
	}

	if (tail == BUFFER_SIZE) {
		tail = 0;
	}
//	tail = tail % BUFFER_SIZE;

	int currTail = tail;
	*data = buffer[currTail];
//	tail = (tail + 1) % BUFFER_SIZE;
	tail = tail + 1;

	byteCounter--;
#ifdef _DEBUG_
	std::cout<<"Removed: head: "<<head<<" tail: "<<tail<<std::endl;
#endif
	return true;
}

int CircularBuffer::getFreeBytesSize() {

	int freeBufferSize = 0;
	if (tail == 0 && head == BUFFER_SIZE) {
		freeBufferSize = 0;
	}
	else if (tail == head && byteCounter == 0) {
		freeBufferSize =  BUFFER_SIZE;
	}
	else if (head > tail) { // H > T
		freeBufferSize=  (BUFFER_SIZE - head + tail);
	}
	else if (head < tail) { // H < T
		freeBufferSize =  (tail - head);
	}
#ifdef _DEBUG_
	std::cout<<"Free size: "<<freeBufferSize<<std::endl;
#endif
	return freeBufferSize;
}

bool CircularBuffer::isBufferFull() {
	return (this->getFreeBytesSize() == 0 ? true : false);
}

int CircularBuffer::getFilledBufferSize() {
	int numberOfByteInBuffer = BUFFER_SIZE - this->getFreeBytesSize();
#ifdef _DEBUG_
	std::cout<<"Bytes in buffer: "<<numberOfByteInBuffer<<std::endl;
#endif
	return numberOfByteInBuffer;
}
