/*
 * i2c.c
 *
 *  Created on: 09/02/2015
 *      Author: cuki
 */

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

	return ack;
}

int read_i2c(int addrDevice, int addrMemory) {

	register int recived = 0;

	i2c_start();
	i2c_write(addrDevice);
	recived = i2c_read(0);
	i2c_stop();

	return recived;
}
