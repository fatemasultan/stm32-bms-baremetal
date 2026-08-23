#ifndef ADC_READ_H
#define ADC_READ_H
//the stm file to map all the register adresses
#include "stm32f401xc.h"
//adc driver file
#include "ADC_DRIVER.h"


//to start the conversion
void adc_start(void);
//to return the final voltage 
float adc_getVolt(void);

//interrupt service routine function that handles everything 
//standard function 
void ADC_IRQHandler(void);

#endif


