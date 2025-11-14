# C++ Generic Vector Implementation

A C++ implementation of a generic vector class (similar to `std::vector`) with template support for multiple data types. This project was created as part of CMPSC 122 coursework at Penn State University.

## Overview

This repository contains implementations of a basic dynamically-resizing vector class that supports various data types through C++ templates. The project includes an interactive command-line interface for testing and demonstrating vector operations.

## Files

- **generic_vector.cpp** - Generic template-based vector implementation with interactive CLI (by Michael Melusky)
- **generic_vectorerr.cpp** - Alternative generic vector implementation with error handling (by Michael Melusky)
- **integer_vector.cpp** - Integer-specific vector implementation (by Robert Bennethum IV)
- **main.cpp** - Simple "Hello, World!" program
- **CMakeLists.txt** - CMake build configuration
- **cmpsc122_homework3.pdf** - Assignment specification document

## Features

The `BasicVector` class provides the following functionality:

### Data Type Support
- Integer (`int`)
- Floating point (`float`)
- Double precision (`double`)
- String (`string`)
- Boolean (`bool`)

### Vector Operations
- `at(index)` - Access element at specified index with bounds checking
- `operator[]` - Access element at specified index
- `front()` - Access first element
- `back()` - Access last element
- `push_back(value)` - Add element to end of vector
- `pop_back()` - Remove last element
- `insert(index, value)` - Insert element at specified position
- `size()` - Get current number of elements
- `capacity()` - Get current capacity
- `print()` - Display all elements

### Dynamic Memory Management
- Automatic resizing when capacity is reached
- Capacity grows by powers of 2 for efficiency
- Proper memory cleanup through destructor

## Building

### Using CMake

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

### Using g++ directly

```bash
# Compile generic vector implementation
g++ -std=c++14 -o vector_demo generic_vector.cpp

# Compile integer vector implementation
g++ -std=c++14 -o int_vector integer_vector.cpp
```

## Usage

Run the compiled program:

```bash
./vector_demo
```

The program will prompt you to:
1. Select a data type to store in the vector
2. Specify initial capacity
3. Enter commands to manipulate the vector

### Available Commands

```
at <index>           - Get element at index
get <index>          - Get element using [] operator
front                - Get first element
back                 - Get last element
insert <index> <val> - Insert value at index
push <value>         - Add value to end
pop                  - Remove last element
size                 - Display current size
capacity             - Display current capacity
print                - Display all elements
quit                 - Exit program
```

### Example Session

```
Specify what data type to store in vector:
     1) int
     2) float
     3) double
     4) string
     5) bool
1
Specify initial capacity: 4
Now accepting commands (quit to exit program):
push 10
push 20
push 30
print
size
capacity
quit
```

## Implementation Details

The vector uses dynamic array allocation with the following characteristics:
- Initial capacity is user-specified
- When full, capacity doubles to the next power of 2
- Memory is managed using `new` and `delete` for arrays
- Bounds checking is performed for `at()` method
- Template support allows type-safe generic implementation

## Authors

- Robert Bennethum IV (rmb6287@psu.edu)
- Michael Melusky (mcm297@psu.edu)

## Course Information

- **Course**: CMPSC 122 (Introduction to Computer Science II)
- **Institution**: Penn State University
- **Assignment**: Program 3.2
- **Due Date**: March 19, 2020

## License

This is academic coursework. Please respect academic integrity policies if you're a student.
