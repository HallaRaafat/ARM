#include "tm4c123gh6pm.h"
#include "DIO.h"
#include "Timer.h"
#include "Systick.h"
#include "Traffic.h"
#include "Interrupts.h"
#include <stdio.h>
#include "stdint.h"
#include "stdbool.h"
volatile int flag=0,status=1;
void SysTick_Handler ()
{flag++;
 if (flag<5) status=1;
    else if (flag<7)status=2;
    else if (flag<8)status=3;
    else if (flag<13)status=4;
     else if (flag<15)status=5;
      else if (flag<16)status=6;
      else flag=0;
 }


int main()
{
  
  // Initializaations 
  // GPIO
  Traffic_Init ();
  
 
  
  //TIMERS 
  Systick_Init();
  
  // intrupts presid 
  
  Interrupts_Init();
   // __asm("CPSIE I");



   
  while (1) // loop
  {
   if (flag<5)
   {
   Traffic_State (1);
   Sys_Delay (5-flag );
   
   }
   
 
    else if (flag<7)
    {
      
      Traffic_State (2);
   Sys_Delay (7-flag );
    }
    else if (flag<8)
    {Traffic_State (3);
   Sys_Delay (8-flag );
    }
    else if (flag<13)
    {
    Traffic_State (4);
   Sys_Delay (13-flag );
    }
     else if (flag<15)
     {
     Traffic_State (5);
   Sys_Delay (15-flag );}
      else if (flag<16)
      {Traffic_State (6);
   Sys_Delay (16-flag );}
      else flag=0;
     
  }
  
  return 0;
}
 void GPIOF_Handler(void)
{
  if(GET_BIT(GPIO_PORTF_MIS_R,0))       //interrupt caused by pin 0     (ped1 pressed)
  { 
    
   Traffic_State (status);
    DIO_WritePin(B,Pin3 , HIGH);         //green ped1
    DIO_WritePin(C,Pin4 , LOW);         //red ped1
    
    DIO_WritePin(C,Pin5 , LOW);         //green1
    DIO_WritePin(C,Pin6 , LOW);         //yellow1
    DIO_WritePin(C,Pin7 , HIGH);         // RED1
    Sys_Delay (1 );
    flag--;
    
   Traffic_State (status);
    DIO_WritePin(B,Pin3 , HIGH);         //green ped1
    DIO_WritePin(C,Pin4 , LOW);         //red ped1
    
    DIO_WritePin(C,Pin5 , LOW);         //green1
    DIO_WritePin(C,Pin6 , LOW);         //yellow1
    DIO_WritePin(C,Pin7 , HIGH);         // RED1
     Sys_Delay (1 );
     flag--;
     
     SET_BIT(GPIO_PORTF_ICR_R ,0);
 
  //  Traffic_set(Cstate); 
  }
  else if (GET_BIT(GPIO_PORTF_MIS_R,4)) //interrupt caused by pin 4
  {
   
   Traffic_State (status);
    DIO_WritePin(A,Pin3 , HIGH);         //green ped2
    DIO_WritePin(A,Pin2 , LOW);         //red ped2
    
    DIO_WritePin(B,Pin7 , LOW);         //green2
    DIO_WritePin(B,Pin6 , LOW);         //yellow2
    DIO_WritePin(A,Pin4 , HIGH);         // RED2
    Sys_Delay (1 );
    flag--;
    
   Traffic_State (status);
     DIO_WritePin(A,Pin3 , HIGH);         //green ped2
    DIO_WritePin(A,Pin2 , LOW);         //red ped2
    
    DIO_WritePin(B,Pin7 , LOW);         //green2
    DIO_WritePin(B,Pin6 , LOW);         //yellow2
    DIO_WritePin(A,Pin4 , HIGH);         // RED2
     Sys_Delay (1 );
     flag--;
     
   SET_BIT(GPIO_PORTF_ICR_R ,4);
  }
}
