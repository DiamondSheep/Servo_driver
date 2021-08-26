# Servo_driver
A driver for the Adafruit 16-Channel 12-bit Servo Driver - I2C interface - PCA9685.
http://www.adafruit.com/product/815

Built for the NVIDIA Jetson Nano Development Kit.

Only for SG90 / MG90s servos or other servos with similar PWM signal timing. 

![image-20210826094550586](C:\Users\63016\AppData\Roaming\Typora\typora-user-images\image-20210826094550586.png)

The default address for the PCA9685 is 0x40. On some Jetson models, this address is being used by other hardware. 

The default bus for the Jetson Nano is 1 which means you should connect the SDA to Pin 3 and the SCL to the Pin 5. 

In order to be able inspect the PCA9685, you may find it useful to install the i2c tools:

<blockquote>$ sudo apt-get install libi2c-dev i2c-tools</blockquote>

As an example, after installation, in a Terminal execute:

<blockquote>$ sudo i2cdetect -y -r 1</blockquote>

Replace the bus number 1 with the appropriate bus number.
