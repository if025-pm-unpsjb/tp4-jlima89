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
	bool_t ledON_OFF = OFF, ledR = OFF, ledG = OFF, ledB = OFF;

	while( TRUE ) {
		// reglas para el boton 1 (On-Off Led)
		boton1 = gpioRead( TEC1 );
		if( boton1 == BTN_PRESIONADO && boton1_ant == BTN_LIBERADO ) {
			ledON_OFF = !ledON_OFF;
			if( ledON_OFF == ON ) {
				uartWriteString(UART_USB, "Boton 1 - LED RGB ON\n");
				ledR = ON;
				ledG = ON;
				ledB = ON;
				gpioWrite( LEDR, ledR );
				gpioWrite( LEDG, ledG );
				gpioWrite( LEDB, ledB );
			} else {
				uartWriteString(UART_USB, "Boton 1 - LED RGB OFF\n");
				gpioWrite( LEDR, OFF );
				gpioWrite( LEDG, OFF );
				gpioWrite( LEDB, OFF );
			}
			//delay(500);
		}
		boton1_ant = boton1;

		// reglas para el boton 2 (R)
		boton2 = gpioRead( TEC2 );
		if( boton2 == BTN_PRESIONADO && boton2_ant == BTN_LIBERADO ) {
			ledR = !ledR;
			uartWriteString(UART_USB, "BOTON 2 - R\n");
			gpioWrite( LEDR, ledR && ledON_OFF );
			//delay(500);
		}
		boton2_ant = boton2;

		// reglas para el boton 3 (G)
		boton3 = gpioRead( TEC3 );
		if( boton3 == BTN_PRESIONADO && boton3_ant == BTN_LIBERADO ) {
			ledG = !ledG;
			uartWriteString(UART_USB, "BOTON 3 - G\n");
			gpioWrite( LEDG, ledG && ledON_OFF );
			//delay(500);
		}
		boton3_ant = boton3;

		// reglas para el boton 4 (B)
		boton4 = gpioRead( TEC4 );
		if( boton4 == BTN_PRESIONADO && boton4_ant == BTN_LIBERADO ) {
			ledB = !ledB;
			uartWriteString(UART_USB, "BOTON 4 - B\n");
			gpioWrite( LEDB, ledB && ledON_OFF );
			//delay(500);
		}
		boton4_ant = boton4;

		delay(50);
	}
}
