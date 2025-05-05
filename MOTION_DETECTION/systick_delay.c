/*
Program   : 2)  Initialize Sys Tick interrupt handler with 1 m sec delay and create a timer global variable to initialize zero. and increment timer global variable inside Sys Tick Handler. In the super loop, wait until the timer global variable reaches 100, once it reaches 100 then toggle RED LED and clear the timer global variable.


File_Name : main.c
Author    : Raghuaran
Date      : 
Board     : RAAYAN MINI
Version   : 4.0
Controller: STM32F401RBT6
Pins used : pb13
*/

#include "stm32f401rbt6.h"
#define MAX_32       2147483647
 
volatile unsigned  int Tick=0;//declare a global variable ticks
void SysTick_Handler() //SysTick Timer interrupt Handler
{
if(Tick==MAX_32)
{
Tick=0;//assign zero
}
Tick++;              //ticks increment for every 1msec 
}



void KM_mdelay(unsigned int delay)
{
unsigned int delay_until;//declare delay_until variable
if(Tick+delay>=MAX_32)
{
Tick=0;//assign to zero
}
  delay_until=Tick+delay;//add both ticks count and passing argument delay
while(Tick<delay_until);//wait untile ticks reaches to delay until

}


void Systick_init(void)
{
    /* Phase 1: Device Initialization */
		

		
    /* Phase 2: Device Configuration */
		STK_CTRL |=0X07;
	
		STK_VAL |= 0X01<<2;
		STK_LOAD =16000;
	
	
		}
		