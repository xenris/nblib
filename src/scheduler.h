#ifndef NBAVR_SCHEDULER_H
#define NBAVR_SCHEDULER_H

#include "kernel.h"

Task* getNextTask(void);
void setPriority(TaskPriority priority);

#endif