#ifndef FLASH_HPP
#define FLASH_HPP

#include <nbavr.hpp>

template <class ledPin>
struct Flash : Task {
    bool intOccurred = false;

    Flash() {
        ledPin::direction(Direction::Output);
    }

    void loop(Clock& clock) override {
        if(intOccurred) {
            intOccurred = false;

            delay(clock, MS_TO_TICKS(500));
        } else {
            ledPin::output(Value::High);

            clock.addInterrupt(interrupt, this, MS_TO_TICKS(50));

            sleep();
        }
    }

    static void interrupt(void* data) {
        Flash* self = reinterpret_cast<Flash*>(data);

        ledPin::output(Value::Low);

        self->intOccurred = true;
        self->wake();
    }
};

#endif
