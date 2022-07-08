/*************************************************************************************************************************************/
/* Name: GPIO.c                                                                                                                    */
/* Author: Madonna Magdy                                                                                                            */
/* Version: V1                                                                                                                      */
/* Usage: This module contains the implementation for the GPIO functions                                                            */
/*************************************************************************************************************************************/
/************************************ Includes ************************************/
#include"GPIO_reg.h"
#include "gpio_config.h"
#include "GPIO.h"

#include<assert.h>
#include<stdlib.h>

/************************************ Includes ************************************/


/******************************************* ID Description of the Unit *********************************************************/
// first number of ID signifies the module used (the GPIO  module takes number 3)

  //The Second number signifies that whether you are using a function or an array or a variable
 //(The variable takes number1 ,The array takes number 2, The function takes number 3  )

 //The Third number signifies the number of a function or an array or a variable

/******************************************* ID Description of the Unit ********************************************************/


/******************************  ID Description For Testing *********************************************************/

 //First part is the ID description of the Unit

 //The second part signifies how many number of tests you use on a certain variable or function (on a certain unit)

/******************************  ID Description For Testing *********************************************************/


/************************  UNIT ID: 3.2.1 **********************************/
/* UNIT ID: 3.2.1
 *
 * UNIT NAME: EXTI_Callback
 *
 * UNIT LOCATION: The array is stored in .data section
 * At Runtime it will be copied to Ram memory as the content of the array might be changed
 *
 * UNIT DESCRIPTION:
 * Array of pointers to functions
 * the index of the array represents the the port number
 * the content of the array represents pointer variable to function
 * static keyword is added because the function can not be called by the software the hardware will call it
 * volatile keyword is added because the value can be changed by hardware (disable optimization)
 * the pointer is of type CallbackFunc_t --> points to a function that returns void and takes void as an argument because
 * the call back function is not called by software so by logic no one will insert an argument
 * and the return type will be void because the user can not call it
 *
 * UNIT NOTE:
 * If you don't initialize EXTI_Callback[] with a null pointer
 * and you forgot to register the call back function there will
 * be segmentation fault because you are trying to access a wild pointer

 * The advantage of the if condition ---> (if(EXTI_Callback[] != NULL_PTR) )
 * you can't check on a garbage value but you can check on the null value
 * to see if the pointer to function (EXTI_Callback[]) doesn't hold the
 * address of a function or doesn't hold a value
 *
 *  */
 static volatile  CallbackFunc_t EXTI_Callback[6]={NULL_PTR};
/************************  UNIT ID: 3.2.1 **********************************/



/************************  UNIT ID: 3.3.1 **********************************/
 /* UNIT ID: 3.3.1
  *
  * UNIT NAME:EXTIAIntDefaultHandler
  *
  * UNIT LOCATION: FLASH
  * we can not write on the FLASH memory at runtime that's why we add a call back function in the implementation
  * as we CAN NOT change the implementation of the function itself but we can SOLVE that problem by
  * adding a pointer to function. Hence, we can let the pointer point to any function we want in the runtime
  * without changing the implementation of the function itself at the runtime
  *
  * UNIT DESCRIPTION: Interrupt service routine that will be called by hardware under certain conditions
  * These conditions are
  * 1-the interrupt mask of that module is enabled --> Done by the Developer through the UNIT ID
  * 2-the NVIC is enabled for that module --> Done by the Developer through the UNIT ID
  * 3- the global interrupt is enabled --> Done by the Developer
  * 4- Register the callback function pointer ---> Done by the Developer
  * 5- Rising the flag of that module under certain condition --> Done by Hardware
  *
  * That Function related to the external interrupt of PORTA
  * */
 EXTIAIntHandler(){

    if (EXTI_Callback[PortA] != NULL_PTR){

    (*EXTI_Callback[PortA])();

    }

}

/************************  UNIT ID: 3.3.2 **********************************/
 /* UNIT ID: 3.3.2
  *
  * UNIT NAME:EXTIAIntDefaultHandler
  *
  * UNIT LOCATION: FLASH
  * we can not write on the FLASH memory at runtime that's why we add a call back function in the implementation
  * as we CAN NOT change the implementation of the function itself but we can SOLVE that problem by
  * adding a pointer to function. Hence, we can let the pointer point to any function we want in the runtime
  * without changing the implementation of the function itself at the runtime
  *
  * UNIT DESCRIPTION: Interrupt service routine that will be called by hardware under certain conditions
  * These conditions are
  * 1-the interrupt mask of that module is enabled --> Done by the Developer through the UNIT ID
  * 2-the NVIC is enabled for that module --> Done by the Developer through the UNIT ID
  * 3- the global interrupt is enabled --> Done by the Developer
  * 4- Register the callback function pointer ---> Done by the Developer
  * 5- Rising the flag of that module under certain condition --> Done by Hardware
  *
  * That Function related to the external interrupt of PORTB
  * */

 EXTIBIntHandler(){

    if (EXTI_Callback[PortB] != NULL_PTR){

    (*EXTI_Callback[PortB])();

    }

}


/************************  UNIT ID: 3.3.3 **********************************/
/* UNIT ID: 3.3.3
 *
 * UNIT NAME:EXTIAIntDefaultHandler
 *
 * UNIT LOCATION: FLASH
 * we can not write on the FLASH memory at runtime that's why we add a call back function in the implementation
 * as we CAN NOT change the implementation of the function itself but we can SOLVE that problem by
 * adding a pointer to function. Hence, we can let the pointer point to any function we want in the runtime
 * without changing the implementation of the function itself at the runtime
 *
 * UNIT DESCRIPTION: Interrupt service routine that will be called by hardware under certain conditions
 * These conditions are
 * 1-the interrupt mask of that module is enabled --> Done by the Developer through the UNIT ID
 * 2-the NVIC is enabled for that module --> Done by the Developer through the UNIT ID
 * 3- the global interrupt is enabled --> Done by the Developer
 * 4- Register the callback function pointer ---> Done by the Developer
 * 5- Rising the flag of that module under certain condition --> Done by Hardware
 *
 * That Function related to the external interrupt of PORTC
 * */

EXTICIntHandler(){

    if (EXTI_Callback[PortC] != NULL_PTR){

    (*EXTI_Callback[PortC])();

    }

}

/************************  UNIT ID: 3.3.4 **********************************/
/* UNIT ID: 3.3.4
 *
 * UNIT NAME:EXTIAIntDefaultHandler
 *
 * UNIT LOCATION: FLASH
 * we can not write on the FLASH memory at runtime that's why we add a call back function in the implementation
 * as we CAN NOT change the implementation of the function itself but we can SOLVE that problem by
 * adding a pointer to function. Hence, we can let the pointer point to any function we want in the runtime
 * without changing the implementation of the function itself at the runtime
 *
 * UNIT DESCRIPTION: Interrupt service routine that will be called by hardware under certain conditions
 * These conditions are
 * 1-the interrupt mask of that module is enabled --> Done by the Developer through the UNIT ID
 * 2-the NVIC is enabled for that module --> Done by the Developer through the UNIT ID
 * 3- the global interrupt is enabled --> Done by the Developer
 * 4- Register the callback function pointer ---> Done by the Developer
 * 5- Rising the flag of that module under certain condition --> Done by Hardware
 *
 * That Function related to the external interrupt of PORTD
 * */
EXTIDIntHandler(){

    if (EXTI_Callback[PortD] != NULL_PTR){

    (*EXTI_Callback[PortD])();

    }

}

