
#ifndef GSM_H_
#define GSM_H_

char GSM_Response (char *ATRes);

void UART_SendString_Polling (char* string,UART_Channel_t channel );

void GSM_Init(void);

void GSM_SMSSend(char* mobileNumber, char*SMSText );


#endif /* GSM_H_ */
