/************************************************************* 
* binVisual -- Program to visualize 32 bit binary numbers    *
*              for debugging purposes. Includes a function   *
*              which takes as input a 32 bit unsigned binary *
*              number and prints it to the console. Use the  *
*              main function for calculations and bit        *
*              manipulations to be performed prior to        *
*              printing                                      *
*                                                            * 
* Author: Colton Acosta                                      *
*                                                            * 
* Date: 7/26/2021                                            *
*************************************************************/ 
#include <stdint.h>
#include <stdio.h>

uint32_t y = 0;
volatile uint32_t* y_ptr = &y;

// printHex: Function to print a Hex number to the console
// Input: Unsigned 32 bit integer
// Output: None
void printHex(uint32_t num){
    printf("Output: 0x%x\n", num);
}

int main(void){

    uint32_t tempMask = ~((1<<3) | (1<<2));
    uint32_t data = 0xFFFFFFFF;
    data &= tempMask;
    printHex(data);
    return(0);
}
