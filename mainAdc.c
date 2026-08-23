#include "adc_read.h"
#include "gpio_output.h"
#include "ADC_DRIVER.h"
#include "ADC_REGISTERS.h"

int main(void){
    //initialize led outputs
     gpio_output_init();
     //initialize the adc
     ADC_driver_init();

     //start adc conversion
     adc_start();

     //continuously take volt readings 
     while(1){
             float volt = adc_getVolt();

             if(volt <= 0.0f){Leds_TurnOffAll();}
             else if(volt > 0.0f && volt < 1.1f){
                       Leds_lowcase();
             }
             else if (volt >= 1.1f && volt < 2.2f){
                Leds_medcase();
             }
             else {  //high case 2.2-3.3
                 Leds_TurnOnAll();
             }

     }












}




