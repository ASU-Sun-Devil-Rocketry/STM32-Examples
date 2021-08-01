####################################################################
#  Project
######################################################################

# Program Name 
PROGRAM = blink

# Compiler
CC = arm-none-eabi-gcc

# Assembler
ASM = arm-none-eabi-as

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


# Generate the ARM Assembly Language 
assembly: 
	$(CC) $(CCARG) $(MPU) -S -o $(PROGRAM).asm $(PROGRAM).c

# Generate the output of the preprocessor
pre-process: 
	$(CC) $(CCARG) $(MPU) -E -o $(PROGRAM).i $(PROGRAM).c

# Flash the executable file to the microcontroller
flash: 
	st-flash write $(PROGRAM).bin 0x08000000

# Remove all build files
clean: 
	rm *.bin *.o *.map  *.elf *.d 

# End
