/*
 * main.c
 *
 *  Created on: 13 oct. 2022
 *      Author: fep
 */

#include "app.h"         // <= Su propia cabecera (opcional)
#include "sapi.h"        // <= Biblioteca sAPI
#define MAX_SIZE 50

int main( void )
{
	// Inicializar y configurar la placa de desarrollo
	boardConfig();
	uartConfig( UART_USB, 9600 );
	uint8_t receivedByte;
	char buff[MAX_SIZE];
	int index = 0;

	uartWriteString( UART_USB, "Echo: (en Tera Term hacer: 'Configuracion' -> 'Terminal...' -> 'Transmit: CR+LF')\r\n" );
	while( TRUE ) {
		if(uartReadByte( UART_USB, &receivedByte )) {
			uartWriteByte( UART_USB, receivedByte );

			if( index < MAX_SIZE ) buff[index++] = receivedByte;

			if( receivedByte == '\n' ) {
				buff[index] = '\0';
				uartWriteString( UART_USB, buff );
				uartWriteString( UART_USB, "\n" );
				index = 0;
			}
		}
	}
}
