#include "bump_alloc.h"

void bump_up_init(bumpUpAllocator* allocator, void* memory, size_t size) {
    allocator->start = (char*)memory;
    allocator->curr = (char*)memory;
    allocator->end = allocator->start + size;
}

void* bump_up_alloc(bumpUpAllocator* allocator, size_t size) {
    if(allocator->curr + size > allocator->end) { 
        return NULL;
    }
    // save curr position as result
    void* res = allocator->curr;

    // bump pointer
    allocator->curr+= size;
    return res;
}

void bump_up_reset(bumpUpAllocator* allocator) {
    allocator->curr = allocator->start;
}



