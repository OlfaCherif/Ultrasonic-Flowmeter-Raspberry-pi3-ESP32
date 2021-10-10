import RPi.GPIO as GPIO

pin_Transducer1=12
pin_Transducer2=18

GPIO.setmode(GPIO.BCM)

GPIO.setup(pin_Transducer1,GPIO.OUT) 
GPIO.setup(pin_Transducer2,GPIO.OUT) 

T1_pwm = GPIO.PWM(pin_Transducer1,1000)		# PWM with 1Khz frequency
T2_pwm = GPIO.PWM(pin_Transducer2,1000)		# PWM with 1Khz frequency
T1_pwm.start(5) #start PWM of required Duty Cycle 5%
T2_pwm.start(5)