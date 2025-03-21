
#ifndef STD_ALLOC_H
#define STD_ALLOC_H
#include <stdint.h>
#include <stdlib.h>

// standard malloc/free allocator base allocator for future comparisons
typedef struct {
    void** ptrs;
    size_t count;
    size_t capacity;
} StandardAllocator;

void std_init(StandardAllocator* allocator, size_t capacity);
void* std_alloc(StandardAllocator* allocator, size_t size);
void std_reset(StandardAllocator* allocator);

#endif // STD_ALLOC_H
