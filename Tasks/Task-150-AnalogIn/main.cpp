#include "uop_msb.h"
#include <chrono>
#include <cstdint>
using namespace uop_msb;
using namespace chrono;

BusIn btns(PC_2,PC_3,PC_6);
DigitalOut Greenled(PC_6);
DigitalOut Yellow(PC_3);
DigitalOut Redled(PC_2);

//Fun output stuff
LCD_16X2_DISPLAY disp;
Buzzer buzz;
LatchedLED ledDisp(LatchedLED::STRIP);

//Analogue Inputs
AnalogIn pot(AN_POT_PIN);
AnalogIn ldr(AN_LDR_PIN);
AnalogIn mic(MIC_AN_PIN);

int main()
{

    //Test LED Bar Display
    ledDisp.enable(true);

    ledDisp.setGroup(LatchedLED::LEDGROUP::RED);
    for (unsigned int n=0; n<8; n++) {
        ledDisp = 1 << n;
        wait_us(250000);
    }
    ledDisp = 0;

    ledDisp.setGroup(LatchedLED::LEDGROUP::GREEN);
    for (unsigned int n=0; n<8; n++) {
        ledDisp = 1 << n;
        wait_us(250000);
    }
    ledDisp = 0;
    
    ledDisp.setGroup(LatchedLED::LEDGROUP::BLUE);
    for (unsigned int n=0; n<8; n++) {
        ledDisp = 1 << n;
        wait_us(250000);
    }     
    ledDisp = 0;


    while (true) {
        //Read Analog to Digital Converter values (16 bit)
        unsigned short potVal   = pot.read_u16();
        unsigned short lightVal = ldr.read_u16();
        unsigned short micVal   = mic.read_u16(); 

        //Write to terminal
        printf("--------------------------------\n");
        printf("Potentiometer: %X\n", potVal);
        printf("Light Dependant Resistor: %X\n", lightVal);
        printf("Microphone: %X\n", micVal);   

        //Wait 0.25 seconds
        wait_us(500000);

        if (lightVal < 1000) {
            Greenled = 1;
        }
        else {
            Greenled = 0;
        }

        if (potVal > 0x8000) {
            Yellow = 1;
        }
        else {
            Yellow = 0;
        }

        if (micVal < 8000) {
            Redled = 1;
        }
        else {
            Redled = 0;
        }

    }
}

