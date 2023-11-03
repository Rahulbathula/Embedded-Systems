#include "mbed.h"

BusIn btns(PG_0,PG_1,PG_2,PG_3); //stuck with bustout, when u use busin(its a combination of digitalout and busout)for iterating 
int value;                       //when u have to iteate any elements we have to use busin
                                 //in this case to pulldown last two pins
DigitalOut Redled(PC_2);

// main() runs in its own thread in the OS
int main()
{
    Redled = 0;
    
    btns[PG_3].mode(PinMode::PullDown); //u have strugles here
    btns[PG_2].mode(PinMode::PullDown);
    while (true) {
        do {
        value = btns;
        }while (value<15);

        Redled =!0;

        wait_us(500000);

        do {
        value = btns;
        }while (value>0);

        wait_us(500000);
    }
}

