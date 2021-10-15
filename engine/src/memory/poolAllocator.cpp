#include "poolAllocator.h"

void* PoolAllocator::allocate(const size_t size)
{
    /**
     * No free blocks or no block at all yet
     * Allocate a new one, passing the chunk size.
     */
    if(m_alloc == nullptr)
        m_alloc = allocateBlock(size);

    // The return value is the current position of the
    // allocation pointer.
    Node *freeNode = m_alloc;

    // Advance the allocation pointer to the next Node
    // so it points to a free memory address.
    //
    // When no free Nodes left, the 'm_alloc' will be set
    // to nullptr and this will cause a new block to be
    // allocated.
    m_alloc = m_alloc->m_next;
    return freeNode;
}

/**
 * Puts the Node into the front of the list.
 */
void PoolAllocator::deallocate(void* ptr, size_t size)
{
    // The freed chunk's next pointer points to the
    // current allocation pointer:
    reinterpret_cast<Node*>(ptr)->m_next = m_alloc;

    // The allocation pointer is now set to the returned Node.
    m_alloc = reinterpret_cast<Node*>(ptr);
}

/**
 * Allocates a new block from OS.
 * 
 * Returns a Node to the beginning of the block.
 */
Node* PoolAllocator::allocateBlock(const size_t size)
{
    std::cout << "Allocating new block (" << m_chunksPerBlock << "):\n\n";

    size_t blockSize = m_chunksPerBlock * size;

    // First node of the new block.
    Node* nodeBegin = (Node*)(malloc(blockSize));

    // Once the block is allocated, we need to chain all nodes in the block.
    Node* node = nodeBegin;
    for(int i = 0; i < (int)(m_chunksPerBlock - 1); ++i)
    {
        node->m_next = (Node*)((char*)nodeBegin + size);
        node = node->m_next;
    }

    node->m_next = nullptr;
    return nodeBegin;
}