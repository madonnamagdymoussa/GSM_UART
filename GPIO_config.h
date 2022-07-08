
#ifndef GPIO_CONFIG_H_
#define GPIO_CONFIG_H_


#include "lstd.h"
#include "DMA_reg.h"

#define UART_InterruptNum  61

 typedef enum{

    Channel_0 =0,
    Channel_1 =1,
    Channel_2 =2,
    Channel_3 =3,
    Channel_4 =4,
    Channel_5 =5,
    Channel_6 =6,
    Channel_7 =7,

    MinNumChannel=0,
    MaxNumChannel=7


}ChannelNum_t;

typedef enum{
    PortA =0,
    PortB =1,
    PortC =2,
    PortD =3,
    PortE =4,
    PortF =5,

    MinNumPort=0,
    MaxNumPort=5,


}PortNum_t;

typedef enum{
    InputFloat =0,
    Output =1,

    MinNumState=0,
    MaxNumState=1


}PinState_t;

typedef struct{
    u8_t SenseType;
    u8_t NumEdgeDetection;
    u8_t Event;

}GPIO_EXTI_Config;

typedef enum {
    OutputLow,
    OutputHigh


}OutputValue_t;

typedef enum{
    Disable_AFSEL,
    Enable_AFSEL

}AFSEL_Mode;

typedef enum{
    Disable_AMSEL,
    Enable_AMSEL

}AMSEL_Mode;

typedef enum{
    MuxValue_0,
    MuxValue_1,
    MuxValue_2,
    MuxValue_3,
    MuxValue_4,
    MuxValue_5,
    MuxValue_6,
    MuxValue_7,
    MuxValue_8,
    MuxValue_9,
    MuxValue_10,
    MuxValue_11,
    MuxValue_12,
    MuxValue_13,
    MuxValue_14,
    MuxValue_15,

}MuxValue_t;

typedef enum{

  DisableDigitalFunction,
  EnableDigitalFunction

}DigitalMode_t;

typedef enum{

    EnableLock,
    DisableLock

}LockMode_t;

typedef enum{
    Enable_InterruptMask,
    Disable_InterruptMask
}InterruptMaskMode_t;



extern GPIO_EXTI_Config EXTI_Channel3_Config;
extern GPIO_EXTI_Config EXTI_Channel6_Config;



#endif /* GPIO_CONFIG_H_ */
