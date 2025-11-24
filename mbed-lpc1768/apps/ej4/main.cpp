#include "mbed.h"

Serial pc(USBTX, USBRX); // tx, rx
DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);

int main() {
    pc.baud(9600);
    // Baud Rate 9600
    // Data Bits 8
    // Parity None
    // Stop Bits 1

    char ledToBlink = '1';
    led1 = 1;
    pc.printf("Seleccione el LED poniendo un número entero (1, 2, 3 o 4)\nPor defecto usa 1\n");
    while(1) {
    	if(pc.readable()) {
    		ledToBlink = pc.getc();
    	}
		//pc.printf(typeid(ledToBlink).name());
		switch (ledToBlink) {
			case '1':
				led1 = 1;
				led2 = 0;
				led3 = 0;
				led4 = 0;
				break;
			case '2':
				led1 = 0;
				led2 = 1;
				led3 = 0;
				led4 = 0;
				break;
			case '3':
				led1 = 0;
				led2 = 0;
				led3 = 3;
				led4 = 0;
				break;
			case '4':
				led1 = 0;
				led2 = 0;
				led3 = 0;
				led4 = 1;
				break;
			default:
				pc.printf("Valor ingresado incorrecto\n");
				break;
		}
		wait_ms(250);
		led1 = 0;
		led2 = 0;
		led3 = 0;
		led4 = 0;
		wait_ms(250);
    }
}
