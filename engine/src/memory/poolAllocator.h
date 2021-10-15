#pragma once

#include <iostream>

/**
 * Node or Chunk is the memory containing the data
 */
struct Node
{
    /**
     * When a Node is free, the 'next' contains
     * the address of the next chunk in a list.
     * 
     * When it's allocated, this space is used by the user.
     */
    Node* m_next;
};

/**
 * Pool allocator class
 * 
 * Features:
 * 
 *  - Parametrized by number of chunks per block.
 *  - Keeps track of the allocation pointer.
 *  - Requests a new larger block when needed.
 */

class PoolAllocator
{
private:
    size_t m_chunksPerBlock;  // Number of nodes or chuncks per block
    Node* m_alloc = nullptr;

public:
    PoolAllocator(size_t chunksPerBlock)
        : m_chunksPerBlock(chunksPerBlock) {}
        
    void* allocate(const size_t size);
    void deallocate(void *ptr, size_t size);

private:
    Node* allocateBlock(const size_t size);
};