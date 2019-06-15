#include <Arduino.h>

class Pin
{
    int pin = -1;
    int mode = OUTPUT;
    bool ready = false;

public:
    Pin() {}
    Pin(int _pin, int _mode = OUTPUT) : pin(_pin), mode(_mode) {};
    void setup(int _pin, int _mode = OUTPUT) { 
        if (!ready) { 
            pin = _pin; 
            mode = _mode;
            pinMode(_pin, mode); 
            ready = true; 
            }
    }
    void reset() { ready = false; }
    void set(int level) { digitalWrite(pin, level); }
    int get() { return digitalRead(pin); }
    void on() { set(HIGH); }
    void off() { set(LOW); }
    void toggle() { set(!get()); }
};