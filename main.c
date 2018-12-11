                    /*12Mhz������*/
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
void delay (unsigned char m)   //����Ƶ����ʱ    
{   
 unsigned i=3*m;   
 while(--i);   
}
void UsartInit()
{
	SCON=0X50;			//����Ϊ������ʽ1
	TMOD=0X20;			//���ü�����������ʽ2
	PCON=0X80;			//�����ʼӱ�
	TH1=0XF3;				//��������ʼֵ���ã�ע�Ⲩ������4800��
	TL1=0XF3;
	ES=1;						//�򿪽����ж�
	EA=1;						//�����ж�
	TR1=1;					//�򿪼�����
}
void playMusic(){
	m=sound[muse];
	while(1) { if(status==1) {Beep=~Beep,delay(m);}}
	}
void main()
{
	gnd=0;	
	UsartInit();  //	���ڳ�ʼ��
	while(1){
		playMusic();
		}		
}
/*******************************************************************************
* ������         : Usart() interrupt 4
* ��������		  : ����ͨ���жϺ���
* ����           : ��
* ���         	 : ��
*******************************************************************************/
void Usart() interrupt 4
{

	receiveData=SBUF;//��ȥ���յ�������
	RI = 0;//��������жϱ�־λ
	if(receiveData>=48 && receiveData<=55)
		{m=sound[receiveData-48];status=1;}
	else if(receiveData>=97 && receiveData<=110)
		{m=sound[receiveData-89];status=1;}
	else
		status=0;

}