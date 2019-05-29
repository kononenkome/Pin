#include <Arduino.h>

class Pin
{
    uint32_t pin;

public:
    Pin(uint32_t _pin) : pin(_pin) {}
    void setup(uint32_t mode = OUTPUT) { pinMode(pin, mode); }
    void set(uint32_t level) { digitalWrite(pin, level); }
    uint32_t get() { return digitalRead(pin); }
    void on() { set(HIGH); }
    void off() { set(LOW); }
    void toggle() { set(!get()); }
};