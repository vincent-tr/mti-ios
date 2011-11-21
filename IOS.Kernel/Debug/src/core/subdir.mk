################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/core/main.c 

OBJS += \
./src/core/main.o 

C_DEPS += \
./src/core/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/core/%.o: ../src/core/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C Compiler'
	i386-elf-gcc -c -nostdinc -DIOS_KERNEL -I"/cygdrive/d/Programmation/IOS/workspace/IOS.Kernel/src" -O2 -g -Wall -ffreestanding -nostdlib -std=c99 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


