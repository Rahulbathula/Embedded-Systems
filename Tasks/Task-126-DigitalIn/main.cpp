#include "mbed.h"

DigitalIn ButtonA(PG_0); //Button A
DigitalIn ButtonB(PG_1); //Button B
DigitalIn ButtonC(PG_2, PinMode::PullDown); //Button C
DigitalIn ButtonD(PG_3, PinMode::PullDown); //Button D
DigitalOut redLED(PC_2); //Red Traffic 1
DigitalOut blueLED(PC_3); //yellow LED

// main() runs in its own thread in the OS
int main()
{
    int btnABCD;
    redLED = 0;

    while (true) {
    
        // Wait for the button to be pressed
        do {
            btnABCD = ButtonA & ButtonB &ButtonC & ButtonD; //Read button A
        } while (btnABCD == 0);

        redLED = !redLED;
        blueLED = !blueLED;


        wait_us(10000);

        do {
            btnABCD = ButtonA & ButtonB & ButtonC & ButtonD; //Read button A
        } while (btnABCD == 1);

        //Wait for noise to settle
        wait_us(10000);
    }
}

