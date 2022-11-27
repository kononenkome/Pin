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
    void operator = (int _pin) { setup(_pin); }
    void reset() { ready = false; }
    void set(int level) { setup(pin, mode); digitalWrite(pin, level); }
    int get() { return digitalRead(pin); }
    void on(int ms = 0) { 
        set(HIGH); 
        if (time) delay(ms);
        off();
        }
    void off() { set(LOW); }
    void toggle() { set(!get()); }
};