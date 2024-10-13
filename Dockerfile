# Use an official C++ compiler image
FROM gcc:latest

# Set the working directory in the container
WORKDIR /app

# Install CMake and git
RUN apt-get update && apt-get install -y cmake git

# Copy the entire project into the container
COPY . .

# Create a build directory, run cmake, and make all in one RUN statement
RUN mkdir build && \
    cd build && \
    cmake ../src && \
    make && \
    ls -l

# Change permissions for the test executable if needed
RUN chmod +x ./build/my_tests  # Adjust according to the actual name if necessary

# Set the entry point to the test executable
CMD ["./build/my_tests"]  # Adjust if your executable has a different name