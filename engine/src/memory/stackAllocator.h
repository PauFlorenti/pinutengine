#pragma once

#include <stdlib.h>

class StackAllocator
{
private:
    int stackPointer;
    void* data;
    size_t dataSize;
    size_t totalSize;

public:

    StackAllocator() {};
    ~StackAllocator() {};

    void init(const size_t size, const size_t nValues = 1);
    void destroy();
    void* allocate(size_t size);
    void freeAll();
};