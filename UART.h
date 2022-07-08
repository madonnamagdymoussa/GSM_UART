
#ifndef UART_H_
#define UART_H_

#include "UART_config.h"
#include "lstd.h"
#include "DMA_config.h"
#define UARTSysClock 16000000UL //System Clock
#define UARTRecTimeOut 600 //time in ms after which UART_RcCharwTimeOut function returns. A null is returned if nothing is received.

void UART_EnableGPIO_AFSEL(UART_Channel_t channel);
void UART_Initialization(UART_Config_t* pt_Config);
void UART_ConfigureInterruptSource(enum UART_IRQ_Event InterruptFlag, UART_InterruptMaskConfig_t InterruptMaskConfig, UART_Channel_t Channel);

void UART_Recieve_DMA(UART_Channel_t Channel,u32_t *DestAddressBuffer,DMAChannelNum_t DMAChannelNum,u8_t EncodingNum);
void UART_Transmit_DMA(UART_Channel_t Channel,u32_t *SourceAddressBuffer,DMAChannelNum_t DMAChannelNum,u8_t EncodingNum);


void UART_TransmitChar_Polling(UART_Channel_t channel, u8_t *pTxBuffer);
void UART_RecieveChar_Polling(UART_Channel_t channel, u8_t *pRxBuffer);


void UART_TransmitChar_Interrupt(UART_Channel_t channel, u8_t *pRxBuffer);
void UART_RecieveChar_Interrupt(UART_Channel_t channel, u8_t *pRxBuffer);
void UART_RecCharwTimeOut (char* data,UART_Channel_t channel );


void UART0_RegisterCallbackFunction(enum UART_IRQ_Event Flag, CallbackFunc_t pt_callback);
void UART1_RegisterCallbackFunction(enum UART_IRQ_Event Flag, CallbackFunc_t pt_callback);
void UART2_RegisterCallbackFunction(enum UART_IRQ_Event Flag, CallbackFunc_t pt_callback);
void UART3_RegisterCallbackFunction(enum UART_IRQ_Event Flag, CallbackFunc_t pt_callback);
void UART4_RegisterCallbackFunction(enum UART_IRQ_Event Flag, CallbackFunc_t pt_callback);
void UART5_RegisterCallbackFunction(enum UART_IRQ_Event Flag, CallbackFunc_t pt_callback);
void UART6_RegisterCallbackFunction(enum UART_IRQ_Event Flag, CallbackFunc_t pt_callback);
void UART7_RegisterCallbackFunction(enum UART_IRQ_Event Flag, CallbackFunc_t pt_callback);






#endif /* UART_H_ */
