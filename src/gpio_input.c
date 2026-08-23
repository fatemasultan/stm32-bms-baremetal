#include "../inc/bitmath.h"

#define GPIOA_BASE_ADDR       0x40020000
#define GPIOA_MODER_OFFSET    0x00
#define GPIOA_PUPDR_OFFSET    0x0c
#define GPIOA_IDR_OFFSET      0x10
#define RCC_BASE_ADDR         0x40023800 
#define RCC_AB1ENR_OFFSET     0x30

#define GPIOA_MODER    *((volatile unsigned int*)(GPIOA_BASE_ADDR+GPIOA_MODER_OFFSET))
#define GPIOA_PUPDR    *((volatile unsigned int*)(GPIOA_BASE_ADDR+GPIOA_PUPDR_OFFSET))
#define GPIOA_IDR      *((volatile unsigned int*)(GPIOA_BASE_ADDR+GPIOA_IDR_OFFSET))
#define RCC_AB1ENR     *((volatie unsigned int*)(RCC_BASE_ADDR+RCC_AB1ENR_OFFSET))

void gpio_input_init(){
    set_bit(RCC_AHB1ENR,0); //gpioA clock
    //switch 1 -> PA1, input mode-> 00
    clear_bit(GPIOA_MODER,2);
    clear_bit(GPIOA_MODER,3);
    //PUPDR=01 (pull up)
    set_bit(GPIOA_PUPDR,2);
    clear_bit(GPIOA_PUPDR,3); 

    //switch 2 -> PA2
    clear_bit(GPIOA_MODER,4);
    clear_bit(GPIOA_MODER,5);

    set_bit(GPIOA_PUPDR,4);
    clear_bit(GPIOA_PUPDR,5); 

    //switch 3 -> PA3
    clear_bit(GPIOA_MODER,6);
    clear_bit(GPIOA_MODER,7);

    set_bit(GPIOA_PUPDR,6);
    clear_bit(GPIOA_PUPDR,7); 
}

int gpio_readSwitch1(void){
    return get_bit(GPIOA_IDR,1);
}

int gpio_reatSwitch2(void){
    return get_bit(GPIOA_IDR,2);
}

int gpio_readSwitch3(void){
    return get_bit(GPIOA_IDR,3);
}