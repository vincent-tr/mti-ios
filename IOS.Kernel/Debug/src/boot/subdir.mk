################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
../src/boot/boot.S 

OBJS += \
./src/boot/boot.o 


# Each subdirectory must supply rules for building sources it contributes
src/boot/%.o: ../src/boot/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: GCC Assembler'
	i386-elf-gcc -c -DASM_SOURCE -nostdinc -DIOS_KERNEL -I"D:\Programmation\IOS\workspace\IOS.Kernel\src" -O2 -g -pedantic -Wall -ffreestanding -nostdlib -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


