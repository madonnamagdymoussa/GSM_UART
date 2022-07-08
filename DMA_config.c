#include "DMA_config.h"
#include "UART_reg.h"

/*
 * typedef struct{
    DMAChannelNum_t ChannelNum;
    DMA_DestAddressIncrement_t DestAddressIncrement;
    DMA_SrcAddressIncrement_t SrcAddressIncrement;
    DMA_DestDataSize_t DestDataSize;
    DMA_SrcDataSize_t SrcDataSize;
}DMA_ChannelControlWordConfig_t;
 *
 */

DMA_ChannelControlWordConfig_t  DMAChannel8_UARTChannel0RX={
     DMAChannel_8,
     Byte_DestInc,
     Byte_srcInc,
     Byte_DestData,
     Byte_SrcData,
};

DMA_ChannelControlWordConfig_t DMAChannel9_UARTChannel0TX={
     DMAChannel_9,
     Byte_DestInc,
     Byte_srcInc,
     Byte_DestData,
     Byte_SrcData,
};

/****************************************************************************************************/
DMA_ChannelControlWordConfig_t  DMAChannel22_UARTChannel1RX={
     DMAChannel_22,
     Byte_DestInc,
     Byte_srcInc,
     Byte_DestData,
     Byte_SrcData,
};

DMA_ChannelControlWordConfig_t  DMAChannel23_UARTChannel1TX={
     DMAChannel_23,
     Byte_DestInc,
     Byte_srcInc,
     Byte_DestData,
     Byte_SrcData,
};
/****************************************************************************************************/
DMA_ChannelControlWordConfig_t DMAChannel0_UARTChannel2RX={
     DMAChannel_0,
     Byte_DestInc,
     Byte_srcInc,
     Byte_DestData,
     Byte_SrcData,
};

DMA_ChannelControlWordConfig_t DMAChannel23_UARTChannel2TX={
     DMAChannel_1,
     Byte_DestInc,
     Byte_srcInc,
     Byte_DestData,
     Byte_SrcData,
};
/****************************************************************************************************/

DMA_ChannelControlWordConfig_t DMAChannel16_UARTChannel3RX={
     DMAChannel_16,
     Byte_DestInc,
     Byte_srcInc,
     Byte_DestData,
     Byte_SrcData,
};

DMA_ChannelControlWordConfig_t DMAChannel17_UARTChannel3TX={
     DMAChannel_17,
     Byte_DestInc,
     Byte_srcInc,
     Byte_DestData,
     Byte_SrcData,
};
/****************************************************************************************************/
DMA_ChannelControlWordConfig_t  DMAChannel18_UARTChannel4RX={
     DMAChannel_18,
     Byte_DestInc,
     Byte_srcInc,
     Byte_DestData,
     Byte_SrcData,
};

DMA_ChannelControlWordConfig_t DMAChannel19_UARTChannel4TX={
     DMAChannel_19,
     Byte_DestInc,
     Byte_srcInc,
     Byte_DestData,
     Byte_SrcData,
};
/****************************************************************************************************/


DMA_ChannelControlWordConfig_t DMAChannel6_UARTChannel5RX={
     DMAChannel_6,
     Byte_DestInc,
     Byte_srcInc,
     Byte_DestData,
     Byte_SrcData,
};

DMA_ChannelControlWordConfig_t DMAChannel7_UARTChannel5TX={
     DMAChannel_7,
     Byte_DestInc,
     Byte_srcInc,
     Byte_DestData,
     Byte_SrcData,
};
/****************************************************************************************************/
DMA_ChannelControlWordConfig_t DMAChannel10_UARTChannel6RX={
     DMAChannel_10,
     Byte_DestInc,
     Byte_srcInc,
     Byte_DestData,
     Byte_SrcData,
};

DMA_ChannelControlWordConfig_t DMAChannel11_UARTChannel6TX={
     DMAChannel_11,
     Byte_DestInc,
     Byte_srcInc,
     Byte_DestData,
     Byte_SrcData,
};
/****************************************************************************************************/
DMA_ChannelControlWordConfig_t DMAChannel20_UARTChannel7RX={
     DMAChannel_20,
     Byte_DestInc,
     Byte_srcInc,
     Byte_DestData,
     Byte_SrcData,
};

DMA_ChannelControlWordConfig_t DMAChannel21_UARTChannel7TX={
     DMAChannel_21,
     Byte_DestInc,
     Byte_srcInc,
     Byte_DestData,
     Byte_SrcData,
};
/****************************************************************************************************/







DMA_ChannelControlWordConfig_t  *   DMA_ChannelsConfigTX[8]={

  &DMAChannel9_UARTChannel0TX,
  &DMAChannel23_UARTChannel1TX,
  &DMAChannel23_UARTChannel2TX,
  &DMAChannel17_UARTChannel3TX,
  &DMAChannel19_UARTChannel4TX,
  &DMAChannel7_UARTChannel5TX,
  &DMAChannel11_UARTChannel6TX,
  &DMAChannel21_UARTChannel7TX
};

DMA_ChannelControlWordConfig_t*DMA_ChannelsConfigRX[8]={

   &DMAChannel8_UARTChannel0RX,
   &DMAChannel22_UARTChannel1RX,
   &DMAChannel0_UARTChannel2RX,
   &DMAChannel16_UARTChannel3RX,
   &DMAChannel18_UARTChannel4RX,
   &DMAChannel6_UARTChannel5RX,
   &DMAChannel10_UARTChannel6RX,
   &DMAChannel20_UARTChannel7RX

 };


