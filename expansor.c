/*
 * expansor.c
 *
 *  Created on: 09/02/2015
 *      Author: cuki
 */

#include <18F252.h>

#fuses HS
#use delay(clock=15MHz)
#use rs232(baud=9600,xmit=pin_c6,rcv=pin_c7)
#use i2c (master,scl=pin_c3,sda=pin_c4,force_hw,fast=1000)

#include "i2c.c"
#include "mcp23017.c"

int main(void) {

	int cont = 0;
	int ack = 0;
	int achados;
	int reg[127];

	for (cont = 0; cont < 254; cont += 2) {
		delay_ms(10);
		if (hand_shake(cont)) {
			printf("achado 0x%x\n\r", cont);
		}
	}

	printf("Vasculhados %u\n\r", cont / 2);

	return 0;
}
