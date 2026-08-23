    .syntax unified
    .cpu cortex-m4
    .thumb

/* ===================== Stack ===================== */
    .word _estack

/* ===================== Vector Table ===================== */
    .section .isr_vector, "a", %progbits
    .type g_pfnVectors, %object
    .global g_pfnVectors

g_pfnVectors:
    .word _estack                /* 0  Initial Stack Pointer            */
    .word Reset_Handler          /* 1  Reset Handler                    */
    .word Default_Handler        /* 2  NMI                              */
    .word Default_Handler        /* 3  HardFault                        */
    .word Default_Handler        /* 4  MemManage                        */
    .word Default_Handler        /* 5  BusFault                         */
    .word Default_Handler        /* 6  UsageFault                       */
    .word 0                      /* 7  Reserved                         */
    .word 0                      /* 8  Reserved                         */
    .word 0                      /* 9  Reserved                         */
    .word 0                      /* 10 Reserved                         */
    .word Default_Handler        /* 11 SVCall                           */
    .word Default_Handler        /* 12 DebugMonitor                     */
    .word 0                      /* 13 Reserved                         */
    .word Default_Handler        /* 14 PendSV                           */
    .word Default_Handler        /* 15 SysTick                          */
    /* External interrupts (STM32F401xC) can be added here as needed,
       e.g. ADC_IRQHandler at position 18 (offset 0x64):
       .word Default_Handler      * 18 ADC1                             */

/* ===================== Reset Handler ===================== */
    .section .text.Reset_Handler
    .weak Reset_Handler
    .type Reset_Handler, %function

Reset_Handler:
    /* Copy .data section from FLASH to SRAM */
    ldr r0, =_sidata
    ldr r1, =_sdata
    ldr r2, =_edata
copy_data_loop:
    cmp r1, r2
    bge copy_data_done
    ldr r3, [r0], #4
    str r3, [r1], #4
    b copy_data_loop
copy_data_done:

    /* Zero-fill .bss section */
    ldr r1, =_sbss
    ldr r2, =_ebss
    movs r3, #0
zero_bss_loop:
    cmp r1, r2
    bge zero_bss_done
    str r3, [r1], #4
    b zero_bss_loop
zero_bss_done:

    /* Call C++ static constructors (global ctors) */
    bl __libc_init_array

    /* Jump to main */
    bl main

    /* If main returns, loop forever */
hang:
    b hang
    .size Reset_Handler, .-Reset_Handler

/* Empty _init/_fini stubs.
   Normally supplied by crti.o/crtn.o, which -nostartfiles excludes.
   __libc_init_array() (called above) requires a symbol named _init to exist. */
    .section .text._init
    .weak _init
    .type _init, %function
_init:
    bx lr
    .size _init, .-_init

    .section .text._fini
    .weak _fini
    .type _fini, %function
_fini:
    bx lr
    .size _fini, .-_fini

/* ===================== Default Handler ===================== */
    .section .text.Default_Handler, "ax", %progbits
Default_Handler:
    b Default_Handler
    .size Default_Handler, .-Default_Handler

    .end
