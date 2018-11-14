/// [[Index]]

/// # {{Eeprom}}

/// ```c++
/// atomic([]() {
///     nbos::hw::Eeprom0::address(0x00);
///     nbos::hw::Eeprom0::data(0x01);
///     nbos::hw::Eeprom0::masterWriteEnable();
///     nbos::hw::Eeprom0::writeEnable();
/// });
///
/// while(nbos::hw::Eeprom0::writeEnabled());
///
/// nbos::hw::Eeprom0::address(0x00);
/// nbos::hw::Eeprom0::readEnable();
///
/// Word8 n = nbos::hw::Eeprom0::data();
/// ```

#ifndef NBOS_EEPROM_HPP

#include "chip.hpp"
#include "hardwaretype.hpp"
#include "isr.hpp"
#include "macros.hpp"
#include "system.hpp"
#include "callback.hpp"

#include "loopi"

#ifdef _I
    #define N _I
    #define EepromN CAT(Eeprom, N)
    #define EEPROM_N(A) CAT(CHIP_EEPROM_, N, _, A)

    #if CAT(CHIP_EEPROM_, N)

//------------------------------------------------------------------

namespace nbos::hw {

/// ## class {{EepromN}}
struct EepromN {
    EepromN() = delete;

    /// #### enum {{AdcN::Mode}}
    /// * eraseWrite
    /// * eraseOnly
    /// * writeOnly
    enum class Mode {
        eraseWrite = EEPROM_N(PROGRAMMING_MODE_ERASE_WRITE_ID),
        eraseOnly = EEPROM_N(PROGRAMMING_MODE_ERASE_ONLY_ID),
        writeOnly = EEPROM_N(PROGRAMMING_MODE_WRITE_ONLY_ID),
    };

    /// #### static [[HardwareType]] getHardwareType()
    static constexpr HardwareType getHardwareType() {
        return HardwareType::eeprom;
    }

    /// #### static void mode([[AdcN::Mode]] m)
    static force_inline void mode(Mode m) {
        setBit_(REG(EEPROM_N(PROGRAMMING_MODE_BIT_0_REG)), EEPROM_N(PROGRAMMING_MODE_BIT_0_BIT), Int(m) & 0x01);
        setBit_(REG(EEPROM_N(PROGRAMMING_MODE_BIT_1_REG)), EEPROM_N(PROGRAMMING_MODE_BIT_1_BIT), Int(m) & 0x02);
    }

    /// #### static void address(Word16 a)
    static force_inline void address(Word16 a) {
        *REG(EEPROM_N(ADDRESS_REG)) = a;
    }

    /// #### static void data(Word8 d)
    static force_inline void data(Word8 d) {
        *REG(EEPROM_N(DATA_REG)) = d;
    }

    /// #### static Word8 data()
    static force_inline Word8 data() {
        return *REG(EEPROM_N(DATA_REG));
    }

    /// #### static void masterWriteEnable()
    /// Enable the Eeprom write.
    static force_inline void masterWriteEnable() {
        setBit_(REG(EEPROM_N(MASTER_WRITE_ENABLE_REG)), EEPROM_N(MASTER_WRITE_ENABLE_BIT), true);
    }

    /// #### static void writeEnable()
    /// Start an Eeprom write.
    static force_inline void writeEnable() {
        setBit_(REG(EEPROM_N(WRITE_ENABLE_REG)), EEPROM_N(WRITE_ENABLE_BIT), true);
    }

    /// #### static Bool writeEnabled()
    /// Returns true if Eeprom is currently writing.
    static force_inline Bool writeEnabled() {
        return Bool(*REG(EEPROM_N(WRITE_ENABLE_REG)) & bv(EEPROM_N(WRITE_ENABLE_BIT)));
    }

    /// #### static void readEnable()
    /// Start an Eeprom read.
    static force_inline void readEnable() {
        setBit_(REG(EEPROM_N(READ_ENABLE_REG)), EEPROM_N(READ_ENABLE_BIT), true);
    }

    /// #### static void setCallback([[Callback]]<T\> function, T\* data)
    template <class T>
    static force_inline void setCallback(Callback<T> function, T* data = nullptr) {
        callback((Callback<void>)function, data);
    }

    /// #### static void callCallback()
    static force_inline void callCallback() {
        callback();
    }

    /// #### static void intEnable(Bool e)
    static force_inline void intEnable(Bool e) {
        setBit_(REG(EEPROM_N(READY_INT_ENABLE_REG)), EEPROM_N(READY_INT_ENABLE_BIT), e);
    }

private:

    static force_inline void callback(Callback<void> function = nullptr, void* data = nullptr) {
        static Callback<void> f = nullptr;
        static void* d = nullptr;

        if(function == nullptr) {
            if(f != nullptr) {
                f(d);
            }
        } else {
            f = function;
            d = data;
        }
    }
};

ISR(EEPROM_N(EE_READY_INT_VECTOR)) {
    EepromN::callCallback();
}

} // nbos::hw

//--------------------------------------------------------

    #endif

    #undef N
    #undef EepromN
    #undef EEPROM_N

    #include "eeprom.hpp"
#else
    #define NBOS_EEPROM_HPP
#endif

#endif
