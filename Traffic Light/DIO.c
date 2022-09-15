#include "DIO.h"

void DIO_Init(uint8 Port,uint8 pin,uint8 dir)
{
  

  switch(Port)
  {
    
  case A:
    SYSCTL_RCGCGPIO_R |= 0b0000001;
  while((SYSCTL_PRGPIO_R&0b0000001) == 0){};
    GPIO_PORTA_LOCK_R = 0x4C4F434B;
    GPIO_PORTA_CR_R = 0xFF;
    
    if(dir==OUTPUT)
    SET_BIT(GPIO_PORTA_DIR_R ,pin);
    else if(dir==INPUT)
    {
      CLEAR_BIT( GPIO_PORTA_DIR_R,pin);
      SET_BIT( GPIO_PORTA_PUR_R,pin);

    }
    GPIO_PORTA_DEN_R = 0xFF;
    break;
  case B:
    SYSCTL_RCGCGPIO_R |= 0b00010;
  while((SYSCTL_PRGPIO_R&0b000010) == 0){};
    GPIO_PORTB_LOCK_R = 0x4C4F434B;
    GPIO_PORTB_CR_R = 0xFF;
   if(dir==OUTPUT)
    SET_BIT(GPIO_PORTB_DIR_R ,pin);
    else if(dir==INPUT)
    {
      CLEAR_BIT( GPIO_PORTB_DIR_R,pin);
      SET_BIT( GPIO_PORTB_PUR_R,pin);

    }
    GPIO_PORTB_DEN_R = 0xFF;
    break;
  case C:
     SYSCTL_RCGCGPIO_R |= 0b000100;
  while((SYSCTL_PRGPIO_R&0b0000100) == 0){}; 
    GPIO_PORTC_LOCK_R = 0x4C4F434B;
    GPIO_PORTC_CR_R = 0xFF; 
   if(dir==OUTPUT)
    SET_BIT(GPIO_PORTC_DIR_R ,pin);
    else if(dir==INPUT)
    {
      CLEAR_BIT( GPIO_PORTC_DIR_R,pin);
      SET_BIT( GPIO_PORTC_PUR_R,pin);

    }
    GPIO_PORTC_DEN_R = 0xFF;
    break;
  case D:
     SYSCTL_RCGCGPIO_R |= 0b0001000;
  while((SYSCTL_PRGPIO_R&0b00001000) == 0){};
    GPIO_PORTD_LOCK_R = 0x4C4F434B;
    GPIO_PORTD_CR_R = 0xFF;
   if(dir==OUTPUT)
    SET_BIT(GPIO_PORTD_DIR_R ,pin);
    else if(dir==INPUT)
    {
      CLEAR_BIT( GPIO_PORTD_DIR_R,pin);
      SET_BIT( GPIO_PORTD_PUR_R,pin);

    }
    GPIO_PORTD_DEN_R = 0xFF;
    break;
  case E:
     SYSCTL_RCGCGPIO_R |= 0x00010;
  while((SYSCTL_PRGPIO_R&0x000010) == 0){};    
    GPIO_PORTE_LOCK_R = 0x4C4F434B;
    GPIO_PORTE_CR_R = 0x3F;
    if(dir==OUTPUT)
    SET_BIT(GPIO_PORTE_DIR_R ,pin);
    else if(dir==INPUT)
    {
      CLEAR_BIT( GPIO_PORTE_DIR_R,pin);
      SET_BIT( GPIO_PORTE_PUR_R,pin);

    }
    GPIO_PORTE_DEN_R = 0x3F;
    break;
  case F:
      SYSCTL_RCGCGPIO_R |= 0x00020;
  while((SYSCTL_PRGPIO_R&0x00020) == 0){};  
    GPIO_PORTF_LOCK_R = 0x4C4F434B;
    GPIO_PORTF_CR_R = 0x1F;
   if(dir==OUTPUT)
    SET_BIT(GPIO_PORTF_DIR_R ,pin);
    else if(dir==INPUT)
    {
      CLEAR_BIT( GPIO_PORTF_DIR_R,pin);
      SET_BIT( GPIO_PORTF_PUR_R,pin);

    }
    GPIO_PORTF_DEN_R = 0x1F;
    break;
  }
  
}
void DIO_WritePin(uint8 Port,uint8 pin , uint8 Value)
{ 
  
  if (Value == LOW)
  {  switch(Port)
  {

  case A:
     CLEAR_BIT( GPIO_PORTA_DATA_R,pin);
    break;
  case B:
     CLEAR_BIT( GPIO_PORTB_DATA_R,pin);
    break;
  case C:
      CLEAR_BIT( GPIO_PORTC_DATA_R,pin);
    break;
  case D:
      CLEAR_BIT( GPIO_PORTD_DATA_R,pin);
    break;
  case E:
     CLEAR_BIT( GPIO_PORTE_DATA_R,pin);
    break;
  case F:
     CLEAR_BIT( GPIO_PORTF_DATA_R,pin);
    break;
  }
  
  
  }
  else if (Value == HIGH)
  { 
    switch(Port)
  {

  case A:
     SET_BIT( GPIO_PORTA_DATA_R,pin);
    break;
  case B:
     SET_BIT( GPIO_PORTB_DATA_R,pin);
    break;
  case C:
      SET_BIT( GPIO_PORTC_DATA_R,pin);
    break;
  case D:
     SET_BIT( GPIO_PORTD_DATA_R,pin);
    break;
  case E:
    SET_BIT( GPIO_PORTE_DATA_R,pin);
    break;
  case F:
     SET_BIT( GPIO_PORTF_DATA_R,pin);
    break;
  }
  }
  
}
uint8 DIO_ReadPin(uint8 Port , uint8 pin)
{
    uint8 Bit;
  switch(Port)
  {

  case A:
     Bit= GET_BIT(GPIO_PORTA_DATA_R,pin); 
    break;
  case B:
     Bit= GET_BIT(GPIO_PORTB_DATA_R,pin); 
    break;
  case C:
     Bit= GET_BIT(GPIO_PORTC_DATA_R,pin); 
    break;
  case D:
     Bit= GET_BIT(GPIO_PORTD_DATA_R,pin); 
    break;
  case E:
    Bit= GET_BIT(GPIO_PORTE_DATA_R,pin); 
    break;
  case F:
    Bit= GET_BIT(GPIO_PORTF_DATA_R,pin);
    break;
  }
 
  return Bit;
}

void DIO_TogglePin(uint8 Port , uint8 pin)
{
  switch(Port)
  {

  case A:
      GPIO_PORTA_DATA_R^=pin;
    break;
  case B:
      GPIO_PORTB_DATA_R^=pin;
    break;
  case C:
      GPIO_PORTC_DATA_R^=pin;
    break;
  case D:
      GPIO_PORTD_DATA_R^=pin;
    break;
  case E:
      GPIO_PORTE_DATA_R^=pin;
    break;
  case F:
      GPIO_PORTF_DATA_R^=pin;
    break;
  }
}
