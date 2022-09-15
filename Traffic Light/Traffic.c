
#include "Traffic.h"



void Traffic_Init ()

{


DIO_Init(B,Pin3,OUTPUT); //Green ped 1 B3 
 DIO_Init(C,Pin4,OUTPUT); // Red ped 1 C4
 
 DIO_Init(C,Pin5,OUTPUT); // Green 1 
 DIO_Init(C,Pin6,OUTPUT); // Yellow 1 
 DIO_Init(C,Pin7,OUTPUT); // RED 1 
 
 
 DIO_Init(B,Pin7,OUTPUT); // Green 2 
 DIO_Init(B,Pin6,OUTPUT); // yellow 2 
 DIO_Init(A,Pin4,OUTPUT); // Red 2 
  
 DIO_Init(A,Pin3,OUTPUT); // Green ped 2 A3
 DIO_Init(A,Pin2,OUTPUT); // Red ped 2   A2
 
 DIO_Init(F,Pin0,INPUT); // SW1 for ped 1 
 DIO_Init(F,Pin4,INPUT); // SW2 for ped2 


}

void Traffic_State (char State )

{
    DIO_WritePin(B,Pin3 , LOW);         //green ped1
    DIO_WritePin(C,Pin4 , LOW);         //red ped1
    
    DIO_WritePin(C,Pin5 , LOW);         //green1
    DIO_WritePin(C,Pin6 , LOW);         //yellow1
    DIO_WritePin(C,Pin7 , LOW);         // RED1
    
   
    DIO_WritePin(B,Pin7 , LOW);         //green 2
    DIO_WritePin(B,Pin6 , LOW);         //yellow 2
    DIO_WritePin(A,Pin4 , LOW);         //red2
    
    DIO_WritePin(A,Pin3 , LOW);         //green ped2
    DIO_WritePin(A,Pin2 , LOW);         //red ped 2
    
  switch(State)
  {
  case 1:
    // GREEN 1 ON PED 1 OFF      RED 2 ON PED 2 ON 
    DIO_WritePin(C,Pin4 , HIGH); // RED PED 1 
    DIO_WritePin(C,Pin5 , HIGH); // GREEN 1 
    
    DIO_WritePin(A,Pin3 , HIGH);   // green PED 2
    DIO_WritePin(A,Pin4 , HIGH);  // RED 2 

    break;
    
  case 2:
    DIO_WritePin(C,Pin6 , HIGH); //yellow 1 
    DIO_WritePin(C,Pin4 , HIGH); // RED PED1 
    
    DIO_WritePin(A,Pin3 , HIGH);  // GREEN PED 2 
    DIO_WritePin(A,Pin4 , HIGH); //RED 2 

    break;
     case 3:
    DIO_WritePin(C,Pin7 , HIGH); //RED 1 
    DIO_WritePin(B,Pin3 , HIGH); // GREEN PED1 
    
    DIO_WritePin(A,Pin3 , HIGH);  // GREEN PED 2 
    DIO_WritePin(A,Pin4 , HIGH); //RED 2 

    break;
    
  case 4:
    DIO_WritePin(C,Pin7 , HIGH); //RED 1 
    DIO_WritePin(B,Pin3 , HIGH); // GREEN PED1 
    
    DIO_WritePin(B,Pin7 , HIGH);  // GREEN  2 
    DIO_WritePin(A,Pin2 , HIGH); //PED RED 2

    break;
    
  case 5:
    DIO_WritePin(C,Pin7 , HIGH); //RED 1 
    DIO_WritePin(B,Pin3 , HIGH); // GREEN PED1 
    
    DIO_WritePin(B,Pin6 , HIGH);  // yellow 2 
    DIO_WritePin(A,Pin2 , HIGH); //PED RED 2

 
    break;
    case 6:
    DIO_WritePin(C,Pin7 , HIGH); //RED 1 
    DIO_WritePin(B,Pin3 , HIGH); // GREEN PED1 
    
    DIO_WritePin(A,Pin4 , HIGH);  // Red 2 
    DIO_WritePin(A,Pin3 , HIGH); //PED Green 2
      break;
    
  }





}