#####################################################################
#  Project
######################################################################

# Program Name 
PROGRAM = erase 

# Compiler
CC = arm-none-eabi-gcc

# Processor 
MPU = -mcpu=cortex-m3
MPU += -mfloat-abi=soft # Software FPU

# Compiler Arguments
CCARG = -Os -g -std=c99 -MD # Optimize for space, add debuging, C99 standard C
CCARG += -ffunction-sections -fdata-sections # Options for program organization

# Warning Options
WARN = -Wall -Wundef -Wimplicit-function-declaration -Wredundant-decls -Wmissing-prototypes -Wstrict-prototypes

# Library Directory
LIBDIR = ../lib

# Linker Script
LNK = $(LIBDIR)/stm32f103c8t6.ld


erase.bin: $(PROGRAM).elf
	arm-none-eabi-objcopy -Obinary $(PROGRAM).elf $(PROGRAM).bin

erase.elf: $(PROGRAM)
	$(CC) -nostartfiles -T$(LNK) $(MPU) $(PROGRAM).o -Wl,-lopencm3_stm32f1 -o $(PROGRAM).elf

erase.o: $(PROGRAM).c
	$(CC) $(CCARG) $(MPU) $(WARN) -I$(LIBDIR) -DSTM32F1 -o $(PROGRAM).o -c $(PROGRAM).c

flash: 
	st-flash write $(PROGRAM).bin 0x8000000

clean: 
	rm *.bin *.o *.elf *.d 

# End
