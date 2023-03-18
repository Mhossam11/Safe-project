/*
 * CFile1.c
 *
 * Created: 2/20/2023 9:43:10 PM
 *  Author: 20100
 */ 
#include <avr/io.h>
#include "MACRO.h"
void EEPROM_Write(unsigned short address , unsigned char data)
{
	EEARL=(char)address;
	EEARH=(char)(address>>8);
	EEDR=data;
	SET_BIT(EECR,EEMWE);
	SET_BIT(EECR,EEWE);
	while (READ_BIT(EECR,EEWE)==1);
}

unsigned char EEPROM_Read(unsigned short address)
{
	EEARL=(char)address;
	EEARH=(char)(address>>8);
	SET_BIT(EECR,EERE);
	return EEDR;
}