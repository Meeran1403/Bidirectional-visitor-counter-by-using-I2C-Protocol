#include<LPC21XX.H>
void delay_second(unsigned int sec)
{
	T0PR=15000000-1;
	T0TCR=0x01;
	while(T0TC<sec);
	T0TCR=0x03;
	T0TCR=0X00;
}

void delay_millisecond(unsigned int ms)
{
	T0PR=15000-1;
	T0TCR=0x01;
	while(T0TC<ms);
	T0TCR=0x03;
	T0TCR=0X00;
}
void delay_micromillisecond(unsigned int microsec)
{
	T0PR=15-1;
	T0TCR=0X01;
	while(T0TC<microsec);
	T0TCR=0X03;
	T0TCR=0X00;
}
