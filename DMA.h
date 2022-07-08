
#ifndef DMA_H_
#define DMA_H_

#include "DMA_config.h"

void DMA_ConfigureControlTableBaseAddress(void *ptControlTable);
void DMA_Initialization();

void DMA_ChannelControlStructureSet(DMA_ChannelControlWordConfig_t* ptrConfig, u32_t*SourceAddress , u32_t*DestAddress );

void DMA_ConfigureChannelSoftwareRequest(DMA_SoftwareRequestMode_t RequestMode,DMAChannelNum_t ChannelNum);

void DMA_ConfigureInterruptStatus(DMA_InterruptStatus Status, u32_t InterruptNum);

void DMA_AssignChannel(u8_t DMA_ChannelNum, u8_t EncodingNum);
void DMA_DeAssignChannel(u8_t DMA_ChannelNum, u8_t EncodingNum);


void DMA_RegisterCallbackFunction_SoftwareTransfer(DMAChannelNum_t ChannelNum, CallbackFunc_t pt_callback);
void DMA_RegisterCallbackFunction_ErrorHandler(DMAChannelNum_t ChannelNum, CallbackFunc_t pt_callback);


#endif /* DMA_H_ */
