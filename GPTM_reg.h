
#ifndef GPTM_REG_H_
#define GPTM_REG_H_

#include "lstd.h"

#define GPTM_32BitTimer0BaseAdd   0x40030000
#define GPTM_32BitTimer1BaseAdd   0x40031000
#define GPTM_32BitTimer2BaseAdd   0x40032000
#define GPTM_32BitTimer3BaseAdd   0x40033000
#define GPTM_32BitTimer4BaseAdd   0x40034000
#define GPTM_32BitTimer5BaseAdd   0x40035000

#define GPTM_64BitTimer0BaseAdd   0x40036000
#define GPTM_64BitTimer1BaseAdd   0x40037000
#define GPTM_64BitTimer2BaseAdd   0x4004C000
#define GPTM_64BitTimer3BaseAdd   0x4004D000
#define GPTM_64BitTimer4BaseAdd   0x4004E000
#define GPTM_64BitTimer5BaseAdd   0x4004F000

#define GPTMTAILR_Offset          0x028
#define GPTMTBILR_Offset          0x02C
#define GPTMTAMR_Offset           0x004
#define GPTMTBMR_Offset           0x008

typedef union {

    struct{

     u32_t  GPTMTimerAEnable:1;
     u32_t  GPTMTimerAStallEnable:1;
     u32_t  GPTMTimerAEventMode:1;
     u32_t  GPTMRTCStallEnable:1;

    }bits;

    u32_t Register;
}GPTMCTL_reg;


typedef union {

    struct{

        u32_t Configuration:3;
        u32_t :29;

    }bits;

    u32_t Register;
}GPTMCFG_Reg;


typedef union {

    struct{

        u32_t TimerMode :2;
        u32_t TimerCaptureMode:1;
        u32_t TimerAlternateModeSelect:1;
        u32_t TimerCountDirection:1;
        u32_t TimerMatchInterruptEnable:1;
        u32_t TimerWaitOnTrigger:1;
        u32_t TimerSnapShotMode:1;
        u32_t TimerIntervalLoadWrite:1;
        u32_t TimerPWMInterruptEnable:1;
        u32_t TimerMatchRegisterUpdate:1;
        u32_t TimerPWMLegacyOperation:1;
        u32_t  :20;

    }bits;

    u32_t Register;

}GPTMTMR_Reg;

/***************************************** IntervalLoadA 64bit or 16bit **************************************************************/
#define GPTM_16_32BitTimer0AIntervalLoad    ( (volatile void*) (GPTM_32BitTimer0BaseAdd + GPTMTAILR_Offset)  )
#define GPTM_16_32BitTimer1AIntervalLoad    ( (volatile void*) (GPTM_32BitTimer1BaseAdd + GPTMTAILR_Offset)  )
#define GPTM_16_32BitTimer2AIntervalLoad    ( (volatile void*) (GPTM_32BitTimer2BaseAdd + GPTMTAILR_Offset)  )
#define GPTM_16_32BitTimer3AIntervalLoad    ( (volatile void*) (GPTM_32BitTimer3BaseAdd + GPTMTAILR_Offset)  )
#define GPTM_16_32BitTimer4AIntervalLoad    ( (volatile void*) (GPTM_32BitTimer4BaseAdd + GPTMTAILR_Offset)  )
#define GPTM_16_32BitTimer5AIntervalLoad    ( (volatile void*) (GPTM_32BitTimer5BaseAdd + GPTMTAILR_Offset)  )

/***************************************** IntervalLoadA 64bit or 16bit **************************************************************/
#define GPTM_32_64BitTimer0AIntervalLoad    ( (volatile void*) (GPTM_64BitTimer0BaseAdd + GPTMTAILR_Offset)  )
#define GPTM_32_64BitTimer1AIntervalLoad    ( (volatile void*) (GPTM_64BitTimer1BaseAdd + GPTMTAILR_Offset)  )
#define GPTM_32_64BitTimer2AIntervalLoad    ( (volatile void*) (GPTM_64BitTimer2BaseAdd + GPTMTAILR_Offset)  )
#define GPTM_32_64BitTimer3AIntervalLoad    ( (volatile void*) (GPTM_64BitTimer3BaseAdd + GPTMTAILR_Offset)  )
#define GPTM_32_64BitTimer4AIntervalLoad    ( (volatile void*) (GPTM_64BitTimer4BaseAdd + GPTMTAILR_Offset)  )
#define GPTM_32_64BitTimer5AIntervalLoad    ( (volatile void*) (GPTM_64BitTimer5BaseAdd + GPTMTAILR_Offset)  )

