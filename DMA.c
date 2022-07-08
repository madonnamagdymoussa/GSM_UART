/*************************************************************************************************************************************/
/* Name:   DMA.c                                                                                                                    */
/* Author: Madonna Magdy                                                                                                             */
/* Version: V1                                                                                                                       */
/* Usage: This module contains the implementation for the DMA functions                                                             */
/*************************************************************************************************************************************/

#include "DMA_reg.h"
#include "lstd.h"
#include "DMA.h"

#include "NVIC.h"
#include<math.h>

/******************************************* ID Description of the Unit *********************************************************/
// first number of ID signifies the module used (the DMA driver takes number 2)

  //The Second number signifies that whether you are using a function or an array or a variable
 //(The variable takes number1 ,The array takes number 2, The function takes number 3  )

 //The Third number signifies the number of a function or an array or a variable

/******************************************* ID Description of the Unit ********************************************************/


/******************************  ID Description For Testing *********************************************************/

 //First part is the ID description of the Unit

 //The second part signifies how many number of tests you use on a certain variable or function (on a certain unit)

/******************************  ID Description For Testing *********************************************************/

/************************  UNIT ID: 2.2.1 *******************************************************/
/* UNIT ID: 2.2.1
 *
 * UNIT NAME: ui8ControlTable
 *
 * UNIT LOCATION: .bss section because it is uninitialized
 *
 * UNIT DESCRIPTION: the content of the array stores the Source pointer , destination pointer,
 * the control word and unused entry of EACH channel Control Structure.
 *
 *Source pointer for channelX--> 4 bytes
 *destination pointer for channelX--> 4 bytes
 *control word for channelX--> 4 bytes
 *unused entry for channelX--> 4 bytes
 *ThereFore, the total bytes for EACH channel will be 16 bytes
 *
 *UNIT NOTE: 1-the array is aligned on 1024-byte boundary according to the specification for tiva c document
 *           2-the array is NOT static because the address of the first location in the array will be the base address
 *           of control structure for each channel.Will be used in DMA_reg.h file
 *
 * */
unsigned char ui8ControlTable[1024] __attribute__ ((aligned(1024)));/*******************************/



/************************  UNIT ID: 2.2.2 *************************************************************/
/* UNIT ID: 6.2.2
 *
 * UNIT NAME: DMA_SoftwareTransfer_Callback
 *
 * UNIT LOCATION: The array is stored in .data section
 * At Runtime it will be copied to Ram memory as the content of the array might be changed
 *
 * UNIT DESCRIPTION:
 * Array of pointers to functions
 * the index of the array represents the the channel number
 * the content of the array represents pointer variable to function
 * static keyword is added because the function can not be called by the software the hardware will call it
 * volatile keyword is added because the value can be changed by hardware (disable optimization)
 * the pointer is of type CallbackFunc_t --> points to a function that returns void and takes void as an argument because
 * the call back function is not called by software so by logic no one will insert an argument
 * and the return type will be void because the user can not call it
 *
 * UNIT NOTE:
 * If you don't initialize DMA_SoftwareTransfer_Callback[] with a null pointer
 * and you forgot to register the call back function there will
 * be segmentation fault because you are trying to access a wild pointer

 * The advantage of the if condition ---> (if(DMA_SoftwareTransfer_Callback[] != NULL_PTR) )
 * you can't check on a garbage value but you can check on the null value
 * to see if the pointer to function (DMA_SoftwareTransfer_Callback[]) doesn't hold the
 * address of a function or doesn't hold a value
 *
 */
static volatile  CallbackFunc_t DMA_SoftwareTransfer_Callback[32]={NULL_PTR};/***************************/



/************************  UNIT ID: 2.2.3 *************************************************************/
/* UNIT ID: 2.2.3
 *
 * UNIT NAME: DMA_ErrorHandler_Callback
 *
 * UNIT LOCATION: The array is stored in .data section
 * At Runtime it will be copied to Ram memory as the content of the array might be changed
 *
 * UNIT DESCRIPTION:
 * Array of pointers to functions
 * the index of the array represents the the channel number
 * the content of the array represents pointer variable to function
 * static keyword is added because the function can not be called by the software the hardware will call it
 * volatile keyword is added because the value can be changed by hardware (disable optimization)
 * the pointer is of type CallbackFunc_t --> points to a function that returns void and takes void as an argument because
 * the call back function is not called by software so by logic no one will insert an argument
 * and the return type will be void because the user can not call it
 *
 * UNIT NOTE:
 * If you don't initialize DMA_ErrorHandler_Callback[] with a null pointer
 * and you forgot to register the call back function there will
 * be segmentation fault because you are trying to access a wild pointer

 * The advantage of the if condition ---> (if(DMA_ErrorHandler_Callback[] != NULL_PTR) )
 * you can't check on a garbage value but you can check on the null value
 * to see if the pointer to function (DMA_ErrorHandler_Callback[]) doesn't hold the
 * address of a function or doesn't hold a value
 *
 */