/************************  UNIT ID: 3.3.5 **********************************/
/* UNIT ID: 3.3.5
 *
 * UNIT NAME:EXTIAIntDefaultHandler
 *
 * UNIT LOCATION: FLASH
 * we can not write on the FLASH memory at runtime that's why we add a call back function in the implementation
 * as we CAN NOT change the implementation of the function itself but we can SOLVE that problem by
 * adding a pointer to function. Hence, we can let the pointer point to any function we want in the runtime
 * without changing the implementation of the function itself at the runtime
 *
 * UNIT DESCRIPTION: Interrupt service routine that will be called by hardware under certain conditions
 * These conditions are
 * 1-the interrupt mask of that module is enabled --> Done by the Developer through the UNIT ID
 * 2-the NVIC is enabled for that module --> Done by the Developer through the UNIT ID
 * 3- the global interrupt is enabled --> Done by the Developer
 * 4- Register the callback function pointer ---> Done by the Developer
 * 5- Rising the flag of that module under certain condition --> Done by Hardware
 *
 * That Function related to the external interrupt of PORTE
 * */
EXTIEIntHandler(){

    if (EXTI_Callback[PortE] != NULL_PTR){

    (*EXTI_Callback[PortE])();

    }

}

/************************  UNIT ID: 3.3.6 **********************************/
/* UNIT ID: 3.3.6
 *
 * UNIT NAME:EXTIAIntDefaultHandler
 *
 * UNIT LOCATION: FLASH
 * we can not write on the FLASH memory at runtime that's why we add a call back function in the implementation
 * as we CAN NOT change the implementation of the function itself but we can SOLVE that problem by
 * adding a pointer to function. Hence, we can let the pointer point to any function we want in the runtime
 * without changing the implementation of the function itself at the runtime
 *
 * UNIT DESCRIPTION: Interrupt service routine that will be called by hardware under certain conditions
 * These conditions are
 * 1-the interrupt mask of that module is enabled --> Done by the Developer through the UNIT ID
 * 2-the NVIC is enabled for that module --> Done by the Developer through the UNIT ID
 * 3- the global interrupt is enabled --> Done by the Developer
 * 4- Register the callback function pointer ---> Done by the Developer
 * 5- Rising the flag of that module under certain condition --> Done by Hardware
 *
 * That Function related to the external interrupt of PORTF
 * */


EXTIFIntHandler(){

    if (EXTI_Callback[PortF] != NULL_PTR){

    (*EXTI_Callback[PortF])();
    }



}



 /************************************************ UNIT ID =3.2.2**************************************************************/
 /* creating an array of pointers to registers
  * the user (or the application layer) will not be allowed to have access to the hardware registers
  * because it's not his/her concern
  * he/she will only be allowed to call the interfacing functions in the GPIO.h file
  * for that reason a keyword static will be added
  *
  * A constant keyword is added because the location of the register never changes
  * so for safety no one can change the location of the pointer the only value that can be changed is the value INSIDE
  * the register ---> the value that the pointer is pointing to*/
 /**************************************************************************************************************/
 volatile GPIO_InterruptSense_Reg static* const GPIO_InterruptSense_Registers[6] ={

      (GPIOIS_PortA_R),
      (GPIOIS_PortB_R),
      (GPIOIS_PortC_R),
      (GPIOIS_PortD_R),
      (GPIOIS_PortE_R),
      (GPIOIS_PortF_R)

 };
/**************************************************************************************************************/
 /* creating an array of pointers to registers
  * the user (or the application layer) will not be allowed to have access to the hardware registers
  * because it's not his/her concern
  * he/she will only be allowed to call the interfacing functions in the GPIO.h file
  * for that reason a keyword static will be added
  *
  * A constant keyword is added because the location of the register never changes
  * so for safety no one can change the location of the pointer the only value that can be changed is the value INSIDE
  * the register ---> the value that the pointer is pointing to*/
/**************************************************************************************************************/
 //volatile GPIO_InterruptBothEdges_Reg static* const GPIO_InterruptBothEdges_Registers[6] ={

 //     (GPIOIBE_PortA_R),
