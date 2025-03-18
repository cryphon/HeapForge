#include "allocators.h"
#include "utils.h"
#include <stdio.h>
#include <assert.h>

int main() {
    printf("Testing allocators...\n");
    
    const size_t POOL_SIZE = 1024;
    char* mem_pool = (char*)malloc(POOL_SIZE);
    
    if(!mem_pool) {
       printf("Failed to allocate memory pool\n");
       return -1;
    }


    printf("Test 1: Basic Bump-Up Allocation\n");
    {
        // init allocator
        bumpAllocator alloc;
        bump_up_init(&alloc, mem_pool, POOL_SIZE);
        // allocate 4 bytes (int)
        int* int_ptr = (int*)bump_up_alloc(&alloc, sizeof(int));
        assert(int_ptr != NULL);
        *int_ptr = 42;

        // allocate 4 bytes (float)
        float* float_ptr = (float*)bump_up_alloc(&alloc, sizeof(float));
        assert(float_ptr != NULL);
        *float_ptr = 3.14f;

        // verify
        assert(*int_ptr == 42);
        assert(*float_ptr == 3.14f);

        // verify allocation positions
        assert((char*)int_ptr == mem_pool);
        assert((char*)float_ptr > (char*)int_ptr);

        printf("    Passed!\n");
    }



    printf("Test 2: Bump-Up Out Memory\n");
    {        
        // init allocator
        bumpAllocator alloc;
        bump_up_init(&alloc, mem_pool, POOL_SIZE);


        // try to allocate more memory than available
        void* res = bump_up_alloc(&alloc, POOL_SIZE + 1);
        assert(res == NULL);

        // allocate something that should fit
        res = bump_up_alloc(&alloc, POOL_SIZE / 2);
        assert(res != NULL);

        // allocate something that does not fit
        res = bump_up_alloc(&alloc, POOL_SIZE / 2 + 1);
        assert(res == NULL);

        printf("    Passed!\n");
    }

    // dump bump-up region
    dump_memory(mem_pool, POOL_SIZE, "(Bump-Up Region)");


    printf("Test 3: Basic Bump-Down Allocation\n");
    {
        // init allocator
        bumpAllocator alloc;
        bump_down_init(&alloc, mem_pool, POOL_SIZE);
        // allocate 4 bytes (int)
        int* int_ptr = (int*)bump_down_alloc(&alloc, sizeof(int));
        assert(int_ptr != NULL);
        *int_ptr = 42;

        // allocate 4 bytes (float)
        float* float_ptr = (float*)bump_down_alloc(&alloc, sizeof(float));
        assert(float_ptr != NULL);
        *float_ptr = 3.14f;

        // verify
        assert(*int_ptr == 42);
        assert(*float_ptr == 3.14f);

        printf("    Passed!\n");
    }

    dump_memory(mem_pool, POOL_SIZE, "(Bump-Down Region)");
    return 0;
}
