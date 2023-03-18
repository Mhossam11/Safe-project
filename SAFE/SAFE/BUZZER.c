/*
 * BUZZER.c
 *
 * Created: 3/17/2023 1:58:07 PM
 *  Author: 20100
 */ 

#include <avr/io.h>
#include "MACRO.h"
void Buzzer_Init(char portname,char pinumber)
{
	switch(portname)
	{
		case'A':
		case'a':
			SET_BIT(DDRA,pinumber);//Set direction of this pin as output
		break;
		
		case'B':
		case'b':
			SET_BIT(DDRB,pinumber);//Set direction of this pin as output
		break;
		
		case'C':
		case'c':
			SET_BIT(DDRC,pinumber);//Set direction of this pin as output
		break;
		
		case'D':
		case'd':
			SET_BIT(DDRD,pinumber);//Set direction of this pin as output
		break;
		default:
		break;
	}
}
void BUZZER_write(unsigned char portname,unsigned char pinnumber,unsigned char outputvalue)
{
	switch(portname)
	{
		case'A':
		case'a':
		if(outputvalue == 1)
		{
			SET_BIT(PORTA,pinnumber);//Set the value of the given pin in port A as High=1
		}
		else
		{
			CLR_BIT(PORTA,pinnumber);//Set the value of the given pin in port A as low=0
		}
		break;
		case'B':
		case'b':
		if(outputvalue == 1)
		{
			SET_BIT(PORTB,pinnumber);//Set the value of the given pin in port B as High=1
		}
		else
		{
			CLR_BIT(PORTB,pinnumber);//Set the value of the given pin in port B as low=0
		}
		break;
		case'C':
		case'c':
		if(outputvalue == 1)
		{
			SET_BIT(PORTC,pinnumber);//Set the value of the given pin in port C as High=1
		}
		else
		{
			CLR_BIT(PORTC,pinnumber);//Set the value of the given pin in port C as low=0
		}
		break;
		case'D':
		case'd':
		if(outputvalue == 1)
		{
			SET_BIT(PORTD,pinnumber);//Set the value of the given pin in port D as High=1
		}
		else
		{
			CLR_BIT(PORTD,pinnumber);//Set the value of the given pin in port D as low=0
		}
		break;
		default:
		break;
	}
}