//      (GPIOIBE_PortA_R),
 //     (GPIOIBE_PortA_R),
 //     (GPIOIBE_PortA_R),
 //     (GPIOIBE_PortA_R),
 //     (GPIOIBE_PortA_R)

// };
/*****************************************Pre-Condition for accessing the GPIOIBE Reg  ****************************************************/
/*
 * the interrupt sense register must be configured first
 */
 volatile GPIO_InterruptEvent_Reg static* const GPIO_InterruptEvent_Registers[6] ={

      (GPIOIEV_PortA_R),
      (GPIOIEV_PortB_R),
      (GPIOIEV_PortC_R),
      (GPIOIEV_PortD_R),
      (GPIOIEV_PortE_R),
      (GPIOIEV_PortF_R)

 };

 /**************************************************************************************************************/
  /* creating an array of pointers to registers
   * the user (or the application layer) will not be allowed to have access to the hardware registers
   * because it's not his/her concern
   * he/she will only be allowed to call the interfacing functions in the GPIO.h file
   * for that reason a keyword static will be added
   *
   * A constant keyword is added because the location of the register never changes
   * so for safety no one can change the location of the pointer the only value that can be changed is the value INSIDE
   * the register ---> the value that the pointer is pointing to*/
 /**************************************************************************************************************/
 volatile GPIO_InterruptMask_Reg static* const GPIO_InterruptMask_Registers[6] ={

      (GPIOIM_PortA_R),
      (GPIOIM_PortB_R),
      (GPIOIM_PortC_R),
      (GPIOIM_PortD_R),
      (GPIOIM_PortE_R),
      (GPIOIM_PortF_R)

 };

 /**************************************************************************************************************/
  /* creating an array of pointers to registers
   * the user (or the application layer) will not be allowed to have access to the hardware registers
   * because it's not his/her concern
   * he/she will only be allowed to call the interfacing functions in the GPIO.h file
   * for that reason a keyword static will be added
   *
   * A constant keyword is added because the location of the register never changes
   * so for safety no one can change the location of the pointer the only value that can be changed is the value INSIDE
   * the register ---> the value that the pointer is pointing to*/
 /**************************************************************************************************************/
 volatile GPIO_Data_Reg static * const GPIO_Data_Registers[6]={

       (GPIO_Data_Reg*) &GPIO_PortA_Data,
       (GPIO_Data_Reg*) &GPIO_PortB_Data,
       (GPIO_Data_Reg*) &GPIO_PortC_Data,
       (GPIO_Data_Reg*) &GPIO_PortD_Data,
       (GPIO_Data_Reg*) &GPIO_PortE_Data,
       (GPIO_Data_Reg*) &GPIO_PortF_Data

 };

 /**************************************************************************************************************/
  /* creating an array of pointers to registers
   * the user (or the application layer) will not be allowed to have access to the hardware registers
   * because it's not his/her concern
   * he/she will only be allowed to call the interfacing functions in the GPIO.h file
   * for that reason a keyword static will be added
   *
   * A constant keyword is added because the location of the register never changes
   * so for safety no one can change the location of the pointer the only value that can be changed is the value INSIDE
   * the register ---> the value that the pointer is pointing to*/
 /**************************************************************************************************************/
 volatile GPIO_Direction_Reg static * const GPIO_Direction_Registers[6]={

      (GPIO_Direction_Reg*) &GPIO_PortA_Direction,
      (GPIO_Direction_Reg*) &GPIO_PortB_Direction,
      (GPIO_Direction_Reg*) &GPIO_PortC_Direction,
      (GPIO_Direction_Reg*) &GPIO_PortD_Direction,
      (GPIO_Direction_Reg*) &GPIO_PortE_Direction,
      (GPIO_Direction_Reg*) &GPIO_PortF_Direction

 };

 /**************************************************************************************************************/
  /* creating an array of pointers to registers
   * the user (or the application layer) will not be allowed to have access to the hardware registers
   * because it's not his/her concern
   * he/she will only be allowed to call the interfacing functions in the GPIO.h file
   * for that reason a keyword static will be added
   *
   * A constant keyword is added because the location of the register never changes
   * so for safety no one can change the location of the pointer the only value that can be changed is the value INSIDE
   * the register ---> the value that the pointer is pointing to*/
 /**************************************************************************************************************/
 volatile GPIO_DigitalEnable_Reg static * const GPIO_DigitalEnable_Registers[6]={
        GPIO_PortA_DigitalEnable,
        GPIO_PortB_DigitalEnable,
        GPIO_PortC_DigitalEnable,
        GPIO_PortD_DigitalEnable,
        GPIO_PortE_DigitalEnable,
        GPIO_PortF_DigitalEnable

 };

 /**************************************************************************************************************/
  /* creating an array of pointers to registers
   * the user (or the application layer) will not be allowed to have access to the hardware registers
   * because it's not his/her concern
   * he/she will only be allowed to call the interfacing functions in the GPIO.h file
   * for that reason a keyword static will be added
   *
   * A constant keyword is added because the location of the register never changes
   * so for safety no one can change the location of the pointer the only value that can be changed is the value INSIDE
   * the register ---> the value that the pointer is pointing to*/
 /**************************************************************************************************************/
 volatile GPIO_AFSEL_Reg static *const GPIO_AlternateFunctionSelect_Registers[6]={

       GPIO_PortA_AlternateFunctionSelect,
       GPIO_PortB_AlternateFunctionSelect,
       GPIO_PortC_AlternateFunctionSelect,
       GPIO_PortD_AlternateFunctionSelect,
       GPIO_PortE_AlternateFunctionSelect,
       GPIO_PortF_AlternateFunctionSelect
 };
 /**************************************************************************************************************/
  /* creating an array of pointers to registers
   * the user (or the application layer) will not be allowed to have access to the hardware registers
   * because it's not his/her concern
   * he/she will only be allowed to call the interfacing functions in the GPIO.h file
   * for that reason a keyword static will be added
   *
   * A constant keyword is added because the location of the register never changes
   * so for safety no one can change the location of the pointer the only value that can be changed is the value INSIDE
   * the register ---> the value that the pointer is pointing to*/
 /**************************************************************************************************************/
 volatile GPIO_AMSEL_Reg static *const GPIO_AnalogModeSelect_Registers[6]={

      GPIO_PortA_AnalogModeSelect,
      GPIO_PortB_AnalogModeSelect,
      GPIO_PortC_AnalogModeSelect,
      GPIO_PortD_AnalogModeSelect,
      GPIO_PortE_AnalogModeSelect,
      GPIO_PortF_AnalogModeSelect

 };

 /**************************************************************************************************************/
  /* creating an array of pointers to registers
   * the user (or the application layer) will not be allowed to have access to the hardware registers
   * because it's not his/her concern
   * he/she will only be allowed to call the interfacing functions in the GPIO.h file
   * for that reason a keyword static will be added
   *
   * A constant keyword is added because the location of the register never changes
   * so for safety no one can change the location of the pointer the only value that can be changed is the value INSIDE
   * the register ---> the value that the pointer is pointing to*/
 /**************************************************************************************************************/
 volatile u32_t static * const GPIO_PortControl_Registers[6]={

      GPIO_PortA_PortControl,
      GPIO_PortB_PortControl,
      GPIO_PortC_PortControl,
      GPIO_PortD_PortControl,
      GPIO_PortE_PortControl,
      GPIO_PortF_PortControl

 };

 /**************************************************************************************************************/
  /* creating an array of pointers to registers
   * the user (or the application layer) will not be allowed to have access to the hardware registers
   * because it's not his/her concern
   * he/she will only be allowed to call the interfacing functions in the GPIO.h file
   * for that reason a keyword static will be added
   *
   * A constant keyword is added because the location of the register never changes
   * so for safety no one can change the location of the pointer the only value that can be changed is the value INSIDE
   * the register ---> the value that the pointer is pointing to*/
 /**************************************************************************************************************/
