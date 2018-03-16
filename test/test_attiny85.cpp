#define __attiny85__

#define RECORD_ID "attiny85"

#include "test.hpp"

typedef void (*ft)(void*);

static ft func = (ft)0x1234;
static void* data = (void*)0x5678;

//------------------------------------------------
// Analog to Digital

INCLUDE_ADC_CALLBACK(0);

TEST(Adc0, getHardwareType) {
    ASSERT_EQ(Adc0::getHardwareType(), HardwareType::adc);
}

TEST(Adc0, enable) {
    TEST_REG_WRITE(Adc0::enable(true));
    TEST_REG_WRITE(Adc0::enable(false));
}

TEST(Adc0, start) {
    TEST_REG_WRITE(Adc0::start());
}

TEST(Adc0, value) {
    TEST_REG_READ_WRITE(Adc0::value());
}

TEST(Adc0, reference) {
    TEST_REG_WRITE(Adc0::reference(Adc0::Reference::aref));
    TEST_REG_WRITE(Adc0::reference(Adc0::Reference::avcc));
    TEST_REG_WRITE(Adc0::reference(Adc0::Reference::internal_1_1));
    TEST_REG_WRITE(Adc0::reference(Adc0::Reference::internal_2_56));
    TEST_REG_WRITE(Adc0::reference(Adc0::Reference::internal_2_56_cap));
}

TEST(Adc0, channel) {
    TEST_REG_WRITE(Adc0::channel(Adc0::Channel::adc0));
    TEST_REG_WRITE(Adc0::channel(Adc0::Channel::adc1));
    TEST_REG_WRITE(Adc0::channel(Adc0::Channel::adc2));
    TEST_REG_WRITE(Adc0::channel(Adc0::Channel::adc3));
    TEST_REG_WRITE(Adc0::channel(Adc0::Channel::vbg));
    TEST_REG_WRITE(Adc0::channel(Adc0::Channel::gnd));
}

TEST(Adc0, prescaler) {
    TEST_REG_WRITE(Adc0::prescaler(Adc0::Prescaler::div2));
    TEST_REG_WRITE(Adc0::prescaler(Adc0::Prescaler::div4));
    TEST_REG_WRITE(Adc0::prescaler(Adc0::Prescaler::div8));
    TEST_REG_WRITE(Adc0::prescaler(Adc0::Prescaler::div16));
    TEST_REG_WRITE(Adc0::prescaler(Adc0::Prescaler::div32));
    TEST_REG_WRITE(Adc0::prescaler(Adc0::Prescaler::div64));
    TEST_REG_WRITE(Adc0::prescaler(Adc0::Prescaler::div128));
}

TEST(Adc0, leftAdjust) {
    TEST_REG_WRITE(Adc0::leftAdjust(true));
    TEST_REG_WRITE(Adc0::leftAdjust(false));
}

TEST(Adc0, trigger) {
    TEST_REG_WRITE(Adc0::trigger(Adc0::Trigger::singleConversion));
    TEST_REG_WRITE(Adc0::trigger(Adc0::Trigger::freeRunning));
    TEST_REG_WRITE(Adc0::trigger(Adc0::Trigger::analogComparator));
    TEST_REG_WRITE(Adc0::trigger(Adc0::Trigger::externalInt0));
    TEST_REG_WRITE(Adc0::trigger(Adc0::Trigger::timer0CompareMatchA));
    TEST_REG_WRITE(Adc0::trigger(Adc0::Trigger::timer0Overflow));
    // TEST_REG_WRITE(Adc0::trigger(Adc0::Trigger::Timer0CompareMatchB));
    // TEST_REG_WRITE(Adc0::trigger(Adc0::Trigger::PinChangeInterrupt));
}

TEST(Adc0, callback) {
    TEST_REG_WRITE(Adc0::callback(func,data));
}

TEST(Adc0, intEnable) {
    TEST_REG_WRITE(Adc0::intEnable(false));
    TEST_REG_WRITE(Adc0::intEnable(true));
}

TEST(Adc0, intFlag) {
    TEST_REG_READ_WRITE(Adc0::intFlag());
}

TEST(Adc0, intFlagClear) {
    TEST_REG_WRITE(Adc0::intFlagClear());
}

//------------------------------------------------
// External Interrupts

INCLUDE_EXINT_CALLBACK(0);

TEST(ExIntN, getHardwareType) {
    ASSERT_EQ(ExInt0::getHardwareType(), HardwareType::exInt);
}

