#ifndef HAL_GPIO
#define HAL_GPIO

#include "stm32f10x.h"

//PORTS
#define PORTA    GPIOA
#define PORTB    GPIOB
#define PORTC    GPIOC
#define PORTD    GPIOD
#define PORTE    GPIOE
#define PORTF    GPIOF
#define PORTG    GPIOG


//PIN MODE
#define INPUT_MODE  ((uint32_t) 0x01)//OUTPUT Mode
#define OUTPUT_MODE ((uint32_t) 0x02)//INPUT Mode

/*CNFy[1:0]: Port x configuration bits (y=8....15)......CNF stands for config.
  These bits are written to cnfigure the corresponding I/O port*/
//INPUT MODE TYPES
#define INPUT_Analog    ((uint32_t) 0x00)//Analoge Mode
#define INPUT_Floating  ((uint32_t) 0x01)//Floating input(reset state)
#define INPUT_PU_PD     ((uint32_t) 0x02)//Input with pull-up/pull-down

//OUTPUT MODE TYPES
#define OUTPUT_GPOPP    ((uint32_t) 0x00)//General purpose output push-pull
#define OUTPUT_GPOOD    ((uint32_t) 0x01)//General purpose output Open-drain
#define OUTPUT_ALT_PP   ((uint32_t) 0x02)//Alternate function output push-pull
#define OUTPUT_ALT_OD   ((uint32_t) 0x03)//Alternate function output open-drain

/*MODEy[1:0]*/
//PIN Speeds
#define SPEED_2MHZ  ((uint32_t) 0x02)//Output mode max speed 2 MHZ
#define SPEED_10MHZ ((uint32_t) 0x01)//Output mode max speed 10 MHZ
#define SPEED_50MHZ ((uint32_t) 0x03)//Output mode max speed 50 MHZ


//CLOCK ENABLING
#define GPIO_CLOCK_ENABLE_ALT_FUNCTION   (RCC->APB2ENR |= (1<<0))
#define GPIO_CLOCK_ENABLE_PORTA       	 (RCC->APB2ENR |= (1<<2))
#define GPIO_CLOCK_ENABLE_PORTB   			 (RCC->APB2ENR |= (1<<3))
#define GPIO_CLOCK_ENABLE_PORTC          (RCC->APB2ENR |= (1<<4))
#define GPIO_CLOCK_ENABLE_PORTD          (RCC->APB2ENR |= (1<<5))
#define GPIO_CLOCK_ENABLE_PORTE          (RCC->APB2ENR |= (1<<6))

//HIGH IT POSITIONS FOR CRH reg. CNFy and MODEy
#define CNF_POS_BIT1   (PINPOS[pinNumber] + 2)
#define CNF_POS_BIT2   (PINPOS[pinNumber] + 3)

//Configuration Structure
typedef struct
{
	GPIO_TypeDef *port;
	
	uint32_t  pin;
	
	uint32_t  mode;
	
	uint32_t  mode_type;
	
	uint32_t  pull;
	
	uint32_t  speed;
	
	uint32_t  alt_func;

}GPIO_TYPE; 


//Functions
//*******************************************
//         GPIO CONFIGURATION

static void config_pin (GPIO_TypeDef *port, uint32_t pinNumber, uint32_t mode_type);
static void config_pin_speed (GPIO_TypeDef *port, uint32_t pinNumber, uint32_t mode, uint32_t pinSpeed);

 






















 
#endif