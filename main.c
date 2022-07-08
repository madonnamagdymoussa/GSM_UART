
#include "UART.h"
#include "DMA.h"

//extern unsigned char ui8ControlTable[1024];

char SMSText[]={"Do your best, Release your stress, Forget the rest "};


int main(void)
{
    DMA_Initialization();

    //GSM_Init(UART_Channel0);


    UART_Initialization(&UARTChannel0_Config);

    DMA_ConfigureChannelSoftwareRequest(EnableSoftwareRequest,DMAChannel_0);


    UART_Transmit_DMA(UART_Channel2 ,&SMSText[0], DMAChannel_1 ,EncodingNum_1);


    DMA_ConfigureInterruptStatus( EnableInterrupt, DMASoftwareChannelTransfer_InterruptNum);
    DMA_ConfigureInterruptStatus( EnableInterrupt, DMAError_InterruptNum);


    //to do in GSM DRIVER
    //UART_SMS_Recieve
    //UART_SMS_Send

}
