//include the header file 
#include "adc_read.h"


//variable that holds the latest voltage
static volatile float final_volt = 0.0f;

//buffer and index  allocated for the filtering
static uint16_t buffer[8] = {0,0,0,0,0,0,0,0};
static uint8_t index = 0;


void ADC_IRQHandler(void){
//check if flag is set (Eoc)
if(ADC1->SR & ADC_SR_EOC){
    
//store the raw data in a variable
 uint16_t raw_val = (uint16_t)(ADC1->DR & 0x0FFF);

//filtering the output because the step/window is so tiny so it can catch noise
//so we could filter it to get accurate readings
buffer[index] = raw_val;
index = (index + 1) %8;

uint32_t sum =0;
for(uint8_t i =0;i<8;i++){

    sum+=buffer[i];
}
float avg = (float)sum /  8.0f;







//final battery voltage mapping 0-4095 to 0-3.3volts
final_volt =(avg *3.3f) / (4095.0f);





}

//function to read the final voltage (by main)
float adc_getVolt(void){

    return final_volt;
}


















