/**
 * \mainpage
 * \section intro_sec Introduccion
 *
 * TP2 de Tecnicas Digitales 2
 *
 * \section Descripcion
 *
 * Programa sencillo que hace destellar el LED del stick LPCXpresso\n
 * usando delay por hardware (SysTick + IRQ).
 *
 * Todo el desarrollo del mismo se realizo en el main.c
 */


/**
 * \file
 * \brief Funcion principal
 *
 */
#include "main.h"
#include "board.h"

/**
 * \brief Funcion de configuracion de la interrupcion por SysTick
 *
 *	Se utiliza a SysTick_Config para setear cada cuantos Ticks se
 *	generara la interrupion
 */
void Setup_SysTick(void)
{
	//Interrupcion cada SystemCoreClock/10 ticks
	SysTick_Config(SystemCoreClock/CLOCK_DIVIDER);
}

/**
 * \brief ISR de la interrupcion por SysTick
 *
 *	Solo se hace un Toggle del Board_LED(0)
 */
void SysTick_Handler(s)
{
	Board_LED_Toggle(0);
}

/**
 * \brief Funcion main principal
 *
 *	Se realizan las inicializaciones de SystemCoreClock, Board y del SysTick.\n
 *	Luego entra en loop que es solo interrumpido por la interrupcion de timer.
 */
int main (void)
{
	//Inicializacion de Board y SystemCoreClock
	SystemCoreClockUpdate();
	Board_Init();
	//Inicializacion del SysTick
	Setup_SysTick();

	while(1)
	{
		//Lo unico que hacemos es esperar a la interrupcion de
		//SysTick en el main
		__WFI();
	}

	return 0;
}
