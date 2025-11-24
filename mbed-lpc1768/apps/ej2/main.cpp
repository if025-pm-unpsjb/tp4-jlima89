#include "mbed.h"

PwmOut led1(LED1);
PwmOut led2(LED2);
PwmOut led3(LED3);
PwmOut led4(LED4);

void change(PwmOut &l) {
	for(float i=0.0f; i<1.0f; i+=0.1f) {
		l.write(i);
		wait_ms(150);
	}

	for(float i=1.0f; i>=0.0f; i-=0.1f) {
		l.write(i);
		wait_ms(150);
	}
	l.write(0.0f);
}

int main()
{
	int a;
    while(1) {
    	wait(1);
    	for(int led=0; led<4; led++) {
    		switch (led) {
    			case 0:
    				change(led1);
    				break;
    			case 1:
    				change(led2);
    				break;
    			case 2:
    				change(led3);
    				break;
    			case 3:
    				change(led4);
    				break;
    		}
    	}
    }
}
