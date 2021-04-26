#include "mbed.h"
#include <cstdio>

// Hardware Definitions
#define TRAF_GRN1_PIN PC_6
#define TRAF_YEL1_PIN PC_3
#define TRAF_RED1_PIN PC_2
#define TRAF_RED2_PIN PC_7
#define TRAF_GRN2_PIN PC_9
#define TRAF_YEL2_PIN PC_8

// Objects
// DigitalOut grn(TRAF_GRN1_PIN);
// DigitalOut yel(TRAF_YEL1_PIN);
// DigitalOut red(TRAF_RED1_PIN,1);

//  DigitalOut red(TRAF_RED2_PIN);
// DigitalOut yel(TRAF_YEL2_PIN);
// DigitalOut grn(TRAF_GRN2_PIN);

BusOut leds(TRAF_RED1_PIN, TRAF_YEL1_PIN, TRAF_GRN1_PIN);

int main()
{
    while (true) {
        // leds = 0;   //Binary 000
        // wait_us(500000);
        // leds = 7;   //Binary 111
        
        
        
        // grn = 1;
        // red = 1;
        // yel = 1;


        for (int i = 1; i <= 7; i++){
        leds = 0;   //Binary 000
        wait_us(500000);
        leds = i;   //Binary 101
        // printf();
        wait_us(500000);   
        }

    }
}


