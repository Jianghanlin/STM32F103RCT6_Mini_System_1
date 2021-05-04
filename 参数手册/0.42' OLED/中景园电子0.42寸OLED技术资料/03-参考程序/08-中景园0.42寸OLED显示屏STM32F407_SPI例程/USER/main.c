//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//�о�԰����
//���̵�ַ��http://shop73023976.taobao.com/?spm=2013.1.0.0.M4PqC2
//
//  �� �� ��   : main.c
//  �� �� ��   : v2.0
//  ��    ��   : HuangKai
//  ��������   : 2018-0101
//  ����޸�   : 
//  ��������   : OLED 4�ӿ���ʾ����(STM32F4ϵ��)
//              ˵��: 
//              ----------------------------------------------------------------
//              GND    ��Դ��
//              VCC  ��5V��3.3v��Դ
//              D0   ��PG12��SCL��
//              D1   ��PD5��SDA��
//              RES  ���濪���帴λ
//              DC   ��PD15
//              CS   ��PD1               
//              ----------------------------------------------------------------
// �޸���ʷ   :
// ��    ��   : 
// ��    ��   : HuangKai
// �޸�����   : �����ļ�
//��Ȩ���У�����ؾ���
//  ��������   : 2018-0101
//All rights reserved
//******************************************************************************/


#include "sys.h"
#include "delay.h"
#include "led.h"
#include "oled.h"
#include "bmp.h"


int main(void)
{ 
	u8 t=0;
	delay_init(168);
	LED_Init();					//��ʼ��LED
 	OLED_Init();				//��ʼ��OLED
	t=' ';  
	LED0=0;
	while(1) 
	{
		OLED_ShowPicture(0,0,72,5,BMP1);
		delay_ms(500);
		OLED_Clear();
		OLED_ShowChinese(12,0,0,16);//��
		OLED_ShowChinese(28,0,1,16);//��
		OLED_ShowChinese(44,0,2,16);//԰
		OLED_ShowString(8,16,"2019/02",16);
		OLED_Refresh();
		delay_ms(500);
		OLED_Clear();
		OLED_ShowString(0,0,"ASCII:",16);  
		OLED_ShowString(0,16,"CODE :",16);
		OLED_ShowChar(48,0,t,16);//��ʾASCII�ַ�	   
		t++;
		if(t>'~')t=' ';
		OLED_ShowNum(48,16,t,3,16);
		OLED_Refresh();
		delay_ms(500);
		OLED_Clear();
		OLED_ShowChinese(0,0,0,16);  //16*16 ��
	  OLED_ShowChinese(0,16,0,24); //24*24 ��
		OLED_ShowChinese(24,0,0,32);//32*32 ��
		OLED_Refresh();
	  delay_ms(500);
  	OLED_Clear();
		OLED_ShowString(0,0,"ABC",12);//6*12 ��ABC��
	  OLED_ShowString(0,12,"ABC",16);//8*16 ��ABC��
		OLED_ShowString(28,0,"ABC",24);//12*24 ��ABC��
	  OLED_Refresh();
		delay_ms(500);
		OLED_ScrollDisplay(11,4);
	}
}
