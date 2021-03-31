#include "ulcd.h"
#include "uLCD_4DGL.h"
uLCD_4DGL uLCD(D1, D0, D2); // serial tx, serial rx, reset pin;
AnalogOut  aout(PA_4);
AnalogIn Ain(A0);
AnalogOut Aout(PA_5);
float ADCdata;


void ulcd_display(int i){
if (i==0){
// basic printf demo = 16 by 18 characters on screen
    uLCD.text_width(2.5); //4X size text
    uLCD.text_height(2.5);
    uLCD.locate(0,2);
    uLCD.color(GREEN);
    uLCD.printf("  100Hz"); //Default Green on black text

    uLCD.text_width(2.5); //4X size text
    uLCD.text_height(2.5);
    uLCD.locate(0,4);
    uLCD.color(GREEN);
    uLCD.printf("  200Hz"); //Default Green on black text
  
    uLCD.text_width(2.5); //4X size text
    uLCD.text_height(2.5);
    uLCD.locate(0,6);
    uLCD.color(GREEN);
    uLCD.printf("  300Hz"); //Default Green on black text
}

     
else if(i==1){

// basic printf demo = 16 by 18 characters on screen
    uLCD.text_width(2.5); //4X size text
    uLCD.text_height(2.5);
    uLCD.locate(0,2);
    uLCD.color(RED);
    uLCD.printf("  100Hz"); //Default Green on black text
  
    uLCD.text_width(2.5); //4X size text
    uLCD.text_height(2.5);
    uLCD.locate(0,4);
    uLCD.color(GREEN);
    uLCD.printf("  200Hz"); //Default Green on black text

    uLCD.text_width(2.5); //4X size text
    uLCD.text_height(2.5);
    uLCD.locate(0,6);
    uLCD.color(GREEN);
    uLCD.printf("  300Hz"); //Default Green on black text
     

}

else if(i ==2){
// basic printf demo = 16 by 18 characters on screen
    uLCD.text_width(2.5); //4X size text
    uLCD.text_height(2.5);
    uLCD.locate(0,2);
    uLCD.color(GREEN);
    uLCD.printf("  100Hz"); //Default Green on black text

    uLCD.text_width(2.5); //4X size text
    uLCD.text_height(2.5);
    uLCD.locate(0,4);
    uLCD.color(RED);
    uLCD.printf("  200Hz"); //Default Green on black text

    uLCD.text_width(2.5); //4X size text
    uLCD.text_height(2.5);
    uLCD.locate(0,6);
    uLCD.color(GREEN);
    uLCD.printf("  300Hz"); //Default Green on black text
}

else if(i==3){
// basic printf demo = 16 by 18 characters on screen
    uLCD.text_width(2.5); //4X size text
    uLCD.text_height(2.5);
    uLCD.locate(0,2);
    uLCD.color(GREEN);
    uLCD.printf("  100Hz"); //Default Green on black text

    uLCD.text_width(2.5); //4X size text
    uLCD.text_height(2.5);
    uLCD.locate(0,4);
    uLCD.color(GREEN);
    uLCD.printf("  200Hz"); //Default Green on black text

    uLCD.text_width(2.5); //4X size text
    uLCD.text_height(2.5);
    uLCD.locate(0,6);
    uLCD.color(RED);
    uLCD.printf("  300Hz"); //Default Green on black text
}
}

void wave(int j){

while (1)
{
    for (float i = 0.96f; i >= 0.00; i -= 0.0096f) {
            aout = i;
            
            ThisThread::sleep_for(1ms/j);
            }
            aout = 0.00f;

}
}

void sampling(){

   while(1){
    ADCdata = Ain;
    printf("%f\r\n", ADCdata);
    Aout = ADCdata;
    ThisThread::sleep_for(1ms);
  }

}