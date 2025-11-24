#include "mbed.h"

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);

int main()
{
	// mascaras
	int mask_led1 = 1; // 0001
	int mask_led2 = 2; // 0010
	int mask_led3 = 4; // 0100
	int mask_led4 = 8; // 1000

	// configuracion inicial
	led1 = 0;
	led2 = 0;
	led3 = 0;
	led4 = 0;

	wait(1);

    while(1)
        {
    	// bucle de 0 a 15
    	for(int i = 0; i<16; i++){
    		led1 = i & mask_led1;
    		led2 = i & mask_led2;
    		led3 = i & mask_led3;
    		led4 = i & mask_led4;

    		wait(1);
    	}
    }
}
