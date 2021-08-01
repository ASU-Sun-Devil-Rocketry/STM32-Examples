####################################################################
#  Project
######################################################################

# Program Name 
PROGRAM = blink

# Cross Compiler Compiler
CC = arm-none-eabi-gcc

# Assembler
ASM = arm-none-eabi-as

# Processor 
MPU = cortex-m3

# Compiler Arguments
# Optimize for space, add debugging functionality,
# Use GNU dialect of ISO C11, execute thumb instructions, generate warnings
# during compilation
CCARG =  -mcpu=$(MPU) -O0 -g -std=gnu11 -mthumb -Wall 

# Linker Arguments
LLARG =  -mcpu=$(MPU) -T stm32_ls.ld -nostdlib -Wl,-Map=$(PROGRAM).map

blink.bin: $(PROGRAM).elf
	arm-none-eabi-objcopy -O binary $(PROGRAM).elf $(PROGRAM).bin

blink.elf: $(PROGRAM).o
	$(CC) $(LLARG)  -o $(PROGRAM).elf $(PROGRAM).o

blink.o: $(PROGRAM).c
	$(CC) $(CCARG) -c -o $(PROGRAM).o $(PROGRAM).c

# Generate the ARM Assembly Language 
assembly: 
	$(CC) $(CCARG) -S -o $(PROGRAM).asm $(PROGRAM).c

# Generate the output of the preprocessor
pre-process: 
	$(CC) $(CCARG) -E -o $(PROGRAM).i $(PROGRAM).c

# Flash the executable file to the microcontroller
flash: 
	st-flash write $(PROGRAM).bin 0x08000000

# Remove all build files
clean: 
	rm *.bin *.o *.map  *.elf *.d *.asm *.i 

# End
