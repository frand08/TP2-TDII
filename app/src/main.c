

#include "main.h"
#include "board.h"


void setup_SysTick_INT(void)
{
	//Interrupcion cada SystemCoreClock/10 ticks
	SysTick_Config(SystemCoreClock/10);
}


void SysTick_Handler(void)
{
	Board_LED_Toggle(0);
}


int main (void)
{
	//Inicializacion de Board y SystemCoreClock
	SystemCoreClockUpdate();
	Board_Init();
	//Inicializacion del SysTick
	setup_SysTick_INT();

	while(1)
	{
		//Lo unico que hacemos es esperar a la interrupcion de
		//SysTick en el main
		__WFI();
	}

	return 0;
}
