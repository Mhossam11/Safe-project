/*
 * SAFE.c
 *
 * Created: 3/17/2023 1:52:03 PM
 *  Author: 20100
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL 
#include <util/delay.h>
#include "LCD.h"
#include "Keypad.h"
#include "BUZZER.h"
#include "EEPROM.h"

#define EEPROM_STATUS_LOCATION 0X20 //TO CHECK IF THE PASSWORD SET OR NOT
#define EEPROM_LOCATION1 0X21		//PASSWORD DATA IN EEPROM
#define EEPROM_LOCATION2 0X22
#define EEPROM_LOCATION3 0X23
#define EEPROM_LOCATION4 0X24
#define MAX_TRIES 3					//NUMBER OF TRIES BEFOR SAFE CLOSE
char arr[4];						// TO TAKE DATA OF PASS

int main(void)
{
	
	char value=NOTPRESSED;			//0XFF
	char flag=0,i;
	char tries=MAX_TRIES;
	LCD_vInt();
	KeyPad_vInit();
	Buzzer_Init('B',3);
	LCD_vSend_cmd(DISPLAY_ON_CURSOR_OFF);
	
	if(EEPROM_Read(EEPROM_STATUS_LOCATION) == NOTPRESSED)  //CHECKING IF THE PASSWORD SET BEFOR?
	{
		LCD_vSend_String("SET PASS:");
		for(i=0;i<=3;i++)
		{
			do 
			{
				value = KeyPad_u8check_press();     //set new password 
			} while (value==NOTPRESSED);
			
			LCD_vSend_char(value);					//print numbers of password 
			_delay_ms(500);
			LCD_vMove_Cursor(1,10+i);
			LCD_vSend_char('*');                   //print * instead of password numbers
			_delay_ms(500);
			EEPROM_Write(EEPROM_LOCATION1+i,value);
		}
		EEPROM_Write(EEPROM_STATUS_LOCATION,0x00);		// to know that we have already password 
	}
	
	while(flag ==0 )   //to know if status of safe
	{
		LCD_vSend_cmd(CLR_SCREEN);
		LCD_vSend_String("Check pass:");
		for(i=0;i<=3;i++)
		{
			do 
			{
				arr[i]=KeyPad_u8check_press();  //take password from user to check if it correct 
			} while (arr[i] == NOTPRESSED );
			LCD_vSend_char(arr[i]);
			_delay_ms(500);
			LCD_vMove_Cursor(1,12+i);
			LCD_vSend_char('*');
			_delay_ms(500);
		}
		if(EEPROM_Read(EEPROM_LOCATION1)==arr[0] && EEPROM_Read(EEPROM_LOCATION2)==arr[1] && EEPROM_Read(EEPROM_LOCATION3)==arr[2] && EEPROM_Read(EEPROM_LOCATION3)==arr[3]) //if pass is true 
		{
			LCD_vSend_cmd(CLR_SCREEN);
			LCD_vSend_String("Right password");
			LCD_vMove_Cursor(2,1);
			BUZZER_write('B',3,1);
			LCD_vSend_String("Safe is open");
			_delay_ms(250);
			BUZZER_write('B',3,0);
			flag=1;
		}
		else				//if pass is not true
		{
			tries=tries-1;
			if(tries>0)
			{
				LCD_vSend_cmd(CLR_SCREEN);
				LCD_vSend_String("Wrong password !");
				BUZZER_write('B',3,1);
				_delay_ms(250);
				BUZZER_write('B',3,0);
				LCD_vMove_Cursor(2,1);
				LCD_vSend_char(tries+48);       //print numbers of tries 
				LCD_vSend_String(" Tries left");
				_delay_ms(1000);
			}
			else 
			{
				LCD_vSend_cmd(CLR_SCREEN);
				LCD_vSend_String("wrong password");
				LCD_vMove_Cursor(2,1);
				LCD_vSend_String("Safe Closed");
				for(i=0;i<=15;i++)				//Alert for owner
				{
						BUZZER_write('B',3,1);
						_delay_ms(100);
						BUZZER_write('B',3,0);
						_delay_ms(100);
						
				}
				flag=1;
			}
		}
		
	}		
	
    
}
	