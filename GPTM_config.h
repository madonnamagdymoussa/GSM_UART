#ifndef GPTM_CONFIG_H_
#define GPTM_CONFIG_H_

typedef enum{
   Timer0,
   Timer1,
   Timer2,
   Timer3,
   Timer4,
   Timer5
}GPTM_Channel_t;

typedef enum{
    _16_32BitTimerA,
    _32_64BitTimerA,
    _16BitTimerB,
    _32BitTimerB
}GPTM_TimerType_t;

typedef enum{
    _32BitTimer=0x0,
    _64BitTimer=0x0,

    _32BitRTC=0x1,
    _64BitRTC=0x1,

    _16BitTimer=0x4,
    //_32BitTimer=0x4
}GPTM_TimerSize_t;


typedef enum{
    CountDownDirection,
    CountUpDirection

 }GPTM_CountingDirection_t;

 typedef enum{
     OneShotMode=0x1,
     PeriodicMode=0x2,
     CaptureMode=0x3
 }GPTM_TimerMode_t;

 typedef enum{
     MatchInterruptDisable,
     MatchInterruptEnable
 }GPTM_MatchInterruptMode_t;

 typedef enum{
     CaptureMode_EdgeCountMode,
     CaptureMode_EdgeTimeMode,
 }GPTM_CaptureMode_t;


 typedef struct{

     GPTM_Channel_t Channel;
     GPTM_TimerSize_t TimerSize;
     GPTM_TimerMode_t Mode;
     GPTM_MatchInterruptMode_t MatchInterruptMode;
     GPTM_CountingDirection_t CountingDirection;
     GPTM_CaptureMode_t CaptureMode;

 }GPTM_ConfigurationChannel_t;

 #endif /* GPTM_CONFIG_H_ */
