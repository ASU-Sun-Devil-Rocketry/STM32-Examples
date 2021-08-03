/************************************************************* 
* erase    -- get rid of all MCU code                        *
*                                                            * 
* Author: Colton Acosta, cacost12@asu.edu                    *
*                                                            * 
* Date: 7/2/2021                                             *
*************************************************************/ 
#include <stdint.h>

int main(void) { 
    
    // Do nothing forever 
    while (1) { 
        for (int i = 0; i < 1500000; i++) /* Wait a bit. */ 
        __asm__("nop"); 
    } 
 
    return 0; 
} 
