######################################################################
#  ARM Cortex-M3 Example Makefile
#
#  Main Build Process: 
#      1. Compile program.c and startup.c sourcefiles to .o files
#      2. Run the linker to generate the merged .elf file
#      3. Copy the .elf file into .bin format for the MCU
#      4. Flash the MCU with the .bin file via the SWD interface and
#         the st-flash utility  
#  
#  Additional Build Features:
#      1. pre-process: generate the result of executing the 
#         pre-processor directives
#      2. assembly: generate the assembly from the C source code
#      3. printSymbols: print all the symbols and corresponding 
#         memory addresses produced by the linker
######################################################################

# Program Name 
PROGRAM = erase

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
LLARG =  -mcpu=$(MPU) -nostdlib -g -Wl,-Map=$(PROGRAM).map

all: erase.o startup.o erase.elf erase.bin 

erase.bin: erase.elf
	arm-none-eabi-objcopy -O binary $(PROGRAM).elf $(PROGRAM).bin

erase.elf: erase.o startup.o
	$(CC) $(LLARG) -T erase.ld -o erase.elf erase.o startup.o

startup.o: startup.c
	$(CC) $(CCARG) -c -o startup.o startup.c

erase.o: erase.c
	$(CC) $(CCARG) -c -o erase.o erase.c

# Generate the ARM Assembly Language 
assembly: erase.c 
	$(CC) $(CCARG) -S -o $(PROGRAM).asm $(PROGRAM).c

# Generate the output of the preprocessor
pre-process: erase.c 
	$(CC) $(CCARG) -E -o $(PROGRAM).i $(PROGRAM).c

# Print all the symbols produced by the linker
printSymbols: erase.elf 
	arm-none-eabi-nm $(PROGRAM).elf

# Flash the executable file to the microcontroller
flash: 
	st-flash write $(PROGRAM).bin 0x08000000

# Remove all build files
clean: 
	rm *.bin *.o *.map  *.elf *.d *.asm *.i 

# End
