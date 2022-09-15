#ifndef DIO_
#define DIO_

#include "std.h"
#include "tm4c123gh6pm.h"
#include "bitwise_operations.h"

#define OUTPUT 1
#define INPUT 0
#define LOW 0 
#define HIGH 1 

#define Pin0 0
#define Pin1 1
#define Pin2 2
#define Pin3 3
#define Pin4 4
#define Pin5 5
#define Pin6 6
#define Pin7 7


void DIO_Init(uint8 Port,uint8 pin,uint8 dir);
void DIO_WritePin(uint8 Port,uint8 pin , uint8 Value);
uint8 DIO_ReadPin(uint8 Port , uint8 pin);
void DIO_TogglePin(uint8 Port , uint8 pin);
enum letters{A,B,C,D,E,F};
#endif