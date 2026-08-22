#ifndef BITMATH_H
#define BITMATH_H

#define set_bit(REG, BIT)   ((REG) |= (1U<<(BIT)));
#define clear_bit(REG, BIT)  ((REG) &= (~(1U<<(BIT))));
#define get_bit(REG, BIT)    (((REG)>>(BIT)) & 1U);
#define toggle_bit(REG, BIT)  ((REG)^=(1U << (BIT)));

#endif