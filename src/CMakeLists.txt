cmake_minimum_required(VERSION 3.10)
project(MyCppProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Download and include Google Test
include(FetchContent)
FetchContent_Declare(
    gtest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.0  # Specify the version you want
)
FetchContent_MakeAvailable(gtest)

# Include directories
include_directories(include)
# Include Google Test headers
include_directories(${gtest_SOURCE_DIR}/include)

# Set the source directory for circularBuffer
set(CIRCULAR_BUFFER_DIR src/circularBuffer)

# Collect all source files in the circularBuffer directory
file(GLOB SOURCES "${CIRCULAR_BUFFER_DIR}/*.cpp")

# Add the tests
set(TEST_SOURCES
    circularBuffer/main.cpp
)

add_executable(my_tests circularBuffer/main.cpp)

# Define UNIT_TESTING for the test executable
target_compile_definitions(my_tests PRIVATE UNIT_TESTING)

# Link Google Test to the test executable
target_link_libraries(my_tests gtest gtest_main)

# Enable testing
enable_testing()
add_test(NAME MyTests COMMAND my_tests)