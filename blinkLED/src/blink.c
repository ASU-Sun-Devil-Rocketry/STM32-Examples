/************************************************************* 
* blinkLED -- Program that uses the STM32's GPIO to blink an *
*             LED to test the status of the microcontroller  *
*             programmer. LED must be attached to Pin PCB0   *
*                                                            * 
* Author: Colton Acosta, cacost12@asu.edu                    *
*                                                            * 
* Date: 7/2/2021                                             *
*************************************************************/ 
#include <stdint.h>

// GPIO B Register Boundary: 0x4001 0C00 to 0x4001 0FFF
// GPIOB Low Status Register: 0x4001 0C00
#define GPIOB_CRL     (*((volatile uint32_t*) 0x40010C00))

// GPIOB Output Data Register: 0x4001 0C0C
#define GPIOB_ODR    (*((volatile uint32_t*) 0x40010C0C))

// Peripheral Clock Enable Register: RCC_APB2ENR
// Base Address: 0x4002 1000 
// Address: 0x4002 1018
#define RCC_APB2ENR    (*((volatile uint32_t*) 0x40021018))

void initStatusLED(void){

    // Enable the GPIO Clock
    RCC_APB2ENR |= (1<<3);    

    /* Set PB0 for Output push-pull */
   // uint32_t tempMask = ~((1<<3) | (1<<2));
    GPIOB_CRL &= ~((1<<3) | (1<<2));

    /* Set PB0 to output max speed 2 MHz */
    GPIOB_CRL |= (1<<1);
}

void toggleStatusLED(void){

    /* Toggle the LED output with a bitwise XOR */
    GPIOB_ODR ^= (1<<0);
}

int main(void) {

   // Initialize Status LED Pin
   initStatusLED(); 
     
    while (1) { 

        // Toggle the LED
        toggleStatusLED();

        // Delay
        for (int i = 0; i < 1500000; i++){
            __asm__("nop"); 
        }
    } 
 
    return 0; 
} 
