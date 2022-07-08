
#ifndef DMA_CONFIG_H_
#define DMA_CONFIG_H_

#include "lstd.h"

#define DMASoftwareChannelTransfer_InterruptNum (46)
#define DMAError_InterruptNum (47)


typedef enum{
    DMAChannel_0,
    DMAChannel_1,
    DMAChannel_2,
    DMAChannel_3,
    DMAChannel_4,
    DMAChannel_5,
    DMAChannel_6,
    DMAChannel_7,
    DMAChannel_8,
    DMAChannel_9,
    DMAChannel_10,
    DMAChannel_11,
    DMAChannel_12,
    DMAChannel_13,
    DMAChannel_14,
    DMAChannel_15,
    DMAChannel_16,
    DMAChannel_17,
    DMAChannel_18,
    DMAChannel_19,
    DMAChannel_20,
    DMAChannel_21,
    DMAChannel_22,
    DMAChannel_23,
    DMAChannel_24,
    DMAChannel_25,
    DMAChannel_26,
    DMAChannel_27,
    DMAChannel_28,
    DMAChannel_29,
    DMAChannel_30,
    DMAChannel_31,

}DMAChannelNum_t;

typedef enum{
    Byte_DestInc=0x0,
    HalfWord_DestInc=0x1,
    Word_DestInc=0x2,
    NoIncrement_DestInc=0x3
}DMA_DestAddressIncrement_t;


typedef enum{
    Byte_srcInc=0x0,
    HalfWord_srcInc=0x1,
    Word_srcInc=0x2,
    NoIncrement_srcInc=0x3
}DMA_SrcAddressIncrement_t;


typedef enum{
    Byte_DestData=0x0,
    HalfWord_DestData=0x1,
    Word_DestData=0x2,
}DMA_DestDataSize_t;


typedef enum{
    Byte_SrcData=0x0,
    HalfWord_SrcData=0x1,
    Word_SrcData=0x2,
}DMA_SrcDataSize_t;

typedef enum{
DisableSoftwareRequest,
EnableSoftwareRequest
}DMA_SoftwareRequestMode_t;

typedef enum{

    EnableInterrupt,
    ClearInterrupt
}DMA_InterruptStatus;

typedef enum{
    EncodingNum_0,
    EncodingNum_1,
    EncodingNum_2,
    EncodingNum_3,

}DMAEncodingNum_t;

typedef struct{
    DMAChannelNum_t ChannelNum;
    DMA_DestAddressIncrement_t DestAddressIncrement;
    DMA_SrcAddressIncrement_t SrcAddressIncrement;
    DMA_DestDataSize_t DestDataSize;
    DMA_SrcDataSize_t SrcDataSize;
}DMA_ChannelControlWordConfig_t;

//Array of pointers to structures
extern DMA_ChannelControlWordConfig_t*DMA_ChannelsConfigTX[8];
extern DMA_ChannelControlWordConfig_t*DMA_ChannelsConfigRX[8];

#endif /* DMA_CONFIG_H_ */
