#include "mbed.h"
#include "ulcd.h"

using namespace std::chrono;

DigitalIn mypin_down(PC_2);
DigitalIn mypin_up(PC_3);
DigitalIn mypin_select(PC_4);





Thread thread;
EventQueue queue(32 * EVENTS_EVENT_SIZE);



int main()
 {
     int j;
    int select=1;
   // Optional: set mode as PullUp/PullDown/PullNone/OpenDrain
   mypin_down.mode(PullNone);
   mypin_up.mode(PullNone);
   mypin_select.mode(PullNone);
   //thread.start(callback(&queue, &EventQueue::dispatch_forever));
   // press the button and see the console / led change
   while (1)
    {    
        if (mypin_down==0)
            select++;
        if(mypin_up==0)
            select--;
        if(select>3)
            select=1;
        if(select<1)
            select=3;
        if(mypin_select==0){
            if(select==1){
                j=77;
                break;
            }

            else if(select==2){
                j=1;
                break;
            }

            else if(select==3){
                j=3;
                break;
            }
        }

    
        ulcd_display(select);
        
   }
    wave(j);
}