TEST(ExIntN, enable) {
    TEST_REG_WRITE(ExInt0::enable(true));
    TEST_REG_WRITE(ExInt0::enable(false));
}

TEST(ExIntN, trigger) {
    TEST_REG_WRITE(ExInt0::trigger(ExInt0::Trigger::low));
    TEST_REG_WRITE(ExInt0::trigger(ExInt0::Trigger::change));
    TEST_REG_WRITE(ExInt0::trigger(ExInt0::Trigger::falling));
    TEST_REG_WRITE(ExInt0::trigger(ExInt0::Trigger::rising));
}

TEST(ExIntN, callback) {
    TEST_REG_WRITE(ExInt0::callback(func,data));
}

TEST(ExIntN, intFlag) {
    TEST_REG_READ_WRITE(ExInt0::intFlag());
}

TEST(ExIntN, intFlagClear) {
    TEST_REG_WRITE(ExInt0::intFlagClear());
}

//------------------------------------------------
// Pin Change Interrupts

INCLUDE_PCINT_CALLBACK(0);

TEST(PcIntN, getHardwareType) {
    ASSERT_EQ(PcInt0::getHardwareType(), HardwareType::pcInt);
}

TEST(PcIntN, enable) {
    TEST_REG_WRITE(PcInt0::enable(true));
    TEST_REG_WRITE(PcInt0::enable(false));
}

TEST(PcIntN, mask) {
    TEST_REG_WRITE(PcInt0::mask(0x64));
}

TEST(PcIntN, callback) {
    TEST_REG_WRITE(PcInt0::callback(func,data));
}

TEST(PcIntN, intFlag) {
    TEST_REG_READ_WRITE(PcInt0::intFlag());
}

TEST(PcIntN, intFlagClear) {
    TEST_REG_WRITE(PcInt0::intFlagClear());
}

//------------------------------------------------
// Digital Pins

TEST(PortXPinN, getHardwareType) {
    ASSERT_EQ(PortB::Pin0::getHardwareType(), HardwareType::pin);
    ASSERT_EQ(PortB::Pin5::getHardwareType(), HardwareType::pin);
}

TEST(PortXPinN, mode) {
    TEST_REG_WRITE(PortB::Pin0::mode(Pin::Mode::input));
    TEST_REG_WRITE(PortB::Pin0::mode(Pin::Mode::output));
    TEST_REG_READ_WRITE(PortB::Pin0::mode());
}

TEST(PortXPinN, output) {
    TEST_REG_READ_WRITE(PortB::Pin2::output());
}

TEST(PortXPinN, input) {
    TEST_REG_READ_WRITE(PortB::Pin3::input());
}

TEST(PortXPinN, toggle) {
    TEST_REG_WRITE(PortB::Pin4::toggle());
}

//------------------------------------------------
// Digital Ports

TEST(PortX, getHardwareType) {
    ASSERT_EQ(PortB::getHardwareType(), HardwareType::port);
}

TEST(PortX, mode) {
    TEST_REG_WRITE(PortB::mode(Pin::Mode::input));
    TEST_REG_WRITE(PortB::mode(Pin::Mode::output));
    TEST_REG_WRITE(PortB::mode(Pin::Mode::inputPullup));
}

TEST(PortX, output) {
    TEST_REG_WRITE(PortB::output(0x27));
    TEST_REG_READ_WRITE(PortB::output());
}

TEST(PortX, input) {
    TEST_REG_READ_WRITE(PortB::input());
}

TEST(PortX, toggle) {
    TEST_REG_WRITE(PortB::toggle(0x26));
}

//------------------------------------------------
// Timers

INCLUDE_TIMER_OVERFLOW_CALLBACK(0);
INCLUDE_TIMER_OUTPUT_CALLBACK(0, A);
INCLUDE_TIMER_OUTPUT_CALLBACK(0, B);

INCLUDE_TIMER_OVERFLOW_CALLBACK(1);
INCLUDE_TIMER_OUTPUT_CALLBACK(1, A);
INCLUDE_TIMER_OUTPUT_CALLBACK(1, B);

TEST(Timer0, getHardwareType) {
    ASSERT_EQ(Timer0::getHardwareType(), HardwareType::timer);
}

TEST(Timer0, type) {
    ::testing::StaticAssertTypeEq<Timer0::type, uint8_t>();
}

TEST(Timer0, counter) {
    TEST_REG_WRITE(Timer0::counter(0xc4));
    TEST_REG_READ_WRITE(Timer0::counter());
}

