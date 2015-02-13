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
#use i2c (master,scl=pin_c3,sda=pin_c4,force_hw,fast=100000)

#include "i2c.c"
#include "mcp23017.c"

int main(void) {

	int i = 0;

	int iodir = read_i2c(mcp_r, iodira);
	printf("0x%x\n\r", read_i2c(mcp_r, iodira));

	if (iodir == 0xFF)
		write_i2c(mcp_r, iodira, all_out);
	printf("0x%x\n\r", read_i2c(mcp_r, iodira));

	while (true) {
		for (i = 1; i != 8; i <<= 1) {
			write_i2c(mcp_r, gpioa, i);
			printf("0x%x\n\r", read_i2c(mcp_r, gpioa));
			delay_ms(1000);
		}

	}

	return 0;

}
