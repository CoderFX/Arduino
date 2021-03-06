//Function: This program is based on ARDUINO MEGA 2560 driver L298-driven stepper motor 28BYJ-48
//Time:August,17,2012
int IN1=1;
int IN2=2;
int IN3=3;
int IN4=4;
void setup()
{
  int i;
  for(i=1;i<5;i++)
    pinMode(i,OUTPUT);
}
void loop()
{
  byte phaseccw[8]={0x01,0x02,0x04,0x08,0x01,0x02,0x04,0x08}; 
  byte speed = 5;
  byte i,j,k,n,temp;
  for(n=0;n<3;n++)//Forward to accelerate the rotation three times
  {
    for(k=0;k<255;k++)
    {
      for(i=0;i<8;i++)
      {
         temp = phaseccw[i];
          for(j=1;j<5;j++)
          {
              //temp = phaseccw[i];
              digitalWrite(j,temp&0x01);
              temp>>=1;
          }
          delay(speed);
      }    
    }  
    speed++;
  }
  
  for(j=1;j<5;j++)
    digitalWrite(j,phaseccw[i]&0x00);
  delay(1000);

  for(n=0;n<3;n++)//Reverse deceleration rotation three times
  {  
    for(k=0;k<255;k++)
    {
      for(i=0;i<8;i++)
      {
          temp = phaseccw[i];
          for(j=1;j<5;j++)
          {
              digitalWrite(5-j,temp&0x01);
              temp>>=1;
          }
          delay(speed);
      }
    }   
    speed--;
  }
  
  for(j=1;j<5;j++)
    digitalWrite(j,phaseccw[i]&0x00);
  delay(1000);
}
