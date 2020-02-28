/*
	* MCU: STM32F051R8T6. You might be able to use this also with STM32 F0 Cortex-M0 series. 
	* This example uses CMSIS core, no HAL is used. 
	* Reads an input (Input as pull down, default state of a pin is low) and blinks an LED once the input pin is detected as high.
	* Please add stm32f051x8 header file in your CMSIS driver folder.
	* Feel free to correct any mistakes I might have done.
*/
#include "Simple_GPIO.h"

int main () {
	begin_Input ('B',14);										// set pin B14 as input
	begin_Output ('B', 12);									// set pin B12 as output
	while (1) {
		if ((read_Pin ('B',14) == 1)){ 				// if pin B14 is high, blink an LED at pin B12
			set_Pin ('B',12,1);									// set pin 12, in port B, as 1/HIGH
			for (int i = 0; i < 1000000; i++);  // waste CPU cycles to generate "delay"
			set_Pin ('B',12,0);									// set pin 12, in port B, as 0/LOW
			for (int i = 0; i < 1000000; i++);
			// another blink. You may wrap this operation in a for loop and blink as much as you would like 
			set_Pin ('B',12,1);									
			for (int i = 0; i < 1000000; i++);  
			set_Pin ('B',12,0);									
			for (int i = 0; i < 1000000; i++);
		}
	}
	return 0;
}
