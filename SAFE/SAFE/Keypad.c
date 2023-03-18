/*
 * Keypad.c
 *
 * Created: 3/16/2023 11:32:47 PM
 *  Author: 20100
 */ 
#include "Keypad.h"

void KeyPad_vInit()
{
	DIO_vsetPINDir('D',0,1);
	DIO_vsetPINDir('D',1,1);
	DIO_vsetPINDir('D',2,1);
	DIO_vsetPINDir('D',3,1);
	
	DIO_vsetPINDir('D',4,0);
	DIO_vsetPINDir('D',5,0);
	DIO_vsetPINDir('D',6,0);
	DIO_vsetPINDir('D',7,0);
	/* DIO_vconnectpullup('D',4,1);   //FOR INTERNAL PULLUP
	 DIO_vconnectpullup('D',5,1);
	 DIO_vconnectpullup('D',6,1);
	 DIO_vconnectpullup('D',7,1);*/
}

char KeyPad_u8check_press()
{
	char arr [4][4] = {{'1','2','3','/'},{'4','5','6','*'},{'7','8','9','-'},{'A','0','=','+'}};
	char row , col , x;
	char return_value=NOTPRESSED;
	for(row=0;row<4;row++)
	{
		DIO_write('D',0,1);
		DIO_write('D',1,1);
		DIO_write('D',2,1);
		DIO_write('D',3,1);
		DIO_write('D',row,0);     //3SHAN YE3ML DETECT M3 EL PULL UP LAW FE ZORAR EDAS 
		for(col=0;col<4;col++)
		{
			x=DIO_u8read('D',(col+4)); //3shan ana msh b2ra mn el pin 0 asasn
			if(x==0)
			{
				return_value=arr[row][col];
				break;
			}
		}
		if(x==0)
		{
			break;
		}
	}
	return return_value;   //according to MISRAC lazm el return ykon fe a5r el function
	
}