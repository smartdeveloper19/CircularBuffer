#ifndef ABSBUFFER_H_
#define ABSBUFFER_H_

#include <stdint.h>
class AbsBuffer {

public:
	virtual void initializeBuffer() = 0;
	virtual bool addToBuffer(uint8_t data) = 0;
	virtual bool removeFromBuffer(uint8_t *data) = 0;
	virtual bool isBufferFull() = 0;
	virtual uint8_t getFilledBufferSize() = 0;
	virtual void resetBuffer() = 0;
	virtual ~AbsBuffer();
};

#endif /* ABSBUFFER_H_ */