TEST(Timer0, clock) {
    TEST_REG_WRITE(Timer0::clock(Timer0::Clock::none));
    TEST_REG_WRITE(Timer0::clock(Timer0::Clock::div1));
    TEST_REG_WRITE(Timer0::clock(Timer0::Clock::div8));
    TEST_REG_WRITE(Timer0::clock(Timer0::Clock::div64));
    TEST_REG_WRITE(Timer0::clock(Timer0::Clock::div256));
    TEST_REG_WRITE(Timer0::clock(Timer0::Clock::div1024));
    TEST_REG_WRITE(Timer0::clock(Timer0::Clock::extFalling));
    TEST_REG_WRITE(Timer0::clock(Timer0::Clock::extRising));
}

TEST(Timer0, waveform) {
    TEST_REG_WRITE(Timer0::waveform(Timer0::Waveform::normal));
    TEST_REG_WRITE(Timer0::waveform(Timer0::Waveform::pwm));
    TEST_REG_WRITE(Timer0::waveform(Timer0::Waveform::ctcOcra));
    TEST_REG_WRITE(Timer0::waveform(Timer0::Waveform::fastPwm));
    TEST_REG_WRITE(Timer0::waveform(Timer0::Waveform::pwmOcra));
    TEST_REG_WRITE(Timer0::waveform(Timer0::Waveform::fastPwmOcra));
}

TEST(Timer0, overflowCallback) {
    TEST_REG_WRITE(Timer0::overflowCallback(func,data));
}

TEST(Timer0, overflowIntEnable) {
    TEST_REG_WRITE(Timer0::overflowIntEnable(true));
    TEST_REG_WRITE(Timer0::overflowIntEnable(false));
}

TEST(Timer0, overflowIntFlag) {
    TEST_REG_READ_WRITE(Timer0::overflowIntFlag());
}

TEST(Timer0, overflowIntFlagClear) {
    TEST_REG_WRITE(Timer0::overflowIntFlagClear());
}

TEST(Timer0, outputA) {
    TEST_REG_WRITE(Timer0::OutputA::value(0xc8));
    TEST_REG_READ_WRITE(Timer0::OutputA::value());
}

TEST(Timer0, outputB) {
    TEST_REG_WRITE(Timer0::OutputB::value(0x7a));
    TEST_REG_READ_WRITE(Timer0::OutputB::value());
}

TEST(Timer0, outputAMode) {
    TEST_REG_WRITE(Timer0::OutputA::mode(Timer0::OutputA::Mode::disconnected));
    TEST_REG_WRITE(Timer0::OutputA::mode(Timer0::OutputA::Mode::toggle));
    TEST_REG_WRITE(Timer0::OutputA::mode(Timer0::OutputA::Mode::clear));
    TEST_REG_WRITE(Timer0::OutputA::mode(Timer0::OutputA::Mode::set));
}

TEST(Timer0, outputBMode) {
    TEST_REG_WRITE(Timer0::OutputB::mode(Timer0::OutputB::Mode::disconnected));
    TEST_REG_WRITE(Timer0::OutputB::mode(Timer0::OutputB::Mode::toggle));
    TEST_REG_WRITE(Timer0::OutputB::mode(Timer0::OutputB::Mode::clear));
    TEST_REG_WRITE(Timer0::OutputB::mode(Timer0::OutputB::Mode::set));
}

TEST(Timer0, outputACallback) {
    TEST_REG_WRITE(Timer0::OutputA::callback(func,data));
}

TEST(Timer0, outputBCallback) {
    TEST_REG_WRITE(Timer0::OutputB::callback(func,data));
}

TEST(Timer0, outputAIntEnable) {
    TEST_REG_WRITE(Timer0::OutputA::intEnable(true));
    TEST_REG_WRITE(Timer0::OutputA::intEnable(false));
}

TEST(Timer0, outputBIntEnable) {
    TEST_REG_WRITE(Timer0::OutputB::intEnable(true));
    TEST_REG_WRITE(Timer0::OutputB::intEnable(false));
}

TEST(Timer0, outputAIntFlag) {
    TEST_REG_READ_WRITE(Timer0::OutputA::intFlag());
}

TEST(Timer0, outputBIntFlag) {
    TEST_REG_READ_WRITE(Timer0::OutputB::intFlag());
}

TEST(Timer0, outputAIntFlagClear) {
    TEST_REG_WRITE(Timer0::OutputA::intFlagClear());
}

