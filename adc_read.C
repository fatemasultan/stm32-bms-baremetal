//include the header file 
#include "adc_read.h"


//variable that holds the latest voltage
static volatile float final_volt = 0.0f;


void ADC_IRQHandler(void){
//check if flag is set (Eoc)
if(ADC1_SR & ADC_SR_EOC){
    
//store the raw data in a variable
raw_val = (uint16_t)(ADC1_DC & 0x0FFF);

//filtering the output
....





//final battery voltage mapping 0-4095 to 0-3.3volts
final_volt =(raw_val *3.3f) / (4095f);







//function to read the final voltage (by main)
float adc_getVolt(void){

    return final_volt;
}













}




}