/************************************************************* 
* blinkLED -- Program that uses the STM32's GPIO to blink an *
*             LED to test the status of the microcontroller  *
*             programmer                                     *
*                                                            * 
* Author: Colton Acosta, cacost12@asu.edu                    *
*                                                            * 
* Date: 7/2/2021                                             *
*************************************************************/ 

#include <libopencm3/stm32/rcc.h> 
#include <libopencm3/stm32/gpio.h> 
 
static void  gpio_setup(void) { 
    /* Enable GPIOC clock. */ 
    rcc_periph_clock_enable(RCC_GPIOC); 

    /* Set GPIO8 (in GPIO port C) to 'output push-pull'. */ 
    gpio_set_mode(GPIOC,GPIO_MODE_OUTPUT_2_MHZ, 
    GPIO_CNF_OUTPUT_PUSHPULL,GPIO14); 
    gpio_clear(GPIOC,GPIO14); /* LED on */ 
}  

int main(void) { 
     
    gpio_setup(); 

    while (1) { 
        for (int i = 0; i < 1500000; i++) /* Wait a bit. */ 
        __asm__("nop"); 
 
        for (int i = 0; i < 500000; i++) /* Wait a bit. */ 
        __asm__("nop"); 
    } 
 
    return 0; 
} 