static volatile  CallbackFunc_t DMA_ErrorHandler_Callback[32]={NULL_PTR};/***************************/

int FindChannelNum_InterruptSource(){

    u32_t InterruptSourceFlag=0xFF;

    u32_t ChannelInterruptSources_bitNumbers= DMAChannelInterruptStatus & InterruptSourceFlag;

    if ( (ChannelInterruptSources_bitNumbers & 0) != 0 ){

        if (ChannelInterruptSources_bitNumbers == 2 || ChannelInterruptSources_bitNumbers == 3 ){

            return ChannelInterruptSources_bitNumbers;
        }
        else{
       u32_t Sqrt_ChannelInterruptSourcesVar= (u32_t) sqrt(ChannelInterruptSources_bitNumbers);

       return Sqrt_ChannelInterruptSourcesVar;
       //NOTE: if for example bit 3 and bit 4 is set (sqrt(12)) the lower number (HIGHER PRIORITY) will be returned
       //in our example number 3 will be returned due to the the casting performed  -->(u32_t) sqrt

        }


    }

    return 55555;

}

DMA_SoftwareTransferHandler(){
    u32_t ChannelNum_InterruptSource = FindChannelNum_InterruptSource();

     if (ChannelNum_InterruptSource != 55555){

       if( DMA_ErrorHandler_Callback[ChannelNum_InterruptSource] != NULL_PTR){

           DMA_ErrorHandler_Callback[ChannelNum_InterruptSource](); //executing the call back function in the app layer

           DMAChannelInterruptStatus |= (1<<ChannelNum_InterruptSource); //clear the interrupt

       }
     }

}

DMA_ErrorHandler(){

    u32_t ChannelNum_InterruptSource = FindChannelNum_InterruptSource();

     if (ChannelNum_InterruptSource != 0){

       if( DMA_ErrorHandler_Callback[ChannelNum_InterruptSource ] != NULL_PTR){

           DMA_ErrorHandler_Callback[ChannelNum_InterruptSource ]();//executing the call back function in the app layer

           DMAChannelInterruptStatus |= (1<<ChannelNum_InterruptSource); //clear the interrupt
       }
     }

}



volatile  u32_t* SourceAddressPointerRegisters[32]={

   (u32_t*)SourceAddressPointer_0,
   (u32_t*)SourceAddressPointer_1,
   (u32_t*)SourceAddressPointer_2,
   (u32_t*)SourceAddressPointer_3,
   (u32_t*)SourceAddressPointer_4,
   (u32_t*)SourceAddressPointer_5,
   (u32_t*)SourceAddressPointer_6,
   (u32_t*)SourceAddressPointer_7,
   (u32_t*)SourceAddressPointer_8,
   (u32_t*)SourceAddressPointer_9,
   (u32_t*)SourceAddressPointer_10,
   (u32_t*)SourceAddressPointer_11,
   (u32_t*)SourceAddressPointer_12,
   (u32_t*)SourceAddressPointer_13,
   (u32_t*)SourceAddressPointer_14,
   (u32_t*)SourceAddressPointer_15,
   (u32_t*)SourceAddressPointer_16,
   (u32_t*)SourceAddressPointer_17,
   (u32_t*)SourceAddressPointer_18,
   (u32_t*)SourceAddressPointer_19,
   (u32_t*)SourceAddressPointer_20,
   (u32_t*)SourceAddressPointer_21,
   (u32_t*)SourceAddressPointer_22,
   (u32_t*)SourceAddressPointer_23,
   (u32_t*)SourceAddressPointer_24,
   (u32_t*)SourceAddressPointer_25,
   (u32_t*)SourceAddressPointer_26,
   (u32_t*)SourceAddressPointer_27,
   (u32_t*)SourceAddressPointer_28,
   (u32_t*)SourceAddressPointer_29,
   (u32_t*)SourceAddressPointer_30,
   (u32_t*)SourceAddressPointer_31
};


