/*
 * i2c.c
 *
 *  Created on: 09/02/2015
 *      Author: cuki
 */

#define latencia 10

int hand_shake(int addrDevice) {

	int ack = 0;

	i2c_start();
	ack = i2c_write(addrDevice);
	i2c_stop();

	return !ack;
}

int send_i2c(int addrDevice, int addrMemory) {

	int ack = 0;

	i2c_start();
	ack = i2c_write(addrDevice);
	i2c_write(addrMemory);
	i2c_stop();

	return !ack;
}

int read_i2c(int addrDevice, int addrMemory) {

	int recived = 0;

	i2c_start();
	i2c_write(addrDevice);
	recived = i2c_read(0);
	i2c_stop();

	return recived;
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

	for (cont = 0; cont < sizeof(regs); ++cont) {
		delay_ms(latencia);
		regs[cont] = read_i2c(addrDevice, cont);
	}

	return cont;
}
