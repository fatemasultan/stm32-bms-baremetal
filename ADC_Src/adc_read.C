// include the header files
#include "adc_read.h"
#include "ADC_REGISTERS.h"
#include "bitmath.h"

// variable that holds the latest voltage
static volatile float final_volt = 0.0f;

// buffer and index allocated for the filtering
static uint16_t buffer[8] = {0,0,0,0,0,0,0,0};
static uint8_t index = 0;

// to start the conversion
void adc_start(void){
    set_bit(ADC_CR2, 30);
}

void ADC_IRQHandler(void){
    // check if flag is set (EOC is Bit 1 in ADC_SR)
    if(ADC_SR & (1 << 1)){
        
        // store the raw data in a variable
        uint16_t raw_val = (uint16_t)(ADC_DR & 0x0FFF);

        // filtering the output using circular buffer
        buffer[index] = raw_val;
        index = (index + 1) % 8;

        uint32_t sum = 0;
        for(uint8_t i = 0; i < 8; i++){
            sum += buffer[i];
        }
        float avg = (float)sum / 8.0f;

        // final battery voltage mapping 0-4095 to 0-3.3volts
        final_volt = (avg * 3.3f) / 4095.0f;
    }
}

// function to read the final voltage (by main)
float adc_getVolt(void){
    return final_volt;
}