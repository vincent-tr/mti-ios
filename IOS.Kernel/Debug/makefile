################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := del

# All of the sources participating in the build are defined here
-include sources.mk
-include src/drivers/subdir.mk
-include src/core/subdir.mk
-include src/boot/subdir.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: IOS.Kernel

# Tool invocations
IOS.Kernel: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cygwin C Linker'
	i386-elf-gcc -nostdlib -T ../support/kernel.lds -o "IOS.Kernel" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES) IOS.Kernel
	-@echo ' '

post-build:
	-@echo 'deploy'
	-cp /cygdrive/d/Programmation/IOS/workspace/IOS.Kernel/Debug/IOS.Kernel /cygdrive/d/Programmation/IOS/debug/netdir/IOS.Kernel.img
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
