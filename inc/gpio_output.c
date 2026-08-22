#include "bitmath.h"

#define GPIOB_BASE_ADOR       0x40020400
#define GPIOB_MODER_OFFSET    0x00
#define GPIOB_ODR_OFFSET      0X14
#define RCC_BASE_ADOR         0x40023800
#define RCC_AHB1ENR_OFFSET           0x30
#define GPIOB_MODER           (*((volatile unsigned int*)(GPIOB_BASE_ADOR+GPIOB_MODER_OFFSET)))
#define GPIOB_ODR             (*((volatile unsigned int*)(GPIOB_ODR_OFFSET+GPIOB_BASE_ADOR)))
#define RCC_AHB1ENR           (*((volatile unsigned int*)(RCC_BASE_ADOR+RCC_AHB1ENR_OFFSET)))


//setup output functions

//INIT
void gpio_output_init(void){
    set_bit(RCC_AHB1ENR,0);
    //1
    set_bit(GPIOB_MODER,2);
    clear_bit(GPIOB_MODER,3);
    //2
    set_bit(GPIOB_MODER,4);
    clear_bit(GPIOB_MODER,5);
    //3
    set_bit(GPIOB_MODER,6);
    clear_bit(GPIOB_MODER,7);
}
//loop functions
//High voltage case 
void Leds_TurnOnAll(void){
    set_bit(GPIOB_ODR,1)
    set_bit(GPIOB_ODR,2)
    set_bit(GPIOB_ODR,3)

}
//Turn off all
void Leds_TurnOffAll(void){
    clear_bit(GPIOB_ODR,1)
    clear_bit(GPIOB_ODR,2)
    clear_bit(GPIOB_ODR,3)

}
//Medium voltage case
void Leds_medcase(void){
    set_bit(GPIOB_ODR,1)
    set_bit(GPIOB_ODR,2)
    clear_bit(GPIOB_ODR,3)

}
//Low voltage case
void Leds_lowcase(void){
    set_bit(GPIOB_ODR,1)
    clear_bit(GPIOB_ODR,2)
    clear_bit(GPIOB_ODR,3)

}