/***************************************** IntervalLoadB 16bit**************************************************************/
#define GPTM_16BitTimer0BIntervalLoad    ( (volatile u16_t*) (GPTM_32BitTimer0BaseAdd + GPTMTBILR_Offset)  )
#define GPTM_16BitTimer1BIntervalLoad    ( (volatile u16_t*) (GPTM_32BitTimer1BaseAdd + GPTMTBILR_Offset)  )
#define GPTM_16BitTimer2BIntervalLoad    ( (volatile u16_t*) (GPTM_32BitTimer2BaseAdd + GPTMTBILR_Offset)  )
#define GPTM_16BitTimer3BIntervalLoad    ( (volatile u16_t*) (GPTM_32BitTimer3BaseAdd + GPTMTBILR_Offset)  )
#define GPTM_16BitTimer4BIntervalLoad    ( (volatile u16_t*) (GPTM_32BitTimer4BaseAdd + GPTMTBILR_Offset)  )
#define GPTM_16BitTimer5BIntervalLoad    ( (volatile u16_t*) (GPTM_32BitTimer5BaseAdd + GPTMTBILR_Offset)  )

/***************************************** IntervalLoadB 32bit**************************************************************/
#define GPTM_32BitTimer0BIntervalLoad    ( (volatile u32_t*) (GPTM_64BitTimer0BaseAdd + GPTMTBILR_Offset)  )
#define GPTM_32BitTimer1BIntervalLoad    ( (volatile u32_t*) (GPTM_64BitTimer1BaseAdd + GPTMTBILR_Offset)  )
#define GPTM_32BitTimer2BIntervalLoad    ( (volatile u32_t*) (GPTM_64BitTimer2BaseAdd + GPTMTBILR_Offset)  )
#define GPTM_32BitTimer3BIntervalLoad    ( (volatile u32_t*) (GPTM_64BitTimer3BaseAdd + GPTMTBILR_Offset)  )
#define GPTM_32BitTimer4BIntervalLoad    ( (volatile u32_t*) (GPTM_64BitTimer4BaseAdd + GPTMTBILR_Offset)  )
#define GPTM_32BitTimer5BIntervalLoad    ( (volatile u32_t*) (GPTM_64BitTimer5BaseAdd + GPTMTBILR_Offset)  )

/***************************************** Configuration **************************************************************/
#define GPTM_32BitTimer0Configuration     ( (volatile GPTMCFG_Reg*)(GPTM_32BitTimer0BaseAdd) )
#define GPTM_32BitTimer1Configuration     ( (volatile GPTMCFG_Reg*)(GPTM_32BitTimer1BaseAdd) )
#define GPTM_32BitTimer2Configuration     ( (volatile GPTMCFG_Reg*)(GPTM_32BitTimer2BaseAdd) )
#define GPTM_32BitTimer3Configuration     ( (volatile GPTMCFG_Reg*)(GPTM_32BitTimer3BaseAdd) )
#define GPTM_32BitTimer4Configuration     ( (volatile GPTMCFG_Reg*)(GPTM_32BitTimer4BaseAdd) )
#define GPTM_32BitTimer5Configuration     ( (volatile GPTMCFG_Reg*)(GPTM_32BitTimer5BaseAdd) )

#define GPTM_64BitTimer0Configuration     ( (volatile GPTMCFG_Reg*)(GPTM_64BitTimer0BaseAdd) )
#define GPTM_64BitTimer1Configuration     ( (volatile GPTMCFG_Reg*)(GPTM_64BitTimer1BaseAdd) )
#define GPTM_64BitTimer2Configuration     ( (volatile GPTMCFG_Reg*)(GPTM_64BitTimer2BaseAdd) )
#define GPTM_64BitTimer3Configuration     ( (volatile GPTMCFG_Reg*)(GPTM_64BitTimer3BaseAdd) )
#define GPTM_64BitTimer4Configuration     ( (volatile GPTMCFG_Reg*)(GPTM_64BitTimer4BaseAdd) )
#define GPTM_64BitTimer5Configuration     ( (volatile GPTMCFG_Reg*)(GPTM_64BitTimer5BaseAdd) )