volatile  u32_t * DestinationAddressPointerRegisters[32]={
   (u32_t*)DestinationAddressPointer_0,
   (u32_t*) DestinationAddressPointer_1,
   (u32_t*) DestinationAddressPointer_2,
   (u32_t*) DestinationAddressPointer_3,
   (u32_t*) DestinationAddressPointer_4,
   (u32_t*) DestinationAddressPointer_5,
   (u32_t*) DestinationAddressPointer_6,
   (u32_t*) DestinationAddressPointer_7,
   (u32_t*) DestinationAddressPointer_8,
   (u32_t*) DestinationAddressPointer_9,
   (u32_t*) DestinationAddressPointer_10,
   (u32_t*) DestinationAddressPointer_11,
   (u32_t*) DestinationAddressPointer_12,
   (u32_t*) DestinationAddressPointer_13,
   (u32_t*) DestinationAddressPointer_14,
   (u32_t*) DestinationAddressPointer_15,
   (u32_t*) DestinationAddressPointer_16,
   (u32_t*) DestinationAddressPointer_17,
   (u32_t*) DestinationAddressPointer_18,
   (u32_t*) DestinationAddressPointer_19,
   (u32_t*) DestinationAddressPointer_20,
   (u32_t*) DestinationAddressPointer_21,
   (u32_t*) DestinationAddressPointer_22,
   (u32_t*) DestinationAddressPointer_23,
   (u32_t*) DestinationAddressPointer_24,
   (u32_t*) DestinationAddressPointer_25,
   (u32_t*) DestinationAddressPointer_26,
   (u32_t*) DestinationAddressPointer_27,
   (u32_t*) DestinationAddressPointer_28,
   (u32_t*) DestinationAddressPointer_29,
   (u32_t*) DestinationAddressPointer_30,
   (u32_t*) DestinationAddressPointer_31
};


volatile static DMACHCTL_Reg * DMA_ChannelControlWordRegisters[32]={
   (DMACHCTL_Reg*)DMA_ChannelControlWord_0,
   (DMACHCTL_Reg*)DMA_ChannelControlWord_1,
   (DMACHCTL_Reg*)DMA_ChannelControlWord_2,
   (DMACHCTL_Reg*)DMA_ChannelControlWord_3,
   (DMACHCTL_Reg*)DMA_ChannelControlWord_4,
   (DMACHCTL_Reg*)DMA_ChannelControlWord_5,
   (DMACHCTL_Reg*)DMA_ChannelControlWord_6,
   (DMACHCTL_Reg*)DMA_ChannelControlWord_7,
   (DMACHCTL_Reg*)DMA_ChannelControlWord_8,
   (DMACHCTL_Reg*)DMA_ChannelControlWord_9,
   (DMACHCTL_Reg*)DMA_ChannelControlWord_10,
   (DMACHCTL_Reg*)DMA_ChannelControlWord_11,
   (DMACHCTL_Reg*)DMA_ChannelControlWord_12,
   (DMACHCTL_Reg*)DMA_ChannelControlWord_13,
   (DMACHCTL_Reg*)DMA_ChannelControlWord_14,
   (DMACHCTL_Reg*)DMA_ChannelControlWord_15,
   (DMACHCTL_Reg*)DMA_ChannelControlWord_16,
   (DMACHCTL_Reg*)DMA_ChannelControlWord_17,
   (DMACHCTL_Reg*)DMA_ChannelControlWord_18,
   (DMACHCTL_Reg*)DMA_ChannelControlWord_19,
   (DMACHCTL_Reg*)DMA_ChannelControlWord_20,
   (DMACHCTL_Reg*)DMA_ChannelControlWord_21,
   (DMACHCTL_Reg*)DMA_ChannelControlWord_22,
   (DMACHCTL_Reg*)DMA_ChannelControlWord_23,
   (DMACHCTL_Reg*)DMA_ChannelControlWord_24,
   (DMACHCTL_Reg*)DMA_ChannelControlWord_25,
   (DMACHCTL_Reg*)DMA_ChannelControlWord_26,
   (DMACHCTL_Reg*)DMA_ChannelControlWord_27,
   (DMACHCTL_Reg*)DMA_ChannelControlWord_28,
   (DMACHCTL_Reg*)DMA_ChannelControlWord_29,
   (DMACHCTL_Reg*)DMA_ChannelControlWord_30,
   (DMACHCTL_Reg*)DMA_ChannelControlWord_31
};

