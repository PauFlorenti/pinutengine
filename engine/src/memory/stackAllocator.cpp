#include "stackAllocator.h"
#include <iostream>
#include <cstring>

void StackAllocator::init(const size_t size, const size_t nValues)
{
    totalSize       = size * nValues;
    dataSize        = 0;
    data            = malloc(size * nValues);

    std::cout << "Stack Allocator has been initialized.\n";
    std::cout << "Allocated " << totalSize << " size at address: " << &data << std::endl;
}

void StackAllocator::destroy()
{
    free(data);
    std::cout << "Data has been freed.\n";
}

void* StackAllocator::allocate(size_t size)
{
    if( dataSize + size > totalSize ){
        size_t remaining = totalSize - dataSize;
        std::cout << "Linear allocator - Tried to allocated" << size << "B, only " << remaining << " remaining.\n";
        return 0;
    }

    std::cout << "There is enough space!" << std::endl;
    // Move pointer to begining of free memory.
    void* block = (int*)data + dataSize;
    dataSize += size;   // Update pointer
    std::cout << "Return block at position: " << block << std::endl;
    return block;
}


void StackAllocator::freeAll()
{
    if(data) {
        dataSize = 0;
        memset(data, 0, totalSize);
    }
}
