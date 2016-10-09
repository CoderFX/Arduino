//Fuction:the code used as test L298 DC Stepper Motor Drive Controller Board Module  28BYJ-48 DC5V Stepper Motor 
//Date£º2012-7-5
//Contat MCU I/O:P0.0-P0.3
//Crystal oscillator£º11.0592M
#include<reg51.h>
#define uint unsigned int
#define uchar unsigned char
uchar phasecw[4]={0x07,0x0b,0x0d,0x0e};//positive rotation	 
uchar phaseccw[4]={0x0e,0x0d,0x0b,0x07};//rollback
/***************delay fuction*********************/
delay(uint x)
{
	uint i,j;
	for(i=0;i<x;i++)
		for(j=0;j<110;j++);
}
main()
{
	uint i,j;
	while(1)
	{
		for(j=0;j<256;j++)//positive rotation A circle
		{
			for(i=0;i<4;i++)
			{
				P0=phasecw[i];
				delay(5);
			}
		}

		P0=0x00;//stop run
		delay(1000);
		
		for(j=0;j<256;j++)//rollback A circle
		{
			for(i=0;i<4;i++)
			{
				P0=phaseccw[i];
				delay(5);
			}
		}

		P0=0x00;//stop run
		delay(1000);
	}
}
