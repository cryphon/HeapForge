#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <time.h>

typedef struct {
    clock_t start;
    clock_t end;
    const char* name;
} Timer;

void start_timer(Timer* timer, const char* name);
void stop_timer(Timer* timer);
void print_timer(Timer* timer);

#endif

