#ifndef NBAVR_H
#define NBAVR_H

#include "hardware.h"
#include "kernel.h"
#include "print.h"
#include "scheduler.h"
#include "serial.h"
#include "stream.h"
#include "task.h"
#include "timing.h"
#include "twi.h"
#include "yield.h"

void nbavr(Task** tasks);

#endif