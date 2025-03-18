#include "bump_alloc.h"

void bump_up_init(bumpAllocator* allocator, void* memory, size_t size) {
    allocator->start = (char*)memory;
    allocator->curr = (char*)memory;
    allocator->end = allocator->start + size;
}

void* bump_up_alloc(bumpAllocator* allocator, size_t size) {
    if(allocator->curr + size > allocator->end) { 
        return NULL;
    }
    // save curr position as result
    void* res = allocator->curr;

    // bump pointer
    allocator->curr+= size;
    return res;
}

void bump_up_free(bumpAllocator* allocator) {
    allocator->curr = allocator->start;
}

void bump_down_init(bumpAllocator* allocator, void* memory, size_t size) {
    allocator->start = (char*)memory;
    allocator->curr = allocator->start + size;
    allocator->end = allocator->curr;
}


void* bump_down_alloc(bumpAllocator* allocator, size_t size) {
    if(allocator->curr - size < allocator->start) {
        return NULL;
    }
    allocator->curr -= size;
    return allocator->curr;
}

void bump_down_free(bumpAllocator* allocator) {
    allocator->curr = allocator->end;
}


