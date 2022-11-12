#include <Servo.h>
Servo ServoV;
Servo ServoV1;
#include<Stepper.h>

// Analog Pins for LDR'S
int tl = A0;
int tr = A1;
int bl = A2;
int br = A3;

const int stepsperrevolution = 512  ;

Stepper mystepperH = Stepper(stepsperrevolution , 8 , 10 , 9 , 11);

const int ref1 = 100;

void setup()
{
Serial.begin(9600);
pinMode(A0,INPUT);
pinMode(A1,INPUT);
pinMode(A2,INPUT);
pinMode(A3,INPUT);
ServoV.attach(12);
mystepperH.setSpeed(100);

ServoV.write(90);
}

void loop()
{
int avt= (tr + tl) / 2; // average value top
int avb = (bl + br) / 2; // average value bottom
int avl = (tl + bl) / 2; // average value left
int avr = (tr + br) / 2; // average value right
int dvert = avt - avb;
int dhori = avl - avr;

if  (-1*ref1 > dvert || dvert > ref1) // check if the difference is in the ref1 else change vertical angle
{
if (avt > avb) //if average resistance on top is greater than on bottom
{
avb=avb+1;
ServoV.write(avb);
}
else if(avt<avb);
{
avt=avt+1;
ServoV.write(avt);
}
}
else if(-1*ref1 > dhori || dhori > ref1) // check if the difference is in the ref1 else change vertical angle
{
if (avr > avl) //if average resistance on top is greater than on bottom
{
mystepperH.step(stepsperrevolution);
}
else //avg resistance on bottom is greater than on top
{
mystepperH.step(-stepsperrevolution);
}
}


ServoV1.attach(13);
if  (-1*ref1 > dvert || dvert > ref1) // check if the difference is in the ref1 else change vertical angle
{
if (avt > avb) //if average resistance on top is greater than on bottom
{
avb=avb+1;
ServoV1.write(avb);
}
else if(avt<avb);
{
avt=avt+1;
ServoV1.write(avt);
}
}
}





 
