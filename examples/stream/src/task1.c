#include "task1.h"

static struct {
    uint32_t delay;
    uint16_t count;
} mData;

static void loop(Task* task);

Task task1 = {
    .data = &mData,
    .dataSize = sizeof(mData),
    .loop = loop,
};

static void loop(Task* task) {
    uint32_t millis = clockMillis();

    if(millis >= mData.delay) {
        print(task->outputStreams[0], "Task1 running (%i)\n", mData.count);
        mData.delay = millis + 1000;
        mData.count++;
    }

    uint8_t b;

    if(streamPop(task->inputStreams[0], &b)) {
        print(task->outputStreams[0], "Task1 received byte 0x%x\n", b);
    }
}
