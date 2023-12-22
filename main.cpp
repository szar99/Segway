#include "mbed.h"
#include "pm2_drivers/PixyCam2.h"
#include <cstdint>
#include <initializer_list>


PixyCam2 pixy(PC_10, PC_11, 230400);

int main()
{

    // while loop gets executed every main_task_period_ms milliseconds (simple aproach to repeatedly execute main)
    const int main_task_period_ms = 30; // define main task period time in ms e.g. 50 ms -> main task runs 20 times per second
    Timer main_task_timer;              // create Timer object which we use to run the main task every main_task_period_ms

    main_task_timer.start();
    while (true)
    {   
        main_task_timer.reset();
        printf("MAIN \n"); //to check like main thread is executed
        // read timer and make the main thread sleep for the remaining time span (non blocking)
        int main_task_elapsed_time_ms = std::chrono::duration_cast<std::chrono::milliseconds>(main_task_timer.elapsed_time()).count();
        thread_sleep_for(main_task_period_ms - main_task_elapsed_time_ms);
    }
}


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

//Script for gimbal assembly - servos positioning
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