/*
 * Keypad.h
 *
 * Created: 3/16/2023 11:32:56 PM
 *  Author: 20100
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#define PORTNAME  D
#define NOTPRESSED 0XFF
#include "DIO.h"
void KeyPad_vInit();
char KeyPad_u8check_press();


#endif /* KEYPAD_H_ */