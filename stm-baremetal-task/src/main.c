#include "gpio_output.h"
#include "gpio_input.h"
#include <stdint.h>

void setup(void) {
    gpio_output_init();
    gpio_input_init();
}

void loop(void) {
     uint8_t pressed_count=0;

    if (gpio_readSwitch1() == 0) {
        pressed_count++;
     }
    if (gpio_readSwitch2() == 0) {
        pressed_count++;
     }
    if (gpio_readSwitch3() == 0) {
        pressed_count++;
     }
    if (pressed_count==3){
        Leds_TurnOnAll();
     }
    else if(pressed_count==2)  {
        Leds_medcase();
    }
    else if(pressed_count==1){
       Leds_lowcase();
     } 
    else{
        Leds_TurnOffAll();
    }
}

int main(void) {
    setup();

    while (1) {
        loop();
    }

    return 0;
}