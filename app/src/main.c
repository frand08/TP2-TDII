

#include "main.h"
#include "board.h"


int main (void)
{
	int i=0;
	Board_Init();
	while(1)
	{
		for (i=0; i<1000000; i++);

		Board_LED_Toggle(0);

	}

	return 0;
}
