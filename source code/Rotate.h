#include<LPC21XX.H>
#include<string.h>
void LCD_ROTATE(unsigned char *firstRow ,unsigned char *secondRow)
{
	unsigned int i,j,n=strlen((void*)firstRow);
	


unsigned int shiftCount = 0;

for(j=0;j<25;j++) {
    delay_millisecond(200);

    // Update the display for the first row with shifting
    LCD_COMMAND(0x80);  // Set cursor to the beginning of the first row
    for (i=0; i<n;i++) {
        LCD_DATA(firstRow[(i + shiftCount) % n]);
    }
    
    // Update the display for the second row without shifting
    LCD_COMMAND(0xC0);  // Set cursor to the beginning of the second row
    LCD_STR(secondRow);  // Display the content of the second row

    shiftCount = (shiftCount + 1) % n;  // Increment shift count and wrap around after n shifts
    delay_millisecond(200);
}
LCD_COMMAND(0X01);



/*	
	LCD_COMMAND(0X87);
	LCD_STR(d);
	for(i=0;i<30;i++)
    {
		delay_millisecond(120);

		LCD_COMMAND(0X87);
		delay_millisecond(1);

		LCD_COMMAND(0X18);
		delay_millisecond(1);

		LCD_COMMAND(0XC0);
		LCD_STR("v24ce2s9");

		delay_millisecond(120);

	} 
	LCD_COMMAND(0X01);

*/
	
	
	/*
	//unsigned char *temp=d;
	for(i=1;i<n*2;i++)
	{

		while(*temp)
		LCD_DATA(*temp++);

		temp=d;


		LCD_COMMAND(0X01);
		LCD_COMMAND(0X80+i);
		delay_millisecond(100);
	} */
}
