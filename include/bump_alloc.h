#ifndef BUMP_ALLOC_H
#define BUMP_ALLOC_H
#include <stdint.h>
#include <stdlib.h>

#define BUMP_ALLOC_OK        0  // Success
#define BUMP_ALLOC_ENOMEM   -1  // Not enough memory
#define BUMP_ALLOC_EFULL    -2  // Allocator fully used
#define BUMP_ALLOC_EINVAL   -3  // Invalid request

typedef struct {
    char* start;    // start if memory region
    char* curr;     // cyrrent allocation position
    char* end;      // end of memory region
} bumpUpAllocator;

void bump_up_init(bumpUpAllocator* allocator, void* memory, size_t size);
void* bump_up_alloc(bumpUpAllocator* allocator, size_t size);
void bump_up_free(bumpUpAllocator* allocator, void* memory, size_t size);
#endif
