#include "bump_alloc.h"

void bump_init(bump_allocator* allocator, void* memory, size_t size) {
    allocator->start = (char*)memory;
    allocator->curr = (char*)memory;
    allocator->end = allocator->start + size;
}

void* bump_alloc(bump_allocator* allocator, size_t size) {
    if(allocator->curr + size > allocator->end) { 
        return NULL;
    }
    // save curr position as result
    void* res = allocator->curr;

    // bump pointer
    allocator->curr+= size;
    return res;
}

void bump_reset(bump_allocator* allocator) {
    allocator->curr = allocator->start;
}



