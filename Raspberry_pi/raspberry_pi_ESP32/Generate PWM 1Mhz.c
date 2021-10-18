// In this file we're going to generate a 1MHz PWM to power the transducers with Raspberry Pi3

#include<stdio.h>
#include<stdlib.h>
#include<wiringPi.h>
#include <stdint.h>

#define pinT1 18 // This pin is connected to two transducers (Mode: Transmetter)

#define mode PWM_MODE_MS // this mode is used to give an accurate signal when the frequencies is high

int main(int arglen, char *argv[])
{
      int index = 0;
      
      if(-1==wiringPiSetup())
      {
             printf("setup error\n");
             exit(-1);
      }

   

    //These values is chosen to generate 1Mhz of frequency 
    int value = 512;
    // duty cycle is from 0 to 1024

    wiringPiSetup();
    pwmSetMode(mode); // This mode is used to choose a desired frequency

    pinMode(pinT1,PWM_OUTPUT); //only PCM_GPIO18 support PWM_OUTPUT
    
 //pwmFrequency in Hz = 19.2e6 Hz / pwmClock / pwmRange
    int clock= 2;
    int range = 9;

    pwmSetRange(range); //Range could be up to 4096
    pwmSetClock(clock); // clock should be in [2..4095]

    for (index= 0;index<10000;index++)
    {
        pwmWrite(pinT1,value);
      
        delay(340);
        pwmWrite(pinT1,0);
       
    }
    return 0;

}
