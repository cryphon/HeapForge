#ifndef BUMP_ALLOC_H
#define BUMP_ALLOC_H
#include <stdint.h>

#define BUMP_ALLOC_OK        0  // Success
#define BUMP_ALLOC_ENOMEM   -1  // Not enough memory
#define BUMP_ALLOC_EFULL    -2  // Allocator fully used
#define BUMP_ALLOC_EINVAL   -3  // Invalid request

#endif
