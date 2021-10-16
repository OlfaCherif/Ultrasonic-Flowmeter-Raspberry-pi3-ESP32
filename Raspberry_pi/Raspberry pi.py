import time
import pigpio

pi = pigpio.pi() # Connect to local Pi.

#This package makes the raspberry pi generate high frequencies ( in MHz) by using the hardware clock of the raspberry 
#The usual PWM function doesn't allow that 


while true
    pi.hardware_clock(18, 1000000) # Generate square wave of 1MHz frequency on the PWM pin 18 connected to the transducer 1 
    pi.hardware_clock(12, 1000000) # Generate square wave of 1MHz frequency on the PWM pin 12 connected to the transducer 2 
    time.sleep(10)
    pi.hardware_clock(18, 0) # turn off the signal for 10 seconds
    pi.hardware_clock(12, 0) # turn off the signal for 10 seconds
    time.sleep(10) 

pi.stop() 

