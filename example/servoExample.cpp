/*
 * The MIT License (MIT)

Copyright (c) 2015 Jetsonhacks

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
// servoExample.cpp
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "JHPWMPCA9685.hpp"


// Calibrated for a Robot Geek RGS-13 Servo
// Make sure these are appropriate for the servo being used!

int servoMin = 120;
int servoMax = 488;
/*
int getkey() {
    int character;
    struct termios orig_term_attr;
    struct termios new_term_attr;

    // set the terminal to raw mode 
    tcgetattr(fileno(stdin), &orig_term_attr);
    memcpy(&new_term_attr, &orig_term_attr, sizeof(struct termios));
    new_term_attr.c_lflag &= ~(ECHO|ICANON);
    new_term_attr.c_cc[VTIME] = 0;
    new_term_attr.c_cc[VMIN] = 0;
    tcsetattr(fileno(stdin), TCSANOW, &new_term_attr);

    // read a character from the stdin stream without blocking 
    //   returns EOF (-1) if no character is available 
    character = fgetc(stdin);

    // restore the original terminal attributes
    tcsetattr(fileno(stdin), TCSANOW, &orig_term_attr);

    return character;
}
*/
// Map an integer from one coordinate system to another
// This is used to map the servo values to degrees
// e.g. map(90,0,180,servoMin, servoMax)
// Maps 90 degrees to the servo value

int map (int degree, int in_min, int in_max, int out_min, int out_max) {
    int toReturn = (degree - in_min) * (out_max - out_min) / (in_max - in_min) + out_min ;

    return toReturn ;
}

int main() {
    int err = 0;
    PCA9685 *servo1 = new PCA9685() ;
    err = servo1->openPCA9685();
    if (err < 0){
        printf("Error: %d", servo1->error);
    } 
    else {
        printf("PCA9685 Device Address: 0x%02X\n",servo1->kI2CAddress);
        servo1->setAllPWM(0,0);
        servo1->reset();
        servo1->setPWMFrequency(50);
	// reinit
	// servo1->setPWM(1,0, 336);
	servo1->setPWM(0,0, 200);
	sleep(1);
    }
    PCA9685 *servo2 = new PCA9685();
    err = servo2->openPCA9685();
    if (err < 0){
    	printf("Error: %d\n", servo2->error);
    }
    else{
    	printf("PCA9685 Device Address: 0x%02X\n", servo2->kI2CAddress);
	servo2->setAllPWM(0, 0);
	servo2->reset();
	servo2->setPWMFrequency(50);
	// reinit
	servo2->setPWM(1,0, 300);
    }
    servo1->closePCA9685();
    servo2->closePCA9685();
}
