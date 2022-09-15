



TIMER0_CFG_R  

TIMER0_TAMR_R          

TIMER0_CTL_R          
      
 TIMER0_IMR_R   
TIMER0_RIS_R           
 TIMER0_MIS_R           
TIMER0_ICR_R      
 
#define TIMER0_TAILR_R          
 
#define TIMER0_TAMATCHR_R       (*((volatile unsigned long *)0x40030030))
#define TIMER0_TBMATCHR_R       (*((volatile unsigned long *)0x40030034))
#define TIMER0_TAPR_R           (*((volatile unsigned long *)0x40030038))
#define TIMER0_TBPR_R           (*((volatile unsigned long *)0x4003003C))
#define TIMER0_TAPMR_R          (*((volatile unsigned long *)0x40030040))
#define TIMER0_TBPMR_R          (*((volatile unsigned long *)0x40030044))
#define TIMER0_TAR_R            (*((volatile unsigned long *)0x40030048))
#define TIMER0_TBR_R            (*((volatile unsigned long *)0x4003004C))
#define TIMER0_TAV_R            (*((volatile unsigned long *)0x40030050))
         
#define TIMER0_RTCPD_R          (*((volatile unsigned long *)0x40030058))
#define TIMER0_TAPS_R           (*((volatile unsigned long *)0x4003005C))
      
#define TIMER0_TAPV_R           (*((volatile unsigned long *)0x40030064))
  


void Timer_Init ()
{
// RCGCTIMER clock for wanted timer 
  
  SYSCTL_RCGCTIMER_R |=0x1;
 // Timer disabled in CTL 
  TIMER0_CTL_R   =0x00;
  // CFG 32 =0 default  16 = 0b100
  TIMER0_CFG_R =0b100;
  //    TnMR one shot or periodic 
  TIMER0_TAMR_R =0x1;
  // ILR value
  TIMER0_TAILR_R =0x00f42400; // 16,000,000
  // IMR intrurpt mask
  // TnEN CTL
  // RIS 
  // TnMIE 



}
void Timer_delay (int period)
{


}

