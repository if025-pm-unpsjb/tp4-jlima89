/*
 * main.c
 *
 *  Created on: 13 oct. 2022
 *      Author: fep
 */

#include "app.h"         // <= Su propia cabecera (opcional)
#include "sapi.h"        // <= Biblioteca sAPI
#define BTN_PRESIONADO OFF
#define BTN_LIBERADO ON

int main( void )
{
	// Inicializar y configurar la placa de desarrollo
	boardConfig();
	uartConfig( UART_USB, 9600 );
	bool_t boton1, boton2, boton3, boton4;
	bool_t boton1_ant, boton2_ant, boton3_ant, boton4_ant;
	bool_t led1, led2, led3, led4;

	while( TRUE ) {
		// reglas para el boton 1
		boton1 = gpioRead( TEC1 );
		led1 = !boton1;
		if( boton1 == BTN_PRESIONADO && boton1_ant == BTN_LIBERADO ) {
			gpioWrite( CIAA_BOARD_LED, led1 );
			uartWriteString(UART_USB, "BOTON 1 presionado\n");
			delay(500);
			gpioWrite( CIAA_BOARD_LED, !led1 );
		}
		boton1_ant = boton1;

		// reglas para el boton 2
		boton2 = gpioRead( TEC2 );
		led2 = !boton2;
		if( boton2 == BTN_PRESIONADO && boton2_ant == BTN_LIBERADO ) {
			gpioWrite( LED1, led2 );
			uartWriteString(UART_USB, "BOTON 2 presionado\n");
			delay(500);
			gpioWrite( LED1, !led2 );
		}
		boton2_ant = boton2;

		// reglas para el boton 3
		boton3 = gpioRead( TEC3 );
		led3 = !boton3;
		if( boton3 == BTN_PRESIONADO && boton3_ant == BTN_LIBERADO ) {
			gpioWrite( LED2, led3 );
			uartWriteString(UART_USB, "BOTON 3 presionado\n");
			delay(500);
			gpioWrite( LED2, !led3 );
		}
		boton3_ant = boton3;

		// reglas para el boton 4
		boton4 = gpioRead( TEC4 );
		led4 = !boton4;
		if( boton4 == BTN_PRESIONADO && boton4_ant == BTN_LIBERADO ) {
			gpioWrite( LED3, led4 );
			uartWriteString(UART_USB, "BOTON 4 presionado\n");
			delay(500);
			gpioWrite( LED3, !led4 );
		}
		boton4_ant = boton4;

		delay(10);
	}
}
