/*
 * EEPROM.h
 *
 * Created: 2/20/2023 9:43:25 PM
 *  Author: 20100
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

void EEPROM_Write(unsigned short address , unsigned char data);
unsigned char EEPROM_Read(unsigned short address);


#endif /* EEPROM_H_ */