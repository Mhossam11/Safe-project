/*
 * DIO.c
 *
 * Created: 12/24/2022 3:34:49 PM
 *  Author: 20100
 */ 
#include <avr/io.h>
#include "MACRO.h"
void DIO_vsetPINDir(unsigned char portname,unsigned char pinumber,unsigned char direction)
{
	switch(portname)
	{
		case'A':
		case'a':
		if(direction==1)
		{
			SET_BIT(DDRA,pinumber);//Set direction of this pin as output
		}
		else
		{
			CLR_BIT(DDRA,pinumber);//Set direction of this pin as input
		}
		break;
		
		case'B':
		case'b':
		if(direction==1)
		{
			SET_BIT(DDRB,pinumber);//Set direction of this pin as output
		}
		else
		{
			CLR_BIT(DDRB,pinumber);//Set direction of this pin as input
		}
		break;
		
		case'C':
		case'c':
		if(direction==1)
		{
			SET_BIT(DDRC,pinumber);//Set direction of this pin as output
		}
		else
		{
			CLR_BIT(DDRC,pinumber);//Set direction of this pin as input
		}
		break;
		
		case'D':
		case'd':
		if(direction==1)
		{
			SET_BIT(DDRD,pinumber);//Set direction of this pin as output
		}
		else
		{
			CLR_BIT(DDRD,pinumber);//Set direction of this pin as input
		}
		break;
		default:
		break;
	}
	
}


void DIO_write(unsigned char portname,unsigned char pinnumber,unsigned char outputvalue)
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


unsigned char DIO_u8read(unsigned char portname,unsigned char pinnumber)     //u8 3shan hya 8 bit
{
	unsigned char return_value=0;
	switch(portname)
	{
		case'A':
		case'a':
		return_value=READ_BIT(PINA,pinnumber);  //read value from given pin in PORTA
		break;
		case'B':
		case'b':
		return_value=READ_BIT(PINB,pinnumber);  //read value from given pin in PORTB
		break;
		case'C':
		case'c':
		return_value=READ_BIT(PINC,pinnumber);  //read value from given pin in PORTC
		break;
		case'D':
		case'd':
		return_value=READ_BIT(PIND,pinnumber);  //read value from given pin in PORTD
		break;
		default:
		break;
	}
	return return_value;
}


void DIO_toggle(unsigned char portname,unsigned char pinnumber)
{
	switch(portname)
	{
		case'A':
		case'a':
		TOG_BIT(PORTA,pinnumber);
		break;
		case'B':
		case'b':
		TOG_BIT(PORTB,pinnumber);
		break;
		case'C':
		case'c':
		TOG_BIT(PORTC,pinnumber);
		break;
		case'D':
		case'd':
		TOG_BIT(PORTD,pinnumber);
		break;
		default:
		break;
	}
}


void DIO_set_port_direction(unsigned char portname,unsigned char direction)
{
	switch(portname)
	{
		case'A':
		case'a':
		DDRA=direction;      //set direction of all PORTA
		break;
		case'B':
		case'b':
		DDRB=direction;      //set direction of all PORTB
		break;
		case'C':
		case'c':
		DDRC=direction;      //set direction of all PORTC
		break;
		case'D':
		case'd':
		DDRD=direction;      //set direction of all PORTD
		break;	
		default:
		break;
	}
}

void DIO_write_port(unsigned char portname,unsigned char portvalue)
{
	switch(portname)
	{
		case'A':
		case'a':
		PORTA=portvalue;   //Write the given value to the portA 
		break;
		case'B':
		case'b':
		PORTB=portvalue;   //Write the given value to the portB
		break;
		case'C':
		case'c':
		PORTC=portvalue;   //Write the given value to the portC
		break;
		case'D':
		case'd':
		PORTD=portvalue;   //Write the given value to the portD
		break;
		default:
		break;
	}
}

unsigned char DIO_read_port(unsigned char portname)
{
	unsigned char return_value=0;
	switch(portname)
	{
		case'A':
		case'a':
		return_value=PINA;    // read the value of portA
		break;
		case'B':
		case'b':
		return_value=PINB;    // read the value of portB
		break;
		case'C':
		case'c':
		return_value=PINC;    // read the value of portC
		break;
		case'D':
		case'd':
		return_value=PIND;    // read the value of portD
		break;
		default:
		break;
		
	}
	return return_value;
}

 void write_low_nibble(unsigned char portname,unsigned char value)
  {
	  value&=0x0f;
	 switch(portname)
	  {
		  case 'A':
		  PORTA&=0xf0;
		  PORTA|=value;
		  break;
		  case 'B':
		  PORTB&=0xf0;
		  PORTB|=value;
		  break;
		  case 'C':
		  PORTC&=0xf0;
		  PORTC|=value;
		  break;
		  case 'D':
		  PORTD&=0xf0;
		  PORTD|=value;
		  break;
	  }
  }
  
   void write_high_nibble(unsigned char portname,unsigned char value)
    {
	    value<<=4;
	    switch(portname)
	    {
		    case 'A':
		    PORTA&=0x0f;
		    PORTA|=value;
		    break;
		    case 'B':
		    PORTB&=0x0f;
		    PORTB|=value;
		    break;
		    case 'C':
		    PORTC&=0x0f;
		    PORTC|=value;
		    break;
		    case 'D':
		    PORTD&=0x0f;
		    PORTD|=value;
		   break;
	    }
    }
	
	void DIO_vconnectpullup(char portname ,char pinnumber, char connect_pullup)
	{
		switch(portname)
		{
			case 'A':
			if(connect_pullup==1)
			{
				SET_BIT(PORTA,pinnumber);
			}
			else
			{
				CLR_BIT(PORTA,pinnumber);
			}
			break;
			case 'B':
			if(connect_pullup==1)
			{
				SET_BIT(PORTB,pinnumber);
			}
			else
			{
				CLR_BIT(PORTB,pinnumber);
			}
			break;
			case 'C':
			if(connect_pullup==1)
			{
				SET_BIT(PORTC,pinnumber);
				
			}
			else
			{
				CLR_BIT(PORTC,pinnumber);
			}
			break;
			case 'D':
			if(connect_pullup==1)
			{
				SET_BIT(PORTD,pinnumber);
				
			}
			else
			{
				CLR_BIT(PORTD,pinnumber);
			}
			break;
			
		}
	}