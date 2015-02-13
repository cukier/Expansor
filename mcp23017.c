/*
 * mcp23017.c
 *
 *  Created on: 09/02/2015
 *      Author: cuki
 */

//endereco
#define mcp_r		0x40
#define mcp_w		0x41

#define iodira		0x00
#define iodirb		0x01
#define ipola		0x02
#define ipolb		0x03
#define gpintena	0x04
#define gpintenb	0x05
#define defvala		0x06
#define defvalb		0x07
#define intcona		0x08
#define intconb		0x09
#define iocon		0x0A
#define gppua		0x0C
#define gppub		0x0D
#define intfa		0x0E
#define intfb		0x0F
#define intcapa		0x10
#define intcapb		0x11
#define gpioa		0x12
#define gpiob		0x13
#define olata		0x14
#define olatb		0x15

#define all_in		0xFF
#define all_out		0x00
