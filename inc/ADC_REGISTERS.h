#ifndef ADC_REGISTERS_H
#define ADC_REGISTERS_H       

#define GPIOA_BASE_ADDR     0x40020000

#define GPIOA_MODER_OFFSET  0x00

#define ADC_BASE_ADDR       0x40012000


#define ADC_CR1_OFFSET      0x04
#define ADC_CR2_OFFSET      0x08
#define ADC_SQR1_OFFSET     0x2C
#define ADC_SQR3_OFFSET     0x34
#define ADC_SMPR2_OFFSET    0x10
#define ADC_DR_OFFSET       0x4C
#define ADC_SR_OFFSET       0x00
#define ADC_CCR_OFFSET      0x304

#define RCC_BASE_ADDR       0x40023800

#define RCC_AHB1_OFFSET     0x30
#define RCC_APB2_OFFSET     0x44

#define GPIOA_MODER  *((volatile unsigned int *)(GPIOA_BASE_ADDR + GPIOA_MODER_OFFSET))

#define ADC_CR1      *((volatile unsigned int *)(ADC_BASE_ADDR + ADC_CR1_OFFSET))
#define ADC_CR2      *((volatile unsigned int *)(ADC_BASE_ADDR + ADC_CR2_OFFSET))
#define ADC_SQR1     *((volatile unsigned int *)(ADC_BASE_ADDR + ADC_SQR1_OFFSET))
#define ADC_SQR3     *((volatile unsigned int *)(ADC_BASE_ADDR + ADC_SQR3_OFFSET))
#define ADC_SMPR2    *((volatile unsigned int *)(ADC_BASE_ADDR + ADC_SMPR2_OFFSET))
#define ADC_DR       *((volatile unsigned int *)(ADC_BASE_ADDR + ADC_DR_OFFSET))
#define ADC_SR       *((volatile unsigned int *)(ADC_BASE_ADDR + ADC_SR_OFFSET))
#define ADC_CCR      *((volatile unsigned int *)(ADC_BASE_ADDR + ADC_CCR_OFFSET))

#define RCC_AHB1ENR     *((volatile unsigned int *)(RCC_BASE_ADDR + RCC_AHB1_OFFSET))
#define RCC_APB2ENR   *((volatile unsigned int *)(RCC_BASE_ADDR + RCC_APB2_OFFSET))

#endif  