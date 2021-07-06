#ifndef ABSBUFFER_H_
#define ABSBUFFER_H_

class AbsBuffer {

public:
	virtual bool addToBuffer(int data) = 0;
	virtual bool removeFromBuffer(int *data) = 0;
	virtual bool isBufferFull() = 0;
	virtual int getFilledBufferSize() = 0;
	virtual ~AbsBuffer();
};

#endif /* ABSBUFFER_H_ */
