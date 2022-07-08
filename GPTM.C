#include "GPTM_reg.h"
#include"lstd.h"
#include "GPTM_config.h"

/*we cast that array --> void because we can use it as 16Bit timer if it is NOT in the concatenated mode
 * Or we can use it as 32Bit timer if it is in the concatenated mode
 * So there is no need to waste memory and create 2 arrays
 * only create one void pointer and re-use it
 *
 * NOTE: that is done with timer A registers only there is no need to to that with timer B registers */
volatile void* const GPTM_16_32_BitTimerA_IntervalLoad[6]={
      (void*)GPTM_16_32BitTimer0AIntervalLoad,
      (void*)GPTM_16_32BitTimer1AIntervalLoad,
      (void*)GPTM_16_32BitTimer2AIntervalLoad,
      (void*)GPTM_16_32BitTimer3AIntervalLoad,
      (void*)GPTM_16_32BitTimer4AIntervalLoad,
      (void*)GPTM_16_32BitTimer5AIntervalLoad
};


/*we cast that array --> void because we can use it as 32Bit timer if it is NOT in the concatenated mode
 * Or we can use it as 64Bit timer if it is in the concatenated mode
 * So there is no need to waste memory and create 2 arrays
 * only create one void pointer and re-use it by casting
 *
 * NOTE:that is done with timer A registers only there is no need to to that with timer B registers*/
volatile void* const GPTM_32_64_BitTimerA_IntervalLoad[6]={
       (void*)GPTM_32_64BitTimer0AIntervalLoad,
       (void*)GPTM_32_64BitTimer1AIntervalLoad,
       (void*)GPTM_32_64BitTimer2AIntervalLoad,
       (void*)GPTM_32_64BitTimer3AIntervalLoad,
       (void*)GPTM_32_64BitTimer4AIntervalLoad,
       (void*)GPTM_32_64BitTimer5AIntervalLoad
};


volatile u16_t* const GPTM_16BitTimerB_IntervalLoad[6]={
      (u16_t*)GPTM_16BitTimer0BIntervalLoad,
      (u16_t*)GPTM_16BitTimer1BIntervalLoad,
      (u16_t*)GPTM_16BitTimer2BIntervalLoad,
      (u16_t*)GPTM_16BitTimer3BIntervalLoad,
      (u16_t*)GPTM_16BitTimer4BIntervalLoad,
      (u16_t*)GPTM_16BitTimer5BIntervalLoad
};

volatile u32_t* const GPTM_32BitTimerB_IntervalLoad[6]={

     (u32_t*)GPTM_32BitTimer0BIntervalLoad,
     (u32_t*)GPTM_32BitTimer1BIntervalLoad,
     (u32_t*)GPTM_32BitTimer2BIntervalLoad,
     (u32_t*)GPTM_32BitTimer3BIntervalLoad,
     (u32_t*)GPTM_32BitTimer4BIntervalLoad,
     (u32_t*)GPTM_32BitTimer5BIntervalLoad,

};

 volatile GPTMCFG_Reg* const GPTM_32_64BitTimer_ConfigurationRegisters[6]={
        (GPTMCFG_Reg *)GPTM_64BitTimer0Configuration,
        (GPTMCFG_Reg *)GPTM_64BitTimer1Configuration,
        (GPTMCFG_Reg *)GPTM_64BitTimer2Configuration,
        (GPTMCFG_Reg *)GPTM_64BitTimer3Configuration,
        (GPTMCFG_Reg *)GPTM_64BitTimer4Configuration,
        (GPTMCFG_Reg *)GPTM_64BitTimer5Configuration

};

 volatile GPTMCFG_Reg* const GPTM_16_32BitTimer_ConfigurationRegisters[6]={
        (GPTMCFG_Reg *)GPTM_32BitTimer0Configuration,
        (GPTMCFG_Reg *)GPTM_32BitTimer1Configuration,
        (GPTMCFG_Reg *)GPTM_32BitTimer2Configuration,
        (GPTMCFG_Reg *)GPTM_32BitTimer3Configuration,
        (GPTMCFG_Reg *)GPTM_32BitTimer4Configuration,
        (GPTMCFG_Reg *)GPTM_32BitTimer5Configuration

};


//create 2d array
volatile GPTMTMR_Reg* const GPTM_TimerMode[4][6]={

   { (GPTMTMR_Reg*)GPTM_16_32BitTimer0AMode,
     (GPTMTMR_Reg*)GPTM_16_32BitTimer1AMode,
     (GPTMTMR_Reg*)GPTM_16_32BitTimer2AMode,
     (GPTMTMR_Reg*)GPTM_16_32BitTimer3AMode,
     (GPTMTMR_Reg*)GPTM_16_32BitTimer4AMode,
     (GPTMTMR_Reg*)GPTM_16_32BitTimer5AMode
   },

   { (GPTMTMR_Reg*)GPTM_32_64BitTimer0AMode,
     (GPTMTMR_Reg*)GPTM_32_64BitTimer1AMode,
     (GPTMTMR_Reg*)GPTM_32_64BitTimer2AMode,
     (GPTMTMR_Reg*)GPTM_32_64BitTimer3AMode,
     (GPTMTMR_Reg*)GPTM_32_64BitTimer4AMode,
     (GPTMTMR_Reg*)GPTM_32_64BitTimer5AMode
   },

{   (GPTMTMR_Reg*)GPTM_16BitTimer0BMode,
    (GPTMTMR_Reg*)GPTM_16itTimer1BMode,
    (GPTMTMR_Reg*)GPTM_16BitTimer2BMode,
    (GPTMTMR_Reg*)GPTM_16BitTimer3BMode,
    (GPTMTMR_Reg*)GPTM_16BitTimer4BMode,
    (GPTMTMR_Reg*)GPTM_16BitTimer5BMode
 },

 {  (GPTMTMR_Reg*)GPTM_32BitTimer0BMode,
    (GPTMTMR_Reg*)GPTM_32BitTimer1BMode,
    (GPTMTMR_Reg*)GPTM_32BitTimer2BMode,
    (GPTMTMR_Reg*)GPTM_32BitTimer3BMode,
    (GPTMTMR_Reg*)GPTM_32BitTimer4BMode,
    (GPTMTMR_Reg*)GPTM_32BitTimer5BMode
 }

};


void GPTM_Initialization(GPTM_Channel_t Channel, GPTM_ConfigurationChannel_t* ConfigurationChannel,GPTM_TimerType_t TimerType){

    (*GPTM_TimerMode[TimerType][Channel]).bits.TimerCountDirection= ConfigurationChannel->CountingDirection;
    (*GPTM_TimerMode[TimerType][Channel]).bits.TimerMode= ConfigurationChannel->Mode;
    (*GPTM_TimerMode[TimerType][Channel]).bits.TimerMatchInterruptEnable=ConfigurationChannel->MatchInterruptMode;


}

//to do : GPTM_Delay_Polling()
//to do : GPTM_Delay_Interrupt()
//to do : GPTM_Delay_DMA()
