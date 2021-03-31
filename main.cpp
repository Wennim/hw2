#include "mbed.h"
#include "ulcd.h"

using namespace std::chrono;

DigitalIn mypin_down(PC_2);
DigitalIn mypin_up(PC_4);
DigitalIn mypin_select(PC_3);
Thread thread;

int main()
 {
     int j;
    int select=1;
   // Optional: set mode as PullUp/PullDown/PullNone/OpenDrain
   mypin_down.mode(PullNone);
   mypin_up.mode(PullNone);
   mypin_select.mode(PullNone);
   // press the button and see the console / led change
   while (1)
    {    
        if (mypin_down==0)
            select++;
        //if(mypin_up==0)
            //select--;
        if(select>4)
            select=1;
        if(select<1)
            select=4;
        if(mypin_select==0){
            if(select==1){
                j=1;
                break;
            }

            else if(select==2){
                j=2;
                break;
            }

            else if(select==3){
                j=10;
                break;
            }    
            else if(select==4){
                j=11;
                break;
            }
        }

    
        ulcd_display(select);
        
   }
    thread.start(sampling);
    wave(j);
 
  
}

