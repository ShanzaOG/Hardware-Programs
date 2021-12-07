#include "stm32f10x.h"
#include "HAL_GPIO.h"


int main()
{
	/*
	//initialize the clock for the Port C(GPIO C)
	RCC->APB2ENR |= (1<<4);
	
	//Configuring pins  on GPIOC
	GPIOC->CRH |= ((1<<20)|(1<<21));//output at 50 MHZ
	
	//GPIOC->CRH = GPIOC->CRH & ~( (1<<22) | (1<<23));
	
	GPIOC->CRH &= ~((1<<22)|(1<<23));//output at 50 MHZ
	*/
	GPIO_TYPE myGPIO;
	
	myGPIO.port = PORTC;
	myGPIO.pin = 13;
	myGPIO.mode = OUTPUT_MODE;
	myGPIO.mode_type = OUTPUT_GPOPP;
	myGPIO.speed = SPEED_50MHZ;
	
	gpio_init(myGPIO);
	
	
	
	while(1)
	{
		
		/*GPIOC->BSRR = (1<<13);//Set pin 13 high
		for(volatile int i = 0; i < 50000; i++)
		;//delay
	  GPIOC->BSRR = 1<<(13 + 16); //reset the pin. This is by your set pin plus 16
		for(volatile int i = 0; i < 50000; i++);*/
		gpio_toggle(PORTC,13);
		for(volatile int i = 0; i < 5000000; i++);
	}

}
/*
int main()
{

	RCC->APB2ENR |= (1<<4);
	GPIOC->CRH &= ~((1<<23)| (1<<22) | (1<<20));
	GPIOC->CRH |= (1<<21);
	
	while(1){
	
		GPIOC->ODR ^= (1<<13);
	
	}

}*/



