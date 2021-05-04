//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//�о�԰����
//���̵�ַ��http://shop73023976.taobao.com
//
//  �� �� ��   : main.c
//  �� �� ��   : v2.0
//  ��    ��   : HuangKai
//  ��������   : 2018-0101
//  ����޸�   : 
//  ��������   : STM32L151AC8T6���������OLED��ʾ��ʵ��
//              ˵��: 
//              ----------------------------------------------------------------
//              GND    ��Դ��
//              VCC  3.3v��Դ
//              D0   ��PA0��SCL��
//              D1   ��PA1��SDA��             
//              ----------------------------------------------------------------
// �޸���ʷ   :
// ��    ��   : 
// ��    ��   : HuangKai
// �޸�����   : �����ļ�
//��Ȩ���У�����ؾ���
//Copyright(C) �о�԰����2018
//All rights reserved
//******************************************************************************/

#include "main.h"
#include "stm32l1xx_hal.h"
#include "oled.h"
#include "bmp.h"

int main()
{
	u8 t=' ';
	HAL_Init();
	OLED_Init();
	LED_ON;
	while(1)
	{
		OLED_ShowPicture(0,0,72,5,BMP1);
		HAL_Delay(500);
		OLED_Clear();
		OLED_ShowChinese(12,0,0,16);//��
		OLED_ShowChinese(28,0,1,16);//��
		OLED_ShowChinese(44,0,2,16);//԰
		OLED_ShowString(8,16,"2019/02",16);
		OLED_Refresh();
		HAL_Delay(500);
		OLED_Clear();
		OLED_ShowString(0,0,"ASCII:",16);  
		OLED_ShowString(0,16,"CODE :",16);
		OLED_ShowChar(48,0,t,16);//��ʾASCII�ַ�	   
		t++;
		if(t>'~')t=' ';
		OLED_ShowNum(48,16,t,3,16);
		OLED_Refresh();
		HAL_Delay(500);
		OLED_Clear();
		OLED_ShowChinese(0,0,0,16);  //16*16 ��
	  OLED_ShowChinese(0,16,0,24); //24*24 ��
		OLED_ShowChinese(24,0,0,32);//32*32 ��
		OLED_Refresh();
	  HAL_Delay(500);
  	OLED_Clear();
		OLED_ShowString(0,0,"ABC",12);//6*12 ��ABC��
	  OLED_ShowString(0,12,"ABC",16);//8*16 ��ABC��
		OLED_ShowString(28,0,"ABC",24);//12*24 ��ABC��
	  OLED_Refresh();
		HAL_Delay(500);
		OLED_ScrollDisplay(11,4);
	}
}
