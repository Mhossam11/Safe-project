/*
 * LCD.c
 *
 * Created: 3/5/2023 11:41:29 PM
 *  Author: 20100
 */ 
#include "LCD.h"
#define F_CPU 8000000UL
#include <util/delay.h>


void LCD_vInt(void)
{
	_delay_ms(200);									//da lazm zae ma 2al fel data sheet
	
	#if defined eight_bits_mode
	DIO_vsetPINDir(PORTNAME,0,1);
	DIO_vsetPINDir(PORTNAME,1,1);
	DIO_vsetPINDir(PORTNAME,2,1);
	DIO_vsetPINDir(PORTNAME,3,1);
	DIO_vsetPINDir(PORTNAME,4,1);
	DIO_vsetPINDir(PORTNAME,5,1);
	DIO_vsetPINDir(PORTNAME,6,1);
	DIO_vsetPINDir(PORTNAME,7,1);
	DIO_vsetPINDir('B',EN,1);
	DIO_vsetPINDir('B',RS,1);
	DIO_vsetPINDir('B',RW,1);
	DIO_write('B',RW,0);							//3shan a3ml write fa wslha GRND
	LCD_vSend_cmd(EIGHT_BITS);						 //b3rfo enha 8 bit 0x38
	_delay_ms(1);									 //lazm delay b3d kol command 3shan ynfzo
	LCD_vSend_cmd(DISPLAY_ON_CURSOR_ON);				//byzhr el cursor
	_delay_ms(1);
	LCD_vSend_cmd(CLR_SCREEN);						//bms7 el 3la el LCD felwawl awl m3ml int
	_delay_ms(10);
	LCD_vSend_cmd(ENTRY_MODE);						//byw2f el cursor flawl 
	_delay_ms(1);
	
	#elif defined four_bits_mode
	DIO_vsetPINDir('A',4,1);					// b3ml write 3la el high nibble fa bbd2 mn 4
	DIO_vsetPINDir('A',5,1);	
	DIO_vsetPINDir('A',6,1);	
	DIO_vsetPINDir('A',7,1);	
	DIO_vsetPINDir('B',EN,1);
	DIO_vsetPINDir('B',RS,1);
	DIO_vsetPINDir('B',RW,1);
	DIO_write('B',RW,0);                           //3shan a3ml write 3leha bs momkn awslha GRND w5las
	LCD_vSend_cmd(RETURN_HOME);                    //0x02  da w el t7te 3shan ash8l four bit mode
	_delay_ms(10);
	LCD_vSend_cmd(FOUR_BITS);						//0x28
	_delay_ms(1);
	LCD_vSend_cmd(DISPLAY_ON_CURSOR_ON);
	_delay_ms(1);
	LCD_vSend_cmd(CLR_SCREEN);
	_delay_ms(10);
	LCD_vSend_cmd(ENTRY_MODE);
	_delay_ms(1);
	#endif
	
}

static void  send_falling_edge(void)
{
	DIO_write('B',EN,1);
	_delay_ms(2);								//lazm el delay da 
	DIO_write('B',EN,0);
	_delay_ms(2);
}

void LCD_vSend_cmd(char cmd)
{
	#if defined eight_bits_mode
	DIO_write_port(PORTNAME,cmd);
	DIO_write('B',RS,0);					//3shan yktb yktb 3la el command 3latol
	send_falling_edge();
	
	#elif defined four_bits_mode
	write_high_nibble('A',cmd>>4);
	DIO_write('B',RS,0);
	send_falling_edge();
	write_high_nibble('A',cmd);
	DIO_write('B',RS,0);                     //msh lazm bs e7tyate
	send_falling_edge();					//msh lazm bs e7tyate
	_delay_ms(1);                          //msh lazm bs e7tyate
	#endif
}

void LCD_vSend_char(char data)
{
	#if defined eight_bits_mode
	DIO_write_port(PORTNAME,data);
	DIO_write('B',RS,1);					 //3shan aktb f el data register 3aks el fo2 kan 0 3shan aktb f el command 
	send_falling_edge();
	
	#elif defined four_bits_mode
	write_high_nibble('A',data>>4);
	DIO_write('B',RS,1);
	send_falling_edge();
	write_high_nibble('A',data);
	DIO_write('B',RS,1);                     //msh lazm bs e7tyate
	send_falling_edge();					//msh lazm bs e7tyate
	_delay_ms(1);                          //msh lazm bs e7tyate
	#endif
}

void LCD_vSend_String(char *data)     //mlhash 3laka 4 wala 8 bit
{
	while((*data) != '\0')				//law mwslsh ll NULL ykml
	{
		LCD_vSend_char(*data);
		data++;
	}
}

void LCD_vClearScreen(void)				//mlhash 3laka 4 wala 8 bit
{
	LCD_vSend_cmd(CLR_SCREEN);
	_delay_ms(10);
}

void LCD_vMove_Cursor(char row , char coloumn)      //mlhash 3laka 4 wala 8 bit
{
	char data;
	if (row>2 || row<1 || /*coloumn>16 ||*/ coloumn<1)  //3SHAN LAW HABET AKTB 3LA EL LOCTION EL HIDDEN 3NDE
	{
		data=0X80;									//el cursour yo2f 3la awl 5ana
	}
	else if(row==1)
	{
		data= 0X80 + coloumn-1;
	} 
	else if(row==2)
	{
		data= 0XC0 + coloumn-1;
	}
	LCD_vSend_cmd(data);
	_delay_ms(1);
}