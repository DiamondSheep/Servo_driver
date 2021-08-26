#ifndef _SERVO_H
#define _SERVO_H

#include <memory>
#include "JHPWMPCA9685.hpp"

class servo_driver{
public:
    // Calibrated for SG-90 servo (top of the pan-tilt) and MG-90S servo (bottom of the pan-tilt)
    int servoMin = 112; // 150 for the SG-90 on the top of the pan-tilt
    int servoMax = 484; // 336 for the SG-90 on the top of the pan-tilt
    int servoMiddle = 298;
    int bus = 1; // bus 1 (pin 3 and pin 5)
    int address = 0x40;
    int frequency = 50; // default 50 Hz
    std::shared_ptr<PCA9685> servo;

    servo_driver();
    servo_driver(int bus=1, int address=0x40);
    ~servo_driver();
    void init();
    void angle(int channel, int angle); 

private:
    // map degrees to the servo value
    int map(int degree);
};

#endif
