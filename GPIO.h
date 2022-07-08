
#ifndef GPIO_H_
#define GPIO_H_

#include "gpio_config.h"



#define EXTI_PORTA_INTERRUPTNUM    0
#define EXTI_PORTB_INTERRUPTNUM    1
#define EXTI_PORTC_INTERRUPTNUM    2
#define EXTI_PORTD_INTERRUPTNUM    3
#define EXTI_PORTE_INTERRUPTNUM    4
#define EXTI_PORTF_INTERRUPTNUM    30

void GPIO_SetData(PortNum_t PortNum , ChannelNum_t ChannelNum, OutputValue_t OutputValue);

void GPIO_SetPinStatus(PortNum_t PortNum, ChannelNum_t ChannelNum, PinState_t State );

void GPIO_EXTI_Initialization(GPIO_EXTI_Config* pt_channel_config, PortNum_t num, ChannelNum_t ChannelNum);

void GPIO_EnableRunModeClockGateControl(PortNum_t num);

void GPIO_TogglePinValue(PortNum_t PortNum, ChannelNum_t ChannelNum);

void GPIO_ConfigureCommit(PortNum_t PortNum, ChannelNum_t ChannelNum, LockMode_t mode);

void GPIO_ConfigureAlternateFunctionSelect(PortNum_t PortNum, ChannelNum_t ChannelNum , AFSEL_Mode mode);

void GPIO_ConfigureAnalogModeSelect(PortNum_t PortNum, ChannelNum_t ChannelNum, AMSEL_Mode mode);

void GPIO_ConfigureDigitalEnable(PortNum_t PortNum, ChannelNum_t ChannelNum, DigitalMode_t mode);

void GPIO_ConfigurePortControl(PortNum_t PortNum, ChannelNum_t ChannelNum, MuxValue_t value );

void GPIO_ConfigureInterruptMask(PortNum_t PortNum, ChannelNum_t ChannelNum,InterruptMaskMode_t mode);

void GPIO_EXTIClearInterrupt(PortNum_t PortNum, ChannelNum_t ChannelNum);

void RegisterCallbackFunction(PortNum_t PortNum,CallbackFunc_t pt_callback);

#endif /* GPIO_H_ */



