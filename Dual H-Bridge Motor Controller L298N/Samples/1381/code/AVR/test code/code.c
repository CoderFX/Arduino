
#include<avr/io.h>
#define uint unsigned int
#define uchar unsigned char
uchar phasecw[4]={0x01,0x02,0x04,0x08};//
uchar phaseccw[4]={0x08,0x04,0x02,0x01};//
void delay(uint x)
{
	uint i,j;
	for(i=0;i<x;i++)
		for(j=0;j<100;j++);
}
int main()
{
	uint i,j,k;
	DDRA |= 0XFF;
	while(1)
	{
		for(k=0;k<4;k++)//
		{
			for(j=0;j<255;j++)
			{
				for(i=0;i<4;i++)
				{
					PORTA = phasecw[i];
					delay(5);
				}
			}		
		}

		PORTA = 0x00;//
		delay(100);

		for(k=0;k<4;k++)//
		{
			for(j=0;j<255;j++)
			{
				for(i=0;i<4;i++)
				{
					PORTA = phaseccw[i];
					delay(5);
				}
			}		
		}


		PORTA = 0x00;//
		delay(100);
	}
}
