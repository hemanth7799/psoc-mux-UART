#include<project.h>
#include <stdio.h>
#define FALSE 0
#define TRUE 1
#define TRANSMIT_BUFFER_SIZE 16

int main()
{
   
     uint output;
       char buffer[16];
     ADC_DelSig_1_Start();
     UART_1_Start();
    
     UART_1_PutString("connected successfully");
     AMux_1_Start();
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    /* CyGlobalIntEnable; */ /* Uncomment this line to enable global interrupts. */
    for(;;)
    {
        AMux_1_FastSelect(0);
        ADC_DelSig_1_StartConvert();
        ADC_DelSig_1_IsEndConversion(ADC_DelSig_1_WAIT_FOR_RESULT);
        output=ADC_DelSig_1_CountsTo_mVolts(ADC_DelSig_1_GetResult16());
        sprintf(buffer,"sensor 1 reading:%u mV\r\n",output);
        UART_1_PutString(buffer);
        CyDelay(1000);
        AMux_1_FastSelect(1);
        ADC_DelSig_1_StartConvert();
        ADC_DelSig_1_IsEndConversion(ADC_DelSig_1_WAIT_FOR_RESULT);
        output=ADC_DelSig_1_CountsTo_mVolts(ADC_DelSig_1_GetResult16());
        sprintf(buffer,"sensor 2 reading: %u   mV\r\n",output);
        UART_1_PutString(buffer);
        CyDelay(1000);
       
       
    }
}

/* [] END OF FILE */
