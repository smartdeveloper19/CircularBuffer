//============================================================================
// Name        : circularBuffer.cpp
// Author      : Muahid Abbas
// Version     :
// Copyright   : 
// Description : main function for the unit testing using gtests
//============================================================================

#ifdef UNIT_TESTING
#include <gtest/gtest.h>

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    //::testing::FLAGS_gtest_filter = "test_Filter*";
    return RUN_ALL_TESTS();
}
#else
#include <iostream>
using namespace std;

int main() {
	cout << "Hello" << endl; // prints Hello
	return 0;
}
#endif
