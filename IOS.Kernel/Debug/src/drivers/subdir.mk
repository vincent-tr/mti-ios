################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/drivers/console.c 

OBJS += \
./src/drivers/console.o 

C_DEPS += \
./src/drivers/console.d 


# Each subdirectory must supply rules for building sources it contributes
src/drivers/%.o: ../src/drivers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C Compiler'
	i386-elf-gcc -c -nostdinc -DIOS_KERNEL -I"/cygdrive/d/Programmation/IOS/workspace/IOS.Kernel/src" -O2 -g -Wall -ffreestanding -nostdlib -std=c99 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