volatile u32_t static * const GPIO_LOCK_Registers[6]={

       GPIO_PortA_LOCK,
       GPIO_PortB_LOCK,
       GPIO_PortC_LOCK,
       GPIO_PortD_LOCK,
       GPIO_PortE_LOCK,
       GPIO_PortF_LOCK

};

/**************************************************************************************************************/
 /* creating an array of pointers to registers
  * the user (or the application layer) will not be allowed to have access to the hardware registers
  * because it's not his/her concern
  * he/she will only be allowed to call the interfacing functions in the GPIO.h file
  * for that reason a keyword static will be added
  *
  * A constant keyword is added because the location of the register never changes
  * so for safety no one can change the location of the pointer the only value that can be changed is the value INSIDE
  * the register ---> the value that the pointer is pointing to*/
/**************************************************************************************************************/
volatile GPIO_CR_Reg static *const GPIO_Port_Commit[6]={

      GPIO_PortA_Commit,
      GPIO_PortB_Commit,
      GPIO_PortC_Commit,
      GPIO_PortD_Commit,
      GPIO_PortE_Commit,
      GPIO_PortF_Commit

};

/**************************************************************************************************************/
 /* creating an array of pointers to registers
  * the user (or the application layer) will not be allowed to have access to the hardware registers
  * because it's not his/her concern
  * he/she will only be allowed to call the interfacing functions in the GPIO.h file
  * for that reason a keyword static will be added
  *
  * A constant keyword is added because the location of the register never changes
  * so for safety no one can change the location of the pointer the only value that can be changed is the value INSIDE
  * the register ---> the value that the pointer is pointing to*/
