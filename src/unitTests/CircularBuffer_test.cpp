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

	ASSERT_EQ(circularBuffer.getFilledBufferSize(), BUFFER_SIZE-2);
	ASSERT_FALSE(circularBuffer.isBufferFull());

	ASSERT_TRUE(circularBuffer.addToBuffer(5));
	ASSERT_TRUE(circularBuffer.addToBuffer(5));

	ASSERT_EQ(circularBuffer.getFilledBufferSize(), BUFFER_SIZE);
	ASSERT_TRUE(circularBuffer.isBufferFull());

	ASSERT_TRUE(circularBuffer.removeFromBuffer(&valueFromBuffer));
	ASSERT_TRUE(circularBuffer.removeFromBuffer(&valueFromBuffer));

	ASSERT_FALSE(circularBuffer.isBufferFull());
}

TEST(test_circular_buffer, test_circular_buffer_check_limit)
{
//	uint8_t valueFromBuffer = 0;
//
//	CircularBuffer circularBuffer;
//	circularBuffer.initializeBuffer();
//	for (int i = 0; i < BUFFER_SIZE-1; i++)
//	{
//		ASSERT_TRUE(circularBuffer.addToBuffer(i));
//	}
//
//	ASSERT_EQ(circularBuffer.getFilledBufferSize(), BUFFER_SIZE); // buffer should be of max size
//	ASSERT_FALSE(circularBuffer.addToBuffer(9)); // should not add more
//
//	for (int i = 0; i < BUFFER_SIZE-1; i++)
//	{
//		ASSERT_TRUE(circularBuffer.removeFromBuffer(&valueFromBuffer));
//		ASSERT_EQ(valueFromBuffer, i);
//	}
//
//	ASSERT_EQ(circularBuffer.getFilledBufferSize(), 0); // size should be zero
//	ASSERT_FALSE(circularBuffer.isBufferFull()); // should not full
//
//	ASSERT_FALSE(circularBuffer.removeFromBuffer(&valueFromBuffer)); // nothing to remove
//	ASSERT_FALSE(circularBuffer.removeFromBuffer(&valueFromBuffer)); // nothing to remove
//
//	ASSERT_TRUE(circularBuffer.addToBuffer(9)); // should add
//	ASSERT_TRUE(circularBuffer.removeFromBuffer(&valueFromBuffer));
//	ASSERT_EQ(valueFromBuffer, 9);
//	ASSERT_EQ(circularBuffer.getFilledBufferSize(), 1);
}

#endif

