#include "HAL_GPIO.h"
#include <stdint.h>



/*--Every pin in the high and low control registers has 4 associated bits thus the position 
    of each pin is shifted by 4 bits.*/
static int PINPOS[16] = {  //Takes me to the first bit of the pin
	(0x00),//PIN0 starts at 0.....This is the first bit in MODE0[1:0]
	(0x04),//PIN1 starts at 4
	(0x08),//PIN2
	(0x0C),//PIN3
	(0x10),//PIN4
	(0x14),//PIN5
	(0x18),//PIN6
	(0x1C),//PIN7
	(0x00),//PIN8
	(0x04),//PIN9
	(0x08),//PIN10
	(0x0C),//PIN11
	(0x10),//PIN12
	(0x14),//PIN13
	(0x18),//PIN14
	(0x1C),//PIN15
	
};



//***************************************************************************************
static void config_pin (GPIO_TypeDef *port, uint32_t pinNumber, uint32_t mode_type)
{
	if(pinNumber >= 8)//if the pin number is greater than 8 go to CONTROL HIGH reg.
	{
		switch(mode_type)
		{
			//------------------OUTPUTMODES--------------------------
			case OUTPUT_GPOPP | INPUT_Analog:
				port->CRH &= ~(1<<CNF_POS_BIT1) | (1<<CNF_POS_BIT2);
			break;
			
			case OUTPUT_GPOOD | INPUT_Floating:
				port->CRH &= ~(1<<CNF_POS_BIT2);
				port->CRH |= (1<<CNF_POS_BIT1);
			break;
			
			case OUTPUT_ALT_PP | INPUT_PU_PD:
				port->CRH |= OUTPUT_ALT_PP<<(CNF_POS_BIT1);
			break;
			
			case OUTPUT_ALT_OD:
				port->CRH |= OUTPUT_ALT_OD<<(CNF_POS_BIT1);
			break;
			
		
		}//end switch
	
	}//end if
	else//else go to CONTROL LOW reg.   
	{
		switch(mode_type)
		{
			//------------------OUTPUTMODES--------------------------
			case OUTPUT_GPOPP | INPUT_Analog:
				port->CRL &= ~(1<<CNF_POS_BIT1) | (1<<CNF_POS_BIT2);
			break;
			
			case OUTPUT_GPOOD | INPUT_Floating:
				port->CRL &= ~(1<<CNF_POS_BIT2);
				port->CRL |= (1<<CNF_POS_BIT1);
			break;
			
			case OUTPUT_ALT_PP | INPUT_PU_PD:
				port->CRL |= OUTPUT_ALT_PP<<(CNF_POS_BIT1);
			break;
			
			case OUTPUT_ALT_OD:
				port->CRL |= OUTPUT_ALT_OD<<(CNF_POS_BIT1);
			break;
			
		
		}//end switch
	
	
	}//end else

}//end config pin
//***********************************************************************
static void config_pin_speed (GPIO_TypeDef *port, uint32_t pinNumber, uint32_t mode, uint32_t pinSpeed)
{
	if(pinNumber >= 8)//we first check the pinnumber then the mode
	{
		if(mode == INPUT_MODE) //Set control HIGH reg. to input mode
			port->CRH &=~(1<<(PINPOS[pinNumber]) | 1<<(PINPOS[pinNumber] + 1));
		else
			port->CRH |= (pinSpeed<<(PINPOS[pinNumber]));//set control HIGH to output mode at given speed
	}//end if
	else
	{
		if(mode == INPUT_MODE) //Set control HIGH reg. to input mode
			port->CRL &=~(1<<(PINPOS[pinNumber]) | 1<<(PINPOS[pinNumber] + 1));
		else
			port->CRL |= (pinSpeed<<(pinNumber));
	
	}

}
 //**********************************************************************

void gpio_write(GPIO_TypeDef *port, uint32_t pinNumber, uint8_t state)
{
	if(state)
	{
		port->BSRR = (1<<pinNumber);
	}//end if
	else
	{
		port->BSRR=(1<<(pinNumber + 16));
	}//end else

}//end of gpio write functions

void gpio_toggle(GPIO_TypeDef *port, uint32_t pinNumber)
{
	port->ODR ^= (1<<pinNumber);//ODR -----output dara register 
}

void gpio_init(GPIO_TYPE gpio_type)//we are passing it a structure that we had created earlier in .h file 
{
	if(gpio_type.port == PORTA)//if the GPIO port is PORTA the clock enable the port
		GPIO_CLOCK_ENABLE_PORTA;
	if(gpio_type.port == PORTB)//if the GPIO port is PORTB the clock enable the port
		GPIO_CLOCK_ENABLE_PORTB;
	if(gpio_type.port == PORTC)//if the GPIO port is PORTC the clock enable the port
		GPIO_CLOCK_ENABLE_PORTC;
	if(gpio_type.port == PORTD)//if the GPIO port is PORTD the clock enable the port
		GPIO_CLOCK_ENABLE_PORTD; 
//Once the clocks are enabled, we the call then config pin function and config pin_speed function
	config_pin (gpio_type.port, gpio_type.pin, gpio_type.mode_type);
	config_pin_speed (gpio_type.port, gpio_type.pin, gpio_type.speed, gpio_type.speed);
}




















