#include "ADC_DRIVER.h"
#include "ADC_REGISTERS.h"
#include "bitmath.h"

void ADC_driver_init(){
   
  //starting the clock for ADC1 && GPIOA
  set_bit(RCC_AHB1ENR, 0);
  set_bit(RCC_APB2ENR, 8);
   
  //setting the prescaler so pclk / 4 ---> from calculations
  set_bit(ADC_CCR,16);

  // making it analog type
  set_bit(GPIOA_MODER, 0);
  set_bit(GPIOA_MODER, 1);

  // enabling interrupt
  set_bit(ADC_CR1, 5);
 
  //enabling continous mode
  set_bit(ADC_CR2, 1);
  // a/d converetor on
  set_bit(ADC_CR2, 0);
  

  // no need to write for sqr1 since its only one conversion which is 0000 in sqr "reset value" 
  // same goes for sqr3 ---> channel 0 : 0000
  // same for smpr2 ---> 3 cycles : 000
  // the reset values are checked 








}