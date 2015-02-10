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
	int reg[255];

	while (TRUE) {
		ack = hand_shake(mcp_r);
		if (ack) {
			ack = 0;
			for (cont = 0; cont < 255; ++cont) {
				reg[cont] = read_i2c(mcp_r, cont);
				delay_ms(10);
			}
			for (cont = 0; cont < 255; ++cont)
				printf("reg %3u = %3u\n\r", cont, reg[cont]);
		} else {
			printf("\fErro");
		}
		delay_ms(1000);
	}

	return 0;
}
