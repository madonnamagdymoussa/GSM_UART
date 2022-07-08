
#ifdef usegsm
#include "UART.h"
#include "lstd.h"


/*COMMANDS*/
const static char  CMGF_COMMAND[]=  {"AT+CMGF=1"};
const static char  CMGS_COMMAND[]={"AT+CMGS="};
const char TwoCommas = ' " ' ;
const static char mobileNumber[]={"01283375677"};
const static char newline[]={"\n \r"};
const static char Test_ATCommand[] ={"AT\n \r"};
const static char Test_ATE0Command[] ={"ATE0\n \r"};

/*pointer to the start of the array where the response will be stored */
char GSM_Response (char *ATRes){

    char i=0;
    char FlagResponse_ok=0;

    while (*(ATRes)=='\0')
    {
      do
      {
        UART_RecCharwTimeOut(ATRes+i); // Rceive character using the UART_RecCharwTimeOut function and place it in tha array
        i++;
      }
      while(*(ATRes+i-1)!='\0'); // when nothing is receveived by UART_RecCharwTimeOut, a null is returned and saved in the array.

    }

    i=0; //reset the array index to 0
    while (*(ATRes+i)!='\0')       // This loop searches for the word "OK" in the AT command response
    {
      if (*(ATRes+i)=='O' && *(ATRes+i+1)=='K' )
      {
          FlagResponse_ok=1; // if "OK" is found, the variable named ok will be set to 1 otherwise it will stay 0.
        break;
      }
      i++;
    }
    return FlagResponse_ok;    //OK variable is returned by the function

}


 void UART_SendString_Polling (char* string,UART_Channel_t channel ){

     char i=0;
     while (*(string+i) != '\0')
     {

      UART_TransmitChar_Polling(channel, *(string+i));
      i+=1;

     }

 }

void GSM_Init(UART_Channel_t channel){

    //Synchronization as the GSM module is on auto bauding
    char confirm=0; // Will be used to store the return value of the AT_Response function
    char ATResponse[8]={0}; // will be used to store the AT command response that is also coming for the AT_Response function
    char ATEResponse[8]={0}; // will be used to store the ATE0 command response
    char trial=1; //Will be used to count the number of trials to send the AT command and successfully receive an "OK" response.

    while (confirm==0 && trial<=3) // a Maximum of 3 trials is allowed, then the function exits.
    {
      UART_SendString_Polling (Test_ATCommand,channel); // Send "AT" Command
      confirm=GSM_Response(ATResponse); // Receive the response and write it to ATResponse array. The function return value is stored in the variable "confirm"
      trial++; //Increment the number of trials
    }

//    _delay_ms(500); //Allow a delay of 500 ms before send ing the next command
    confirm=0;trial=1; // reset the values of confirm and trial
    while (confirm==0 && trial<=3) // a Maximum of 3 trials is allowed, then the function exits.
    {
        UART_SendString_Polling (Test_ATE0Command,channel); // Send "ATE0" Command
      confirm=GSM_Response(Test_ATE0Command); // Receive the response and write it to ATEResponse array. The function return value is stored in the variable "confirm"
      trial++; //Increment the number of trials

    }
 //   _delay_ms(500);



}


void GSM_SMSSend(char* mobileNumber, char*SMSText, UART_Channel_t channel){

    char CMGSResponse[25]={0};/***********************************************************************************************/
    // will be used to store the response of "AT+CMGS".
    /*The AT+CMGS command sends an SMS message to a GSM phone.*/

    /****************************************************************************************************************************/


    char CMGFResponse[7]={0};/***********************************************************************************************/

    /* will be used to store the response of "AT+CMGF".*/
    /*CMGF command used to store the message format "In PDU MODE" all SMS messages are encoded in hexadecimal
     * characters like 31020B911326880736F40000A900\*/

    /*In the text mode SMS are represented as readable text*/

    /*COMMAND
     * AT+CMGF=<mode><CR>*/
    /*Parameters
     <mode>: 0 = PDU Mode, 1 = Text Mode
     <CR> = ASCII character 13*/
 /****************************************************************************************************************************/

    char SendingResponse [70]={0}; // will be used to store the response after sending the SMS.
    char confirm_OKResponse=0; // will be used to store the returned ok value from AT_Response function.
    mobileNumber++;

    /**********************************************************************************************/
    UART_SendString_Polling (CMGF_COMMAND, channel ); // send (AT+CMGF Command)
    UART_SendString_Polling (newline, channel );
    confirm_OKResponse = GSM_Response (CMGFResponse);
 //   _delay_ms(500);//Allow a delay of 500 ms between commands in order  not to rush the module.

    UART_SendString_Polling (CMGS_COMMAND, channel ); // send (AT+CMGF Command)
    UART_TransmitChar_Polling(channel, TwoCommas);
    UART_SendString_Polling (mobileNumber, channel ); // send (AT+CMGF Command)
    UART_TransmitChar_Polling(channel, TwoCommas);

    UART_SendString_Polling (newline, channel ); // send (AT+CMGF Command)

    //SMSText

}
#endif
