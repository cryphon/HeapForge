#ifndef UTILS_H
#define UTILS_H
#include <stdio.h>


void dump_memory(char* memory, size_t size, const char* title) {
    printf("\n--- Memory Dump: %s ---\n", title);
    printf("Address Range: %p to %p\n", (void*)memory, (void*)memory + size - 1);


    for(size_t i = 0; i < size; i+= 16) {
        // print addr
        printf("\n%p: ", (void*)(memory + i));

        // print hex values
        for(size_t j = 0; j < 16; j++) {
            if(i + j < size) {
                printf("%02x ", (unsigned char)memory[i + j]);
            }
            else {
                printf("    ");
            }
            // print extra space in the middle
            if( j == 7) {
                printf(" ");
            }
        }
    }
    printf("\n----------------------------------------------------------------\n");
}


#endif