volatile static u32_t *DMA_ChannelMapSelectRegisters[4]={
      (u32_t *)DMA_ChannelMapSelect0_Reg,
      (u32_t *)DMA_ChannelMapSelect1_Reg,
      (u32_t *)DMA_ChannelMapSelect2_Reg,
      (u32_t *)DMA_ChannelMapSelect3_Reg

};

//DMAChannelInterruptStatus

void DMA_ConfigureControlTableBaseAddress(void *ptControlTable){

    DMA_ChannelControlBasePointer->Bits.ChannelControlBaseAddress=(u32_t)ptControlTable;
}



void DMA_Initialization(){

    /*********************************STEP1***************************************/
      /*Enable the DMA clock*/
     RCGCDMA_REG->DMAModuleRunModeClockGatingControl=1;
    /*********************************STEP2***************************************/
     DMA_ConfigureControlTableBaseAddress(&ui8ControlTable[0]);
     /*********************************STEP3***************************************/

}


void DMA_ChannelControlStructureSet(DMA_ChannelControlWordConfig_t* ptrConfig, u32_t*SourceAddress , u32_t*DestAddress ){

    SourceAddressPointerRegisters[ptrConfig->ChannelNum]=SourceAddress;
    DestinationAddressPointerRegisters[ptrConfig->ChannelNum]=DestAddress;

    (*DMA_ChannelControlWordRegisters[ptrConfig->ChannelNum]).DSTINC=ptrConfig->DestAddressIncrement;
    (*DMA_ChannelControlWordRegisters[ptrConfig->ChannelNum]).DSTSIZE=ptrConfig->DestDataSize;
    (*DMA_ChannelControlWordRegisters[ptrConfig->ChannelNum]).SRCINC=ptrConfig->SrcAddressIncrement;
    (*DMA_ChannelControlWordRegisters[ptrConfig->ChannelNum]).SRCSIZE=ptrConfig->SrcDataSize;


}


void DMA_ConfigureChannelSoftwareRequest(DMA_SoftwareRequestMode_t RequestMode,DMAChannelNum_t ChannelNum){

    switch(RequestMode){

    case DisableSoftwareRequest:
        DMAChannelSoftwareRequest_Register &= ~(1<<ChannelNum);
   break;

    case EnableSoftwareRequest:
        DMAChannelSoftwareRequest_Register |= (1<<ChannelNum);
    break;

    }

}


void DMA_ConfigureInterruptStatus(DMA_InterruptStatus Status, u32_t InterruptNum){

    if(EnableInterrupt == Status){
        NVIC_Enable_Interrupt(InterruptNum);
    }

    else if(ClearInterrupt == Status){
        NVIC_Clear_Interrupt(InterruptNum);
    }

}


void DMA_AssignChannel(u8_t DMA_ChannelNum, DMAEncodingNum_t EncodingNum){

    u8_t RegisterNum=(u8_t)(DMA_ChannelNum%7);
    u8_t BitNum =( (DMA_ChannelNum-RegisterNum*8)*4 ) + EncodingNum;
    *DMA_ChannelMapSelectRegisters[RegisterNum]|=(1<<BitNum);
}

void DMA_DeAssignChannel(u8_t DMA_ChannelNum, DMAEncodingNum_t EncodingNum){

    u8_t RegisterNum=(u8_t)(DMA_ChannelNum%7);
    u8_t BitNum =( (DMA_ChannelNum-RegisterNum*8)*4 ) + EncodingNum;
    *DMA_ChannelMapSelectRegisters[RegisterNum]&=~(1<<BitNum);
}


 void DMA_RegisterCallbackFunction_SoftwareTransfer(DMAChannelNum_t ChannelNum, CallbackFunc_t pt_callback){

     DMA_SoftwareTransfer_Callback[ChannelNum]=pt_callback;

 }

 void DMA_RegisterCallbackFunction_ErrorHandler(DMAChannelNum_t ChannelNum, CallbackFunc_t pt_callback){

     DMA_ErrorHandler_Callback[ChannelNum]=pt_callback;

 }
