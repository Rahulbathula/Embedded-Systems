#include "uop_msb.h"
#include <chrono>
#include <cstdint>
#include <cstdio>
using namespace uop_msb;
using namespace chrono;

//Output
DigitalOut redLED(TRAF_RED1_PIN);
DigitalOut yellowLED(TRAF_YEL1_PIN);
DigitalOut greenLED(TRAF_GRN1_PIN);

//Analogue Inputs
AnalogIn ldr(AN_LDR_PIN);
Buzzer buzz;


int main()
{
    unsigned short samples[100];

    for (unsigned int m=0; m<100; m++) {
        printf("sample %X ", samples[m]);
    }
    float Sum=0.0;
    float average=0.0;

    // Automatic headlamp 
    while (true) {

        for (unsigned int m=0; m<100; m++) {
            unsigned short ldrVal   = ldr.read_u16();
            Sum += ldrVal; 
            samples[m] = ldrVal;
            wait_us(10000);          // 10ms
        }

        // TASK a. Calculate the average value in samples
        average = Sum / 100;

        // TASK b. Display to 1dp
        printf("Average value of samples:%0.1f\n", average);
        // TASK c. Switch green LED on when dark;
        if (average > 30000.0) {
            greenLED = 1;
        }
        else {
        greenLED=0;
        }
        
        Sum = 0;
    }  
}