/***************************************** Mode A **************************************************************/
#define GPTM_16_32BitTimer0AMode       ((volatile GPTMTMR_Reg*)(GPTM_32BitTimer0BaseAdd + GPTMTAMR_Offset))
#define GPTM_16_32BitTimer1AMode       ((volatile GPTMTMR_Reg*)(GPTM_32BitTimer1BaseAdd + GPTMTAMR_Offset))
#define GPTM_16_32BitTimer2AMode       ((volatile GPTMTMR_Reg*)(GPTM_32BitTimer2BaseAdd + GPTMTAMR_Offset))
#define GPTM_16_32BitTimer3AMode       ((volatile GPTMTMR_Reg*)(GPTM_32BitTimer3BaseAdd + GPTMTAMR_Offset))
#define GPTM_16_32BitTimer4AMode       ((volatile GPTMTMR_Reg*)(GPTM_32BitTimer4BaseAdd + GPTMTAMR_Offset))
#define GPTM_16_32BitTimer5AMode       ((volatile GPTMTMR_Reg*)(GPTM_32BitTimer5BaseAdd + GPTMTAMR_Offset))

#define GPTM_32_64BitTimer0AMode       ((volatile GPTMTMR_Reg*)(GPTM_64BitTimer0BaseAdd + GPTMTAMR_Offset))
#define GPTM_32_64BitTimer1AMode       ((volatile GPTMTMR_Reg*)(GPTM_64BitTimer1BaseAdd + GPTMTAMR_Offset))
#define GPTM_32_64BitTimer2AMode       ((volatile GPTMTMR_Reg*)(GPTM_64BitTimer2BaseAdd + GPTMTAMR_Offset))
#define GPTM_32_64BitTimer3AMode       ((volatile GPTMTMR_Reg*)(GPTM_64BitTimer3BaseAdd + GPTMTAMR_Offset))
#define GPTM_32_64BitTimer4AMode       ((volatile GPTMTMR_Reg*)(GPTM_64BitTimer4BaseAdd + GPTMTAMR_Offset))
#define GPTM_32_64BitTimer5AMode       ((volatile GPTMTMR_Reg*)(GPTM_64BitTimer5BaseAdd + GPTMTAMR_Offset))

/***************************************** Mode B **************************************************************/
#define GPTM_16BitTimer0BMode       ((volatile GPTMTMR_Reg*)(GPTM_32BitTimer0BaseAdd + GPTMTBMR_Offset))
#define GPTM_16itTimer1BMode        ((volatile GPTMTMR_Reg*)(GPTM_32BitTimer1BaseAdd + GPTMTBMR_Offset))
#define GPTM_16BitTimer2BMode       ((volatile GPTMTMR_Reg*)(GPTM_32BitTimer2BaseAdd + GPTMTBMR_Offset))
#define GPTM_16BitTimer3BMode       ((volatile GPTMTMR_Reg*)(GPTM_32BitTimer3BaseAdd + GPTMTBMR_Offset))
#define GPTM_16BitTimer4BMode       ((volatile GPTMTMR_Reg*)(GPTM_32BitTimer4BaseAdd + GPTMTBMR_Offset))
#define GPTM_16BitTimer5BMode       ((volatile GPTMTMR_Reg*)(GPTM_32BitTimer5BaseAdd + GPTMTBMR_Offset))

#define GPTM_32BitTimer0BMode       ((volatile GPTMTMR_Reg*)(GPTM_64BitTimer0BaseAdd + GPTMTBMR_Offset))
#define GPTM_32BitTimer1BMode       ((volatile GPTMTMR_Reg*)(GPTM_64BitTimer1BaseAdd + GPTMTBMR_Offset))
#define GPTM_32BitTimer2BMode       ((volatile GPTMTMR_Reg*)(GPTM_64BitTimer2BaseAdd + GPTMTBMR_Offset))
#define GPTM_32BitTimer3BMode       ((volatile GPTMTMR_Reg*)(GPTM_64BitTimer3BaseAdd + GPTMTBMR_Offset))
#define GPTM_32BitTimer4BMode       ((volatile GPTMTMR_Reg*)(GPTM_64BitTimer4BaseAdd + GPTMTBMR_Offset))
#define GPTM_32BitTimer5BMode       ((volatile GPTMTMR_Reg*)(GPTM_64BitTimer5BaseAdd + GPTMTBMR_Offset))


#endif /* GPTM_REG_H_ */
