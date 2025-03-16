#include<LPC21XX.H>
#include "LCD.H"
#include "Rotate.h"
#include "EEPROM.H"


#define LED0 1<<17
#define IR1 12
#define IR2 13


void COUNT(void);
unsigned int INcnt=0,OUTcnt=0,PRcnt=0;

int main()
{

	init_i2c();

	i2c_eeprom_write(0X50,0X00,0);
	i2c_eeprom_write(0X50,0X01,0);
	delay_millisecond(100);

//	INcnt=i2c_eeprom_read(0X50,0X00);
//	OUTcnt=i2c_eeprom_read(0X50,0X01);
//	delay_millisecond(100);

	LCD_INIT();

	LCD_ROTATE("        BIDIRECTIONAL VISITOR COUNTER","V24CE2S9");

	LCD_COMMAND(0X80);
	LCD_STR("COUNT");
	LCD_COMMAND(0XC0);
	LCD_STR("IN:  OUT:  PR:  ");

	//for LED ON , OFF

	PINSEL0=0;
	IODIR0=LED0;
	IOCLR0=LED0; //CLR LED ON



	while(1)
	{

		COUNT();
		PRcnt=INcnt-OUTcnt;

		if(PRcnt>0)
			IOCLR0=LED0;  //CLR LED0 ON

		else
			IOSET0=LED0; //SET LED0 OFF
		

		//TO display in count
		LCD_COMMAND(0XC3);
		if(INcnt>9)
		{
			LCD_DATA((INcnt/10)+48);
			LCD_DATA((INcnt%10)+48);
		}
		else
		LCD_DATA(INcnt+48);

		//To display out count
		LCD_COMMAND(0XC9);
		if(OUTcnt>9)
		{
			LCD_DATA((OUTcnt/10)+48);
			LCD_DATA((OUTcnt%10)+48);
		}
		else
		LCD_DATA(OUTcnt+48);

		//To display present count
		LCD_COMMAND(0XCE);
		if(PRcnt>9)
		{
			LCD_DATA((PRcnt/10)+48);
			LCD_DATA((PRcnt%10)+48);
		}
		else if(PRcnt==0)
		{
			LCD_DATA(0+48);
			LCD_DATA(' ');
		}
		else
		{
			LCD_DATA(PRcnt+48);
			LCD_DATA(' ');
		}

	}
}


void COUNT()
{
	if(((IOPIN0>>IR1)&1)==0)
	{
		if(INcnt<100)
			++INcnt;
		delay_millisecond(500);
		i2c_eeprom_write(0X50,0X00,INcnt);
	}
	else if(((IOPIN0>>IR2)&1)==0)
	{
		if((PRcnt>0)&&(OUTcnt<=INcnt)&&(OUTcnt<100))
			++OUTcnt;
		delay_millisecond(500);
		i2c_eeprom_write(0X50,0X01,OUTcnt);
	}
}
