#include "mbed.h"

// Hardware Definitions
#define TRAF_GRN1_PIN PC_6
#define TRAF_YEL1_PIN PC_3
#define TRAF_RED1_PIN PC_2
#define STEREO_L_AN PB_0


#define LEDMASK 0b0000000001001100
// #define LEDMASK 0b0000000001001000
// Objects
//BusOut leds(TRAF_RED1_PIN, TRAF_YEL1_PIN, TRAF_GRN1_PIN);
PortOut leds(PortC, LEDMASK);
BusOut leds2(STEREO_L_AN);

int main()
{
    while (true) {
        leds = 0;   //Binary 000
        leds2 = 0;
        wait_us(500000);
        leds = 0xFF;   //Binary 11111111
        leds2 = 1;
        wait_us(500000);    
    }
}