TEST(Timer0, outputBIntFlagClear) {
    TEST_REG_WRITE(Timer0::OutputB::intFlagClear());
}

TEST(Timer1, getHardwareType) {
    ASSERT_EQ(Timer1::getHardwareType(), HardwareType::timer);
}

TEST(Timer1, type) {
    ::testing::StaticAssertTypeEq<Timer1::type, uint8_t>();
}

TEST(Timer1, counter) {
    TEST_REG_WRITE(Timer1::counter(0x8a));
    TEST_REG_READ_WRITE(Timer1::counter());
}

TEST(Timer1, clock) {
    TEST_REG_WRITE(Timer1::clock(Timer1::Clock::none));
    TEST_REG_WRITE(Timer1::clock(Timer1::Clock::div1));
    TEST_REG_WRITE(Timer1::clock(Timer1::Clock::div2));
    TEST_REG_WRITE(Timer1::clock(Timer1::Clock::div4));
    TEST_REG_WRITE(Timer1::clock(Timer1::Clock::div8));
    TEST_REG_WRITE(Timer1::clock(Timer1::Clock::div16));
    TEST_REG_WRITE(Timer1::clock(Timer1::Clock::div32));
    TEST_REG_WRITE(Timer1::clock(Timer1::Clock::div64));
    TEST_REG_WRITE(Timer1::clock(Timer1::Clock::div128));
    TEST_REG_WRITE(Timer1::clock(Timer1::Clock::div256));
    TEST_REG_WRITE(Timer1::clock(Timer1::Clock::div512));
    TEST_REG_WRITE(Timer1::clock(Timer1::Clock::div1024));
    TEST_REG_WRITE(Timer1::clock(Timer1::Clock::div2048));
    TEST_REG_WRITE(Timer1::clock(Timer1::Clock::div4096));
    TEST_REG_WRITE(Timer1::clock(Timer1::Clock::div8192));
    TEST_REG_WRITE(Timer1::clock(Timer1::Clock::div16384));
}

TEST(Timer1, waveform) {
    TEST_REG_WRITE(Timer1::waveform(Timer1::Waveform::normal));
    TEST_REG_WRITE(Timer1::waveform(Timer1::Waveform::ctcOcra));
    TEST_REG_WRITE(Timer1::waveform(Timer1::Waveform::fastPwmOcrc));
}

TEST(Timer1, overflowCallback) {
    TEST_REG_WRITE(Timer1::overflowCallback(func,data));
}

TEST(Timer1, overflowIntEnable) {
    TEST_REG_WRITE(Timer1::overflowIntEnable(true));
    TEST_REG_WRITE(Timer1::overflowIntEnable(false));
}

TEST(Timer1, overflowIntFlag) {
    TEST_REG_READ_WRITE(Timer1::overflowIntFlag());
}

TEST(Timer1, overflowIntFlagClear) {
    TEST_REG_WRITE(Timer1::overflowIntFlagClear());
}

TEST(Timer1, outputA) {
    TEST_REG_WRITE(Timer1::OutputA::value(0xd9));
    TEST_REG_READ_WRITE(Timer1::OutputA::value());
}

TEST(Timer1, outputB) {
    TEST_REG_WRITE(Timer1::OutputB::value(0x8d));
    TEST_REG_READ_WRITE(Timer1::OutputB::value());
}

TEST(Timer1, outputC) {
    TEST_REG_WRITE(Timer1::OutputC::value(0x15));
    TEST_REG_READ_WRITE(Timer1::OutputC::value());
}

TEST(Timer1, outputAMode) {
    TEST_REG_WRITE(Timer1::OutputA::mode(Timer1::OutputA::Mode::disconnected));
    TEST_REG_WRITE(Timer1::OutputA::mode(Timer1::OutputA::Mode::toggle));
    TEST_REG_WRITE(Timer1::OutputA::mode(Timer1::OutputA::Mode::clear));
    TEST_REG_WRITE(Timer1::OutputA::mode(Timer1::OutputA::Mode::set));
}

TEST(Timer1, outputBMode) {
    TEST_REG_WRITE(Timer1::OutputB::mode(Timer1::OutputB::Mode::disconnected));
    TEST_REG_WRITE(Timer1::OutputB::mode(Timer1::OutputB::Mode::toggle));
    TEST_REG_WRITE(Timer1::OutputB::mode(Timer1::OutputB::Mode::clear));
    TEST_REG_WRITE(Timer1::OutputB::mode(Timer1::OutputB::Mode::set));
}

