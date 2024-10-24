#ifndef PKIO230_H
#define PKIO230_H

#include <Wire.h>
#include "PCF8574.h"

class PKIO230 {
  public:
    // Constructor to initialize with custom I2C address (default is 0x20)
    PKIO230(uint8_t address = 0x20) : pcf8574(address) {}

    // Initialize the I2C and PCF8574
    void begin() {
      pcf8574.begin();        // Initialize the PCF8574
      pcf8574.setButtonMask(0x0F);
    }

    // Set the relay on the given pin (pins 4 to 7)
    void relaySet(uint8_t pin, bool state) {
      if (pin >= 0 && pin < 4) {
        pcf8574.write(pin+4, state ? HIGH : LOW);
      }
    }

    // Read the input from the given pin (pins 0 to 3)
    bool inputRead(uint8_t pin) {
      if (pin >= 0 && pin <= 3) {
        return ! pcf8574.read(pin);
      }
      return false;  // Return false if invalid pin is accessed
    }

    // Check if the PCF8574 is connected
    bool isConnected() {
      return pcf8574.isConnected();
    }

  private:
    PCF8574 pcf8574;  // Instance of PCF8574
};

#endif