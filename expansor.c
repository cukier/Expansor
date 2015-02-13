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

#define qtdDevices	5
#define qtdRegs		255

int main(void) {

	int devices[qtdDevices];
	int regs[qtdDevices][qtdRegs];
	int qtd = 0;
	int cont;
	int cont2;

	qtd = scan(&devices);

	if (qtd > qtdDevices) {
		printf("\n\rMuitos dispoisitivos %d\n\r", qtd);
		return 1;
	}

	printf("\n\rEncontrados %u\n\rDisp\t", qtd);

	for (cont = 0; cont < qtd; ++cont) {
		get_registers(devices[cont], regs[cont]);
		printf("  0x%x", devices[cont]);
	}

	printf("\n\r");

	for (cont = 0; cont < qtdRegs; ++cont) {
		printf("reg 0x%x  ", cont);
		for (cont2 = 0; cont2 < qtd; ++cont2)
			printf("0x%x  ", regs[cont][cont2]);
		printf("\n\r");
	}

	return 0;

}
