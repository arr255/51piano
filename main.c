                    /*12Mhz晶振工作*/
#include <reg51.h>
#define uint unsigned int
#define uchar unsigned char
sbit Beep=P1^6;
sbit gnd=P1^7;
char muse=0;
char m;
char receiveData;
char muzeNumber;
uchar code sound[]={0xff,0x60,0x55,0x4c,0x48,0x40,0x39,0x33,
					0x30,0x2b,0x26,0x24,0x20,0x1c,0x19,
					0x18,0x15,0x13,0x12,0x10,0x0e,0x0d,
                   };
char status=0;
void delay (unsigned char m)   //控制频率延时    
{   
 unsigned i=3*m;   
 while(--i);   
}
void UsartInit()
{
	SCON=0X50;			//设置为工作方式1
	TMOD=0X20;			//设置计数器工作方式2
	PCON=0X80;			//波特率加倍
	TH1=0XF3;				//计数器初始值设置，注意波特率是4800的
	TL1=0XF3;
	ES=1;						//打开接收中断
	EA=1;						//打开总中断
	TR1=1;					//打开计数器
}
void playMusic(){
	m=sound[muse];
	while(1) { if(status==1) {Beep=~Beep,delay(m);}}
	}
void main()
{
	gnd=0;	
	UsartInit();  //	串口初始化
	while(1){
		playMusic();
		}		
}
/*******************************************************************************
* 函数名         : Usart() interrupt 4
* 函数功能		  : 串口通信中断函数
* 输入           : 无
* 输出         	 : 无
*******************************************************************************/
void Usart() interrupt 4
{

	receiveData=SBUF;//出去接收到的数据
	RI = 0;//清除接收中断标志位
	if(receiveData>=48 && receiveData<=55)
		{m=sound[receiveData-48];status=1;}
	else if(receiveData>=97 && receiveData<=110)
		{m=sound[receiveData-89];status=1;}
	else
		status=0;

}