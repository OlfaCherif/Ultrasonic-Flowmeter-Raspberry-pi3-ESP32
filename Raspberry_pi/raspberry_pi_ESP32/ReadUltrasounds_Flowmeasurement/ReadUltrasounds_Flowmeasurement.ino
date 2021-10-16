//ESP32 
//#include <math.h>
#include<time.h>
#define T1 33 //Analog pin on ESP32
#define T2 32 //Analog pin on ESP32
double pi=3.14;
double Diameter; //Diameter of the pipe 
double valueT1; //value of detection of transducer T1
double valueT2; //value of detection of transducer T2
unsigned long time1;
unsigned long time2;
double d;
double alpha;


void setup() {
  // put your setup code here, to run once:
Serial.begin(115200); 
pinMode(T1,INPUT);
pinMode(T2,INPUT);
}

double Debit( double time1, double time2)
{ 
unsigned long transiTime;  
double flow;

transiTime=(time2-time1)/(time1*time2);
flow= pi*Diameter*transiTime/4*sin(2*alpha);

  
}

void loop() {
  // put your main code here, to run repeatedly:


if (analogRead(T1)>1000)
{
  time1=micros();
  while (analogRead(T2)<1000)
  {}
  time2=micros();
  
}

d=Debit(time1,time2);
 # This function measure the flow depending on the reading time of ultrasounds 

Serial.print("The actual waterflow is");
Serial.println(d);


}
