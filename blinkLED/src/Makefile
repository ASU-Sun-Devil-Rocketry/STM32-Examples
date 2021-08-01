####################################################################
#  Project
######################################################################

# Program Name 
PROGRAM = blink

# Compiler
CC = arm-none-eabi-gcc

# Processor 
MPU = -mcpu=cortex-m3

# Compiler Arguments
CCARG =  -O0 -g -std=c99 -mthumb -Wall # Optimize for space, add debuging, C99 standard C

# Linker Arguments
LLARG = -T stm32_ls.ld -nostdlib -Wl,-Map=$(PROGRAM).map

blink.bin: $(PROGRAM).elf
	arm-none-eabi-objcopy -O binary $(PROGRAM).elf $(PROGRAM).bin

blink.elf: $(PROGRAM).o
	$(CC) $(LLARG) $(MPU) -o $(PROGRAM).elf $(PROGRAM).o

blink.o: $(PROGRAM).c
	$(CC) $(CCARG) $(MPU) -c -o $(PROGRAM).o $(PROGRAM).c

flash: 
	st-flash write $(PROGRAM).bin 0x08000000

clean: 
	rm *.bin *.o *.map  *.elf *.d 

# End
