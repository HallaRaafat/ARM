#include "Interrupts.h"





void Interrupts_Init()
{
SET_BIT(NVIC_EN0_R ,30); //PORT F -> 30 IRQ

SET_BIT(GPIO_PORTF_IM_R ,0);
SET_BIT(GPIO_PORTF_IM_R ,4);

 CLEAR_BIT(GPIO_PORTF_IS_R,0);         //interrupt sensing: edge sensing 
 CLEAR_BIT(GPIO_PORTF_IS_R,4);

 SET_BIT(GPIO_PORTF_IEV_R,0);          //interrupt trigger: RISING EDGE 
SET_BIT(GPIO_PORTF_IEV_R,4);
  


}