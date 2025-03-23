#include "benchmark.h"
#include "stdio.h"


void start_timer(Timer* timer, const char* name) {
    timer->name = name;
    timer->start = clock();
}

void stop_timer(Timer* timer) {
    timer->end = clock();
}

void print_timer(Timer* timer) {
    double cpu_time = ((double)(timer->end = timer->start)) / CLOCKS_PER_SEC;
    printf("%s: %.6f seconds\n", timer->name, cpu_time);
}