/**************************************************************************************************************/
volatile GPIO_ICR_Reg static * const GPIO_InterruptClear_Registers[6]={

       (GPIO_ICR_Reg*) &GPIO_PortA_InterruptClear,
       (GPIO_ICR_Reg*) &GPIO_PortB_InterruptClear,
       (GPIO_ICR_Reg*) &GPIO_PortC_InterruptClear,
       (GPIO_ICR_Reg*) &GPIO_PortD_InterruptClear,
       (GPIO_ICR_Reg*) &GPIO_PortE_InterruptClear,
       (GPIO_ICR_Reg*) &GPIO_PortF_InterruptClear


};

 /*****************************  UNIT ID: 3.3.9 **********************************/
 /* UNIT ID: 3.3.9
  *
  * UNIT NAME : GPIO_SetPinStatus
  *
  * UNIT LOCATION: .text section
  *
  * UNIT DESCRIPTION: This function is responsible for setting a defined status for GPIO pin [OUTPUT - INPUT_FLOAT]
  *
  * PRE-CONDITION 1:the port clock of the specified pin must be enabled through the
  * function with UNIT ID: 3.3.7
  *
  * PRE-CONDITION 2: the selected channel within the maximum ChannelNum_t definition
  * PRE-CONDITION 3: the selected port within the maximum PortNum_t definition
  * PRE-CONDITION 4: the selected state within the maximum PinState_t definition
  *
  * POST-CONDITIONS: the pin with number ChannelNum will be a digital pin
  * POST-CONDITIONS: the pin status with number ChannelNum will be State
  *
  * @input : the number of the port
  * @input : the number of the pin
  * @input : the pin state
  *
  * @return:void
  */

