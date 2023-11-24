#include "mbed.h"
#include "PM2_Drivers.h"


PixyCam pixy(PC_12, PD_2, 230400);

int main()
{


    DigitalIn mechanical_button(PC_5); // create DigitalIn object to evaluate extra mechanical button, you need to specify the mode for proper usage, see below
    mechanical_button.mode(PullUp);    // set pullup mode: sets pullup between pin and 3.3 V, so that there is a defined potential
    while (true)
    {

        if (mechanical_button.read()) {
            pixy.setServos(0,0);
            ThisThread::sleep_for(2s);
            pixy.setServos(500,500);
            ThisThread::sleep_for(2s);
            pixy.setServos(1000,1000);
            ThisThread::sleep_for(2s);
            pixy.setServos(500,500);
        }
        ThisThread::sleep_for(100ms);
    }
}


//Script for gimbal assembly - servos positioning
/*    
int main()
{


    DigitalIn mechanical_button(PC_5); // create DigitalIn object to evaluate extra mechanical button, you need to specify the mode for proper usage, see below
    mechanical_button.mode(PullUp);    // set pullup mode: sets pullup between pin and 3.3 V, so that there is a defined potential
    while (true)
    {

        if (mechanical_button.read()) {
            pixy.setServos(0,0);
            ThisThread::sleep_for(2s);
            pixy.setServos(500,500);
            ThisThread::sleep_for(2s);
            pixy.setServos(1000,1000);
            ThisThread::sleep_for(2s);
            pixy.setServos(500,500);
        }
        ThisThread::sleep_for(100ms);
    }
}
*/