#ifdef UNIT_TESTING

#include "CircularBuffer.h"
#include "gtest.h"

TEST(test_circular_buffer, test_add_and_remove_from_circular_buffer)
{
	uint8_t valueFromBuffer = 0;
	CircularBuffer circularBuffer;
	circularBuffer.initializeBuffer();

	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		ASSERT_TRUE(circularBuffer.addToBuffer(i));
	}
	ASSERT_TRUE(circularBuffer.isBufferFull());

	ASSERT_FALSE(circularBuffer.addToBuffer(5)); // should not add to buffer
	ASSERT_EQ(circularBuffer.getFilledBufferSize(), BUFFER_SIZE);

	ASSERT_TRUE(circularBuffer.removeFromBuffer(&valueFromBuffer));
	ASSERT_TRUE(circularBuffer.removeFromBuffer(&valueFromBuffer));

	ASSERT_EQ(circularBuffer.getFilledBufferSize(), 3);
	ASSERT_FALSE(circularBuffer.isBufferFull());

	ASSERT_TRUE(circularBuffer.addToBuffer(5));
	ASSERT_TRUE(circularBuffer.addToBuffer(5));

	ASSERT_EQ(circularBuffer.getFilledBufferSize(), BUFFER_SIZE);
	ASSERT_TRUE(circularBuffer.isBufferFull());

	ASSERT_TRUE(circularBuffer.removeFromBuffer(&valueFromBuffer));
	ASSERT_TRUE(circularBuffer.removeFromBuffer(&valueFromBuffer));

	ASSERT_FALSE(circularBuffer.isBufferFull());
}

TEST(test_circular_buffer, test_circular_buffer_full)
{
	uint8_t bufferSize = BUFFER_SIZE;
	uint8_t valueFromBuffer = 0;

	CircularBuffer circularBuffer;
	circularBuffer.initializeBuffer();
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		ASSERT_TRUE(circularBuffer.addToBuffer(i));
	}

//	for (int i = 0; i < BUFFER_SIZE; i++)
//	{
//		ASSERT_TRUE(circularBuffer.removeFromBuffer(&valueFromBuffer));
//		ASSERT_EQ(valueFromBuffer, i);
//	}


//	ASSERT_EQ(circularBuffer.getBufferSize(), bufferSize);
//	ASSERT_TRUE(circularBuffer.isBufferFull());
//
//	ASSERT_TRUE(circularBuffer.removeFromBuffer(&valueFromBuffer));
//	ASSERT_TRUE(circularBuffer.removeFromBuffer(&valueFromBuffer));
//
//	ASSERT_FALSE(circularBuffer.isBufferFull()); // buffer should not full
//
//	ASSERT_TRUE(circularBuffer.addToBuffer(5));
//	ASSERT_TRUE(circularBuffer.addToBuffer(6));
//
//	ASSERT_EQ(circularBuffer.getBufferSize(), bufferSize);
//	ASSERT_TRUE(circularBuffer.isBufferFull()); // buffer should be full
}

#endif

