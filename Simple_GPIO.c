/*
* Using CMSIS (HAL is not used), these functions accomplish the foolowing:  
	* Sets output pins as push pull, medium speed and no pull up/ down 
	* Sets Input pins as pull down, this means the the default state of a pin is low 
	* Reads pin state and returns an integer. 1 for high level and 0 for low level 
	* Sets pin state as high/ low 
*/
#include "Simple_GPIO.h"
#include <stm32f051x8.h>

void begin_Output (char port, int pin_number) {
	if (port == 'A') {
		RCC->AHBENR    |= (1<<17);										/*Enable AHB bus for port A*/
		GPIOA->MODER   &= ~(0x03 << (2*pin_number));	
		GPIOA->MODER 	 |= (0x01 << (2*pin_number));  	/*Set pin as output*/
		GPIOA->OTYPER  |= (0x00 << (pin_number));			/*Set output type as push pull, set 0x01 for open drain*/
		GPIOA->OSPEEDR |= (0x01 << (2*pin_number));   /*Set output speed as medium*/
		GPIOA->PUPDR   |= (0x00 << (2*pin_number));		/*Set the pin as no pull up/ down. Set 0x01 for pull up, 0x02 for pull down*/	
	} else if (port == 'B') {
		RCC->AHBENR    |= (1<<18);										/*Enable AHB bus for port B*/
		GPIOB->MODER   &= ~(0x03 << (2*pin_number));	/*Similar to steps for port A*/
		GPIOB->MODER 	 |= (0x01 << (2*pin_number));  	
		GPIOB->OTYPER  |= (0x00 << (pin_number));			
		GPIOB->OSPEEDR |= (0x01 << (2*pin_number));   
		GPIOB->PUPDR   |= (0x00 << (2*pin_number));		
	} else if (port == 'C') {
		RCC->AHBENR    |= (1<<19);										/*Enable AHB bus for port C*/
		GPIOC->MODER   &= ~(0x03 << (2*pin_number));	/*Similar to steps for port A*/
		GPIOC->MODER 	 |= (0x01 << (2*pin_number));   
		GPIOC->OTYPER  |= (0x00 << (pin_number));			
		GPIOC->OSPEEDR |= (0x01 << (2*pin_number));   
		GPIOC->PUPDR   |= (0x00 << (2*pin_number));			
	}
}


void begin_Input (char port, int pin_number) {
	if (port == 'A') {
		RCC->AHBENR    |= (1<<17);										/*Enable AHB bus for port A*/
		GPIOA->MODER   &= ~(0x03 << (2*pin_number));	
		GPIOA->MODER 	 |= (0x00 << (2*pin_number));   /*Set mode as input*/
		GPIOA->PUPDR   |= (2 << (2*pin_number));	    /*Set pin as pull down, use 1 for pull up, 0 for no pull up/ down */
	} else if (port == 'B') {			
		RCC->AHBENR    |= (1<<18);										/*Enable AHB bus for port B*/
		GPIOB->MODER   &= ~(0x03 << (2*pin_number));	/*Similar steps to port A*/
		GPIOB->MODER 	 |= (0x00 << (2*pin_number));  	
		GPIOB->PUPDR   |= (2 << (2*pin_number));			
	} else if (port == 'C') {
		RCC->AHBENR    |= (1<<19);										/*Enable AHB bus for port C*/
		GPIOC->MODER   &= ~(0x03 << (2*pin_number));	/*Similar steps to port A*/
		GPIOC->MODER 	 |= (0x00 << (2*pin_number));   
		GPIOC->PUPDR   |= (2 << (2*pin_number));	    
	}
}

void set_Pin (char port, int pin , int state) {
	if (port == 'A') {
		if (state == 0) {
			GPIOA->ODR &= (0 << pin);										/*Set pin as 0/ LOW in port A*/
		} else if (state == 1) {
			GPIOA->ODR |=  (1 << pin); 									/*Set pin as 1/ HIGH in port A*/
		}
	} else if (port == 'B') {
		if (state == 0) {
			GPIOB->ODR &= (0 << pin);										/*Set pin as 0/ LOW in port B*/
		} else if (state == 1){
			GPIOB->ODR |=  (1 << pin);									/*Set pin as 1/ HIGH in port B*/
		}
	} else if (port == 'C') {
		if (state == 0) {
			GPIOC->ODR &= (0 << pin);										/*Set pin as 0/ LOW in port C*/
		} else if (state == 1){
			GPIOC->ODR |=  (1 << pin);									/*Set pin as 1/ HIGH in port C*/
		}
	}
}

int read_Pin (char port, int pin_number){
	uint8_t compare = 0x01;
	uint8_t result = 0;
	if (port == 'A') {
		result = (((GPIOA->IDR) >> pin_number) & (compare)); /*Reads the data register and checks the pin state*/
		if (result == 1) {
			return 1;																						// returns 1 if the pin input is high
		} else {
			return 0;																						// returns 0 if the pin input is low 
		}
	} else if (port == 'B') {
		result = (((GPIOB->IDR) >> pin_number) & (compare)); /*Similar operation to port A*/
		if (result == 1) {
			return 1;
		} else {
			return 0;
		}
	} else if (port == 'C') {
		result = (((GPIOC->IDR) >> pin_number) & (compare)); /*Similar operation to port A & B*/
		if (result == 1) {
			return 1;
		} else {
			return 0;
		}
	}
	return 0;	
}
