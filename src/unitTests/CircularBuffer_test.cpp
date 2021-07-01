#ifdef UNIT_TESTING

#include "CircularBuffer.h"
#include "gtest.h"


TEST(test_circular_buffer, test_add_and_remove_from_circular_buffer_)
{
	uint8_t valueFromBuffer = 0;
	CircularBuffer circularBuffer;
	circularBuffer.initializeBuffer();
	ASSERT_TRUE(circularBuffer.addToBuffer(5));
	ASSERT_TRUE(circularBuffer.addToBuffer(6));
	ASSERT_EQ(circularBuffer.getBufferSize(), 2);
	ASSERT_TRUE(circularBuffer.removeFromBuffer(&valueFromBuffer));
	ASSERT_EQ(valueFromBuffer, 5);
	ASSERT_TRUE(circularBuffer.removeFromBuffer(&valueFromBuffer));
	ASSERT_EQ(valueFromBuffer, 6);
	ASSERT_EQ(circularBuffer.getBufferSize(), 0);
	ASSERT_FALSE(circularBuffer.isBufferFull());
}

TEST(test_circular_buffer, test_circular_buffer_full)
{
	uint8_t valueFromBuffer = 0;
	CircularBuffer circularBuffer;
	circularBuffer.initializeBuffer();
	for (int i=0; i < BuffER_SIZE; i++)
	{
	 ASSERT_TRUE(circularBuffer.addToBuffer(i));
	}
	ASSERT_EQ(circularBuffer.getBufferSize(), 20);
	ASSERT_TRUE(circularBuffer.isBufferFull());
}

#endif

