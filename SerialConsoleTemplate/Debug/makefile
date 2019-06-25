################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include startup/subdir.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: SerialConsoleTemplate.elf

# Tool invocations
SerialConsoleTemplate.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU GCC Linker'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=nano.specs -u _scanf_float -u _printf_float -T"D:\Embeded System 2\SerialConsoleTemplate\LinkerScript.ld" -Wl,-Map=output.map -Wl,--gc-sections -lm -o "SerialConsoleTemplate.elf" @"objects.list" $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

post-build:
	-@echo 'Generating binary and Printing size information:'
	arm-none-eabi-objcopy -O binary "SerialConsoleTemplate.elf" "SerialConsoleTemplate.bin"
	arm-none-eabi-size "SerialConsoleTemplate.elf"
	arm-none-eabi-objdump -S "SerialConsoleTemplate.elf" > "SerialConsoleTemplate.lst"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
