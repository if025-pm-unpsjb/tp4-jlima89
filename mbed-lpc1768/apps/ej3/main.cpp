#include "mbed.h"

Serial pc(USBTX, USBRX); // tx, rx

int main() {
    pc.printf("Escriba cualquier cosa\n");
    //pc.baud(9600);
    // Baud Rate 9600
    // Data Bits 8
    // Parity None
    // Stop Bits 1
    while(1) {
    	if(pc.readable()) {
    		pc.putc(pc.getc());
    	}
    }
}
