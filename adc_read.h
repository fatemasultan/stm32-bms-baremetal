#ifndef adc_read.h
#define adc_read.h
//the stm file to map all the register adresses
#include "stm32f401xc.h"
//adc driver file
#include "ADC_DRIVER.h"

//to return the final voltage 
float adc_getVolt(void);

//interrupt service routine function that handles everything 
//standard function 
void ADC_IRQHandler(void);

#endif


