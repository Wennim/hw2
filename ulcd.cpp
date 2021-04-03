#include "ulcd.h"
#include "uLCD_4DGL.h"
uLCD_4DGL uLCD(D1, D0, D2); // serial tx, serial rx, reset pin;
AnalogOut  aout(PA_4);
AnalogIn Ain(A0);
AnalogOut Aout(PA_5);
float ADCdata[96];


void ulcd_display(int i){
if(i==1){

// basic printf demo = 16 by 18 characters on screen
    uLCD.text_width(2.5); //4X size text
    uLCD.text_height(2.5);
    uLCD.locate(0,0);
    uLCD.color(RED);
    uLCD.printf("  1Hz"); //Default Green on black text
    

    uLCD.text_width(2.5); //4X size text
    uLCD.text_height(2.5);
    uLCD.locate(0,2);
    uLCD.color(GREEN);
    uLCD.printf("  2Hz"); //Default Green on black text

    uLCD.text_width(2.5); //4X size text
    uLCD.text_height(2.5);
    uLCD.locate(0,4);
    uLCD.color(GREEN);
    uLCD.printf("  10Hz"); //Default Green on black text
    
    uLCD.text_width(2.5); //4X size text
    uLCD.text_height(2.5);
    uLCD.locate(0,6);
    uLCD.color(GREEN);
    uLCD.printf("  20Hz"); //Default Green on black text

}

else if(i ==2){
// basic printf demo = 16 by 18 characters on screen
    uLCD.text_width(2.5); //4X size text
    uLCD.text_height(2.5);
    uLCD.locate(0,0);
    uLCD.color(GREEN);
    uLCD.printf("  1Hz"); //Default Green on black text

    uLCD.text_width(2.5); //4X size text
    uLCD.text_height(2.5);
    uLCD.locate(0,2);
    uLCD.color(RED);
    uLCD.printf("  2Hz"); //Default Green on black text

    uLCD.text_width(2.5); //4X size text
    uLCD.text_height(2.5);
    uLCD.locate(0,4);
    uLCD.color(GREEN);
    uLCD.printf("  10Hz"); //Default Green on black text

     uLCD.text_width(2.5); //4X size text
    uLCD.text_height(2.5);
    uLCD.locate(0,6);
    uLCD.color(GREEN);
    uLCD.printf("  20Hz"); //Default Green on black text
}

else if(i==3){
// basic printf demo = 16 by 18 characters on screen
    uLCD.text_width(2.5); //4X size text
    uLCD.text_height(2.5);
    uLCD.locate(0,0);
    uLCD.color(GREEN);
    uLCD.printf("  1Hz"); //Default Green on black text

    uLCD.text_width(2.5); //4X size text
    uLCD.text_height(2.5);
    uLCD.locate(0,2);
    uLCD.color(GREEN);
    uLCD.printf("  2Hz"); //Default Green on black text

    uLCD.text_width(2.5); //4X size text
    uLCD.text_height(2.5);
    uLCD.locate(0,4);
    uLCD.color(RED);
    uLCD.printf("  10Hz"); //Default Green on black text

    uLCD.text_width(2.5); //4X size text
    uLCD.text_height(2.5);
    uLCD.locate(0,6);
    uLCD.color(GREEN);
    uLCD.printf("  20Hz"); //Default Green on black text
}

else if(i==4){
// basic printf demo = 16 by 18 characters on screen
    uLCD.text_width(2.5); //4X size text
    uLCD.text_height(2.5);
    uLCD.locate(0,0);
    uLCD.color(GREEN);
    uLCD.printf("  1Hz"); //Default Green on black text

    uLCD.text_width(2.5); //4X size text
    uLCD.text_height(2.5);
    uLCD.locate(0,2);
    uLCD.color(GREEN);
    uLCD.printf("  2Hz"); //Default Green on black text

    uLCD.text_width(2.5); //4X size text
    uLCD.text_height(2.5);
    uLCD.locate(0,4);
    uLCD.color(GREEN);
    uLCD.printf("  10Hz"); //Default Green on black text

    uLCD.text_width(2.5); //4X size text
    uLCD.text_height(2.5);
    uLCD.locate(0,6);
    uLCD.color(RED);
    uLCD.printf("  20Hz"); //Default Green on black text
}
}

void wave(int j){

while (1)
{
    for (float i = 0.93f; i >= 0.00; i -= j*0.0096f) {
            aout = i;
            
        ThisThread::sleep_for(10ms);
            }

}
}

void sampling(){
int i=0;
   while(i<96){
    ADCdata[i] = Ain;
    printf("%f\n", ADCdata[i]);
    Aout = ADCdata[i];
    ThisThread::sleep_for(1ms);
    i++;
  }
}