void GPIO_SetPinStatus(PortNum_t PortNum, ChannelNum_t ChannelNum, PinState_t State ){

    //assert( (PortNum =>MinNumPort) && (PortNum <= MaxNumPort));
    //assert( (ChannelNum =>MinNumChannel) && (ChannelNum <= MaxNumChannel));
    //assert( (State =>MinNumState) && (State <= MaxNumState));


    switch (State){

    case InputFloat:
    (*GPIO_Direction_Registers[PortNum]).bits.Direction &= ~(1<<ChannelNum);
    break;

    case Output:
    (*GPIO_Direction_Registers[PortNum]).bits.Direction |=(1<<ChannelNum);
  //  (*GPIO_Data_Registers[PortNum]).bits.Data |= (1<<ChannelNum);
    break;

    }


}

void GPIO_SetData(PortNum_t PortNum , ChannelNum_t ChannelNum, OutputValue_t OutputValue){

    /* check that already the pin is an output pin before writing on the data register */
    if ( (*GPIO_Direction_Registers[PortNum]).bits.Direction>>ChannelNum & 1  ){

        switch (OutputValue){

         case OutputLow:
             (*GPIO_Data_Registers[PortNum]).bits.Data &= ~(1<<ChannelNum);
           break;

        case OutputHigh:
            (*GPIO_Data_Registers[PortNum]).bits.Data |= (1<<ChannelNum);
            //GPIO_PORTF_DATA_R |= (1<<ChannelNum);
           break;
        }


    }

}


void GPIO_TogglePinValue(PortNum_t PortNum, ChannelNum_t ChannelNum){

    /* check that already the pin is an output pin before writing on the data register */
   // if ( (*GPIO_Direction_Registers[PortNum]).bits.Direction>>ChannelNum & 1  ){

        (*GPIO_Data_Registers[PortNum]).bits.Data ^= (1<<ChannelNum);
    //}


}

void GPIO_ConfigureAlternateFunctionSelect(PortNum_t PortNum, ChannelNum_t ChannelNum , AFSEL_Mode mode){

    switch(mode){

    case Disable_AFSEL:
        (*GPIO_AlternateFunctionSelect_Registers[PortNum]).bits.AlternateFunctionSelect &= ~(1<<ChannelNum);
        break;

    case Enable_AFSEL:
       (*GPIO_AlternateFunctionSelect_Registers[PortNum]).bits.AlternateFunctionSelect |= (1<<ChannelNum);
        break;
    }


}

void GPIO_EnableRunModeClockGateControl(PortNum_t num){

     GPIO_RunModeClockGatingControl->Bits.GPIOPortRunModeClockGatingControl |= (1<<num);

 }

void GPIO_ConfigureAnalogModeSelect(PortNum_t PortNum, ChannelNum_t ChannelNum, AMSEL_Mode mode){

    switch (mode){

    case Disable_AMSEL:
        (*GPIO_AnalogModeSelect_Registers[PortNum]).bits.AnalogModeSelect &= ~(1<<ChannelNum);
        break;

    case Enable_AMSEL:
        (*GPIO_AnalogModeSelect_Registers[PortNum]).bits.AnalogModeSelect |= (1<<ChannelNum);
        break;
    }

}

void GPIO_ConfigurePortControl(PortNum_t PortNum, ChannelNum_t ChannelNum, MuxValue_t value ){

/****************************************************************************************************************/
    *GPIO_PortControl_Registers[PortNum] &= ~( (u32_t)0xF << (ChannelNum*4) );

    /* IMPORTANT NOTE:
     * that  Operation was performed because
     *
     * IF the bit in that register was already set
     * with a value 1 before and IF you initialize it
     * with a value zero,
     * the value inserted in the register will be not be zero
     * it will be one because it is an OR operation in the line below
     */
/****************************************************************************************************************/

    *GPIO_PortControl_Registers[PortNum] |= ( (u32_t)value << ChannelNum*4);

    //to remove that warning --> implicit conversion changes signedness 'int' to 'unsigned long'
    //    casting was performed


}

