#include "servo_driver.hpp"

servo_driver::servo_driver() = default;

servo_driver::servo_driver(int bus, int address){
    servo = std::make_shared<PCA9685>(address, bus);
    
    servo->openPCA9685();
    printf("PCA9685 Device Address: 0x%02X\n",servo->kI2CAddress);
    this->init();
    servo->setPWMFrequency(frequency);
}

servo_driver::~servo_driver(){
    this->angle(0, 90);
    this->angle(1, 100);
    servo->closePCA9685();
}

void servo_driver::init(){
    servo->setAllPWM(0, 0);
    servo->reset();
}

void servo_driver::angle(int channel, int angle){
    int value = this->map(angle);
    if (channel == 1)
    	if (value <= 112 && value >= 336){
	    printf("Out of angle range.\n");
	    return;
	}

    servo->setPWM(channel, 0, value);
}

// private
int servo_driver::map (int degree) {
    if (degree >= 0 && degree <= 180)
        return (degree * (servoMax-servoMin)/180 + servoMin);
    else {
	printf("Out of angle range.\n");
	return servoMiddle;
    }
}