TEST(Timer1, outputACallback) {
    TEST_REG_WRITE(Timer1::OutputA::callback(func,data));
}

TEST(Timer1, outputBCallback) {
    TEST_REG_WRITE(Timer1::OutputB::callback(func,data));
}

TEST(Timer1, outputAIntEnable) {
    TEST_REG_WRITE(Timer1::OutputA::intEnable(true));
    TEST_REG_WRITE(Timer1::OutputA::intEnable(false));
}

TEST(Timer1, outputBIntEnable) {
    TEST_REG_WRITE(Timer1::OutputB::intEnable(true));
    TEST_REG_WRITE(Timer1::OutputB::intEnable(false));
}

TEST(Timer1, outputAIntFlag) {
    TEST_REG_READ_WRITE(Timer1::OutputA::intFlag());
}

TEST(Timer1, outputBIntFlag) {
    TEST_REG_READ_WRITE(Timer1::OutputB::intFlag());
}

TEST(Timer1, outputAIntFlagClear) {
    TEST_REG_WRITE(Timer1::OutputA::intFlagClear());
}

TEST(Timer1, outputBIntFlagClear) {
    TEST_REG_WRITE(Timer1::OutputB::intFlagClear());
}

//------------------------------------------------
// Universal serial interfaces

INCLUDE_USI_CALLBACK(0, START);
INCLUDE_USI_CALLBACK(0, OVERFLOW);

TEST(Usi0, getHardwareType) {
    ASSERT_EQ(Usi0::getHardwareType(), HardwareType::usi);
}

TEST(Usi0, data) {
    TEST_REG_READ_WRITE(Usi0::data());
    TEST_REG_WRITE(Usi0::data(0x3b));
}

TEST(Usi0, startConditionIntEnable) {
    TEST_REG_WRITE(Usi0::startConditionIntEnable(true));
    TEST_REG_WRITE(Usi0::startConditionIntEnable(false));
}

TEST(Usi0, counterOverflowIntEnable) {
    TEST_REG_WRITE(Usi0::counterOverflowIntEnable(true));
    TEST_REG_WRITE(Usi0::counterOverflowIntEnable(false));
}

TEST(Usi0, wireMode) {
    TEST_REG_WRITE(Usi0::wireMode(nbos::hw::Usi0::WireMode::disabled));
    TEST_REG_WRITE(Usi0::wireMode(nbos::hw::Usi0::WireMode::threeWire));
    TEST_REG_WRITE(Usi0::wireMode(nbos::hw::Usi0::WireMode::twoWire));
    TEST_REG_WRITE(Usi0::wireMode(nbos::hw::Usi0::WireMode::twoWireOverflow));
}

TEST(Usi0, clock) {
    TEST_REG_WRITE(Usi0::clock(nbos::hw::Usi0::Clock::none));
    TEST_REG_WRITE(Usi0::clock(nbos::hw::Usi0::Clock::timer0CompareMatch));
    TEST_REG_WRITE(Usi0::clock(nbos::hw::Usi0::Clock::externalPositiveEdge));
    TEST_REG_WRITE(Usi0::clock(nbos::hw::Usi0::Clock::externalNegativeEdge));
}

TEST(Usi0, clockStrobe) {
    TEST_REG_WRITE(Usi0::clockStrobe());
}

TEST(Usi0, toggleClockPin) {
    TEST_REG_WRITE(Usi0::toggleClockPin());
}

TEST(Usi0, startConditionIntFlag) {
    TEST_REG_READ_WRITE(Usi0::startConditionIntFlag());
    TEST_REG_WRITE(Usi0::startConditionIntFlagClear());
}

TEST(Usi0, stopConditionIntFlag) {
    TEST_REG_READ_WRITE(Usi0::stopConditionIntFlag());
    TEST_REG_WRITE(Usi0::stopConditionIntFlagClear());
}

TEST(Usi0, counterOverflowIntFlag) {
    TEST_REG_READ_WRITE(Usi0::counterOverflowIntFlag());
    TEST_REG_WRITE(Usi0::counterOverflowIntFlagClear());
}

TEST(Usi0, collisionFlag) {
    TEST_REG_READ_WRITE(Usi0::collisionFlag());
}

TEST(Usi0, counter) {
    TEST_REG_READ_WRITE(Usi0::counter());
    TEST_REG_WRITE(Usi0::counter(0x0));
    TEST_REG_WRITE(Usi0::counter(0x3));
    TEST_REG_WRITE(Usi0::counter(0xc3));
}