void GPIO_ConfigureDigitalEnable(PortNum_t PortNum, ChannelNum_t ChannelNum, DigitalMode_t mode){


    switch (mode){

    case DisableDigitalFunction:
        (*GPIO_DigitalEnable_Registers[PortNum]).bits.DigitalEnable &= ~(1<<ChannelNum);
        break;

    case EnableDigitalFunction:
        (*GPIO_DigitalEnable_Registers[PortNum]).bits.DigitalEnable |=(1<<ChannelNum);
        break;

    }

}

void GPIO_ConfigureCommit(PortNum_t PortNum, ChannelNum_t ChannelNum, LockMode_t mode){

    switch (mode){

    case EnableLock:
        *GPIO_LOCK_Registers[PortNum] = 0;
        break;

    case DisableLock:
        *GPIO_LOCK_Registers[PortNum] = 0x4C4F434B;
        (*GPIO_Port_Commit[PortNum]).bits.commit |=(1<<ChannelNum);
        break;

    }
}


void GPIO_EXTIClearInterrupt(PortNum_t PortNum, ChannelNum_t ChannelNum){

    (*GPIO_InterruptClear_Registers[PortNum]).bits.InterruptClear |= (1<<ChannelNum);

}

void GPIO_ConfigureInterruptMask(PortNum_t PortNum, ChannelNum_t ChannelNum,InterruptMaskMode_t mode){

    switch(mode){
    case Enable_InterruptMask:
        (*GPIO_InterruptMask_Registers[PortNum]).Bits.InterruptMaskEnable |= (1<<ChannelNum);
    break;

    case Disable_InterruptMask:
        (*GPIO_InterruptMask_Registers[PortNum]).Bits.InterruptMaskEnable &= ~(1<<ChannelNum);
    break;

    }

}

 void GPIO_EXTI_Initialization(GPIO_EXTI_Config* pt_channel_config, PortNum_t num, ChannelNum_t ChannelNum){

/****************************************************************************************************************/

     //(*GPIO_InterruptEvent_Registers[num]).Bits.InterruptEvent &= ~(1<<ChannelNum);

     //(*GPIO_InterruptMask_Registers[num]).Bits.InterruptMaskEnable &= ~(1<<ChannelNum);

     /* IMPORTANT NOTE:
      * these  Operations are  performed because
      *
      * IF the bit in any of these four registers was already set
      * with a value 1 before and IF you initialize it
      * with a value zero,
      * the value inserted in the register will be not be zero
      * it will be one because it is an OR operation in the lines below
      */
/****************************************************************************************************************/


    // (*GPIO_InterruptSense_Registers[num]).Bits.Interrupt_Sence |= (pt_channel_config->SenseType);

     //(*GPIO_InterruptBothEdges_Registers[num]).Bits.InterruptBothEdges |= (pt_channel_config->NumEdgeDetection);

     //(*GPIO_InterruptEvent_Registers[num]).Bits.InterruptEvent |= (pt_channel_config->Event);


     //(*GPIO_InterruptClear_Registers[num]).bits.InterruptClear |= (1<<ChannelNum);

     //(*GPIO_InterruptMask_Registers[num]).Bits.InterruptMaskEnable |= (1<<ChannelNum);


     (*GPIO_InterruptSense_Registers[num]).Bits.Interrupt_Sence  &= ~(1<<ChannelNum); //detect edges

     //(*GPIO_InterruptBothEdges_Registers[num]).Bits.InterruptBothEdges &= ~(1<<ChannelNum);

     (*GPIO_InterruptEvent_Registers[num]).Bits.InterruptEvent |= (1<<ChannelNum); //rising edge


     (*GPIO_InterruptClear_Registers[num]).bits.InterruptClear |= (1<<ChannelNum);  //will change the location of that line later

 }



void RegisterCallbackFunction(PortNum_t PortNum,CallbackFunc_t pt_callback){

    EXTI_Callback[PortNum]=pt_callback;

    /* insert the required callback function in the pointer to function --> EXTI_Callback[PortNum]  */


}



