/*
 * i2c.c
 *
 *  Created on: 09/02/2015
 *      Author: cuki
 */

#define latencia	10
#define qtdDevices	5
#define qtdRegs		255

int hand_shake(int addrDevice) {

	int ack = 0;

	i2c_start();
	ack = i2c_write(addrDevice);
	i2c_stop();

	return !ack;
}

int write_i2c(int addrDevice, int addrMemory, int value) {

	int ack = 0;

	i2c_start();
	ack = i2c_write(addrDevice);
	i2c_write(addrMemory);
	i2c_write(value);
	i2c_stop();

	return !ack;
}

int read_i2c(int addrDevice, int addrMemory) {

	int leitura;

	i2c_start();
	i2c_write(addrDevice);
	i2c_write(addrMemory);
	i2c_start();
	i2c_write(addrDevice + 1);
	leitura = i2c_read(0);
	i2c_stop();

	return leitura;
}

int scan(int *devices) {

	int cont = 0;
	int ack = 0;
	int found = 0;

	for (cont = 0; cont < 254; cont += 2) {
		delay_ms(latencia);
		if (hand_shake(cont)) {
			devices[found++] = cont;
		}
	}

	return found;
}

int get_registers(int addrDevice, int *regs) {

	int cont = 0;

	for (cont = 0; cont < sizeof(regs); ++cont)
		regs[cont] = read_i2c(addrDevice, cont);

	return cont;
}

int imprime_mapa(void) {

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
