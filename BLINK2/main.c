//BUS AHB2-peripheral clock enable register RCC->AHB2ENR
//Pin PA5-Direction Register-GPIOx->MODER
//Data Register GPIOx->IDR/ODR
//

#include "stm32l4xx.h"                  // Device header

void delayMS(int delay);

int main(void)
{
	RCC->AHB2ENR |=1;											//ENABLE GPIOA clock
	
	GPIOA->MODER &=~0xC00;           			//Reset the PIN5 0b 0000 0000 0000 0000 0000 1100 0000 0000
	GPIOA->MODER |=0x400;									//OUTPUT MODE-PA5
	
	while(1)
	{																			//PIN No----					 7854	3210
		GPIOA->ODR = 0x20;									//SET PA5 0b 0000 0000 0010 0000
		delayMS(100);
		GPIOA->ODR &=~ 0X20;								//RESET PA5
		delayMS(100);
	}
}

void delayMS(int delay)
{
	int i;
	for(; delay>0; delay--)
	{
		for(i=0;i<3195;i++);
	}
}
