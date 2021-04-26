#include "../lib/uopmsb/uop_msb_2_0_0.h"
using namespace uop_msb_200;

// Inputs
DigitalIn SW2(BTN1_PIN);
DigitalIn SW3(BTN2_PIN);

// Outputs
DigitalOut ledRed(TRAF_RED1_PIN);
DigitalOut ledYel(TRAF_YEL1_PIN);
DigitalOut ledGrn(TRAF_GRN1_PIN);

// Timers (modified version from Timer)
TimerCompat tmr_flash;

// THE CODE BELOW IS NOT A SOLUTION
//
// IT IS FUNDAMENTALLY FLAWED (AND INCOMPLETE)
//
//

int main()
{
    //Start flashing timer
    tmr_flash.start();

    while (true) {


        int sw2 = SW2.read();
        int sw3 = SW3.read();
        if (sw2 && sw3) {
            ledGrn = !ledGrn;
            ledRed = !ledRed;
            wait_us(300000);        
        }
        else if (sw2) {
            ledGrn = !ledGrn;
            wait_us(300000);
        }
        else if (sw3) {
            ledRed = !ledRed;
            wait_us(300000);
        }

        //Wait for switch press and release (by BLOCKING)
        // while (SW2.read() == 0);
        // ledRed = !ledRed;
        // wait_us(300000);

        // while (SW2.read() == 1);
        // wait_us(300000);        

        //Toggle Yellow LED
        ledYel = !ledYel;
        while (tmr_flash.read_ms() < 500);
        tmr_flash.reset();
    }
}





