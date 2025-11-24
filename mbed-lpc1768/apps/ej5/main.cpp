#include "mbed.h"
#include <ctype.h>

Serial pc(USBTX, USBRX); // tx, rx
DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);

int time_ms = 1000;

// lectura por consola
void read_input() {
	char buffer_input[10] = "";
	int i = 0;
	do{
		char c = pc.getc();
		if (c == '\r') break;
		if (isdigit((unsigned char)c)) {
			pc.putc(c);
			buffer_input[i] = c;
			i++;
		}
	} while (i < 10);

	pc.printf("\n");
	time_ms = atoi(buffer_input);
}

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

	pc.printf("Ingrese un valor numerico (milisegundos) y presione ENTER:\n");
    while(1) {

    	// bucle de 0 a 15
    	for(int i = 0; i<16; i++){
    		led1 = i & mask_led1;
    		led2 = i & mask_led2;
    		led3 = i & mask_led3;
    		led4 = i & mask_led4;

    		wait_ms(time_ms);

			if (pc.readable()) {
				read_input();
			}
    	}
    }
}
