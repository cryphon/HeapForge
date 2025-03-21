#include "std_alloc.h"


void std_init(StandardAllocator* allocator, size_t capacity) {
    allocator->ptrs = (void**)malloc(capacity* sizeof(void));
    allocator->count = 0;
    allocator->capacity = capacity;
}

void* std_alloc(StandardAllocator* allocator, size_t size) {
    if(allocator->count >= allocator->capacity) {
        return NULL;
    }

    void* ptr = malloc(size);
    if(ptr) {
        allocator->ptrs[allocator->count++] = ptr;
    }
    return ptr;
}

void std_reset(StandardAllocator* allocator) {
    for(size_t i = 0; i < allocator->count; i++) {
        free(allocator->ptrs[i]);
    }
    allocator->count = 0;
}

