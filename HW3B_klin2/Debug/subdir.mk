################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HW3B.c \
../mystruct.c \
../production.c \
../tests.c 

O_SRCS += \
../HW3B.o \
../mystruct.o \
../production.o \
../tests.o 

OBJS += \
./HW3B.o \
./mystruct.o \
./production.o \
./tests.o 

C_DEPS += \
./HW3B.d \
./mystruct.d \
./production.d \
./tests.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


