#ifndef NBAVR_TIMING_H
#define NBAVR_TIMING_H

// The timing module provides:
// - Two counters: milliseconds and microseconds.
// - A time based interrupt system where a function can be reqested to be run
//  once at a specific time between ~10 and 65535 microseconds with an accuracy
//  of 4us at 16MHz
// - A system for delaying a task loop for between 1 and 65535 milliseconds.
// - A task timeout which calls kernel.haltjmp when a task takes longer than
//  TASK_TIMEOUT milliseconds.
// Timer/Counter1 is used to provide all time based functions.

#include <stddef.h>
#include "hardware.h"
#include "kernel.h"
#include "microint.h"

void timingSetup();
bool addInterrupt(void (*function)(int), int code, uint16_t us);
uint32_t getMillis();
uint32_t getMicros();
void delayMillis(uint16_t ms);
void delaySeconds(uint16_t s);

#endif
