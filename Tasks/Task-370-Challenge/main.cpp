#include "../lib/uopmsb/uop_msb_2_0_0.h"
#include "mbed.h"

#include <chrono>
#include <cstdio>

#define SAMPLES 300;

using namespace uop_msb_200;

void adc();

AnalogIn ldr(PC_0);

//Used this to 
Ticker tick;

Thread t1;
osThreadId_t mainThreadID;
osThreadId_t adcThread;

int counter = 0;

float totalVolt;


void adcThreadSignaler(){
        osSignalSet(adcThread, 1);
}

int main(void)
{
/*
1. Create an ISR - called by a Ticker every 1ms. This ISR simply has the job of 
    signalling a waiting thread to perform an ADC conversion
2. Create a thread that waits for a signal from the ISR. This thread should ideally 
    have the highest priority
3. Each time it is unblocked by the signal, it should read the ADC (Use `AnalogIn`) 
    for the LDR and add it to a running sum.
4. Every 1s, it should print out the average of the past 1000 samples to the terminal. 
*/
    t1.start(adc);
    //mainThreadID = ThisThread::get_id();
    tick.attach(&adcThreadSignaler,1ms);    
}  
 
 
void adc(){//make highest priority
    adcThread = ThisThread::get_id();
    while (true) {
        ThisThread::flags_wait_any(1); 

        counter++;

        unsigned int adc_sample[300];
        float Voltage;
        adc_sample[0]=0;
        for (int i=1; i<=300; i++) {
            adc_sample[i] = ldr.read_u16();
            adc_sample[0]+=adc_sample[i];
        }
        Voltage = 3.3f * ((float)adc_sample[0]/(float)300)/65535.0f;
        //printf("%f\n",Voltage);
        totalVolt = totalVolt + Voltage;
        
        if (counter == 1000) {
            float averageVoltage = totalVolt/1000;
            printf("Average voltage over a second: %f\n",averageVoltage);
            totalVolt = 0;
            counter = 0;
        }
        else if (counter > 1000) {
            printf("Counter skipped 1000\n");
        }
    }

    //ThisThread::flags_wait_any(1); 
}