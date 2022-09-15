#include "Systick.h"



void Systick_Init()
{
  
  
  // disable CTL 16 -> COUNT    2 -> CLK  1-> INT EN  0-> ENABLE
NVIC_ST_CTRL_R =0x00;
// LOad = 1 sec 
NVIC_ST_RELOAD_R = 15999999;
//enable 
NVIC_ST_CTRL_R =0x07;
NVIC_ST_CURRENT_R  =0;



}
void Sys_Delay (int value )
{
for (int i=0 ; i<value ; i++)
{
   NVIC_ST_CURRENT_R  =0;
   while ((NVIC_ST_CTRL_R & 0x10000)==0);
   
}
}


