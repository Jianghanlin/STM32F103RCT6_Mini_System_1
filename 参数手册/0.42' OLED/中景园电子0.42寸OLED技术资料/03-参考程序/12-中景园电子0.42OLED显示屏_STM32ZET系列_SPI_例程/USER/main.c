//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//中景园电子
//店铺地址：http://shop73023976.taobao.com/?spm=2013.1.0.0.M4PqC2
//
//  文 件 名   : main.c
//  版 本 号   : v2.0
//  作    者   : HuangKai
//  生成日期   : 2014-0101
//  最近修改   : 
//  功能描述   : OLED 4接口演示例程(51系列)
//              说明: 
//              ----------------------------------------------------------------
//              GND    电源地
//              VCC  接5V或3.3v电源
//              D0   接PG12（SCL）
//              D1   接PD5（SDA）
//              RES  不接(与开发板复位连接)
//              DC   接PD15
//              CS   接PD1               
//              ----------------------------------------------------------------
// 修改历史   :
// 日    期   : 
// 作    者   : HuangKai
// 修改内容   : 创建文件
//版权所有，盗版必究。
//Copyright(C) 中景园电子2014/3/16
//All rights reserved
//******************************************************************************/

#include "delay.h"
#include "sys.h"
#include "oled.h"
#include "bmp.h"
#include "led.h"
int main(void)
{
	u8 t;
	delay_init();
	OLED_Init();
	LED_Init();
	OLED_ColorTurn(0);//0正常显示，1 反色显示
  OLED_DisplayTurn(0);//0正常显示 1 屏幕翻转显示
//	OLED_DrawPoint(0,0);
//	OLED_DrawLine(20,0,50,60);
//	OLED_DrawCircle(64,32,20);
	OLED_Refresh();
	t=' ';
	LED0=0;
	while(1)
	{
		OLED_ShowPicture(0,0,72,5,BMP1);
		delay_ms(500);
		OLED_Clear();
		OLED_ShowChinese(12,0,0,16);//中
		OLED_ShowChinese(28,0,1,16);//景
		OLED_ShowChinese(44,0,2,16);//园
		OLED_ShowString(8,16,"2019/02",16);
		OLED_Refresh();
		delay_ms(500);
		OLED_Clear();
		OLED_ShowString(0,0,"ASCII:",16);  
		OLED_ShowString(0,16,"CODE :",16);
		OLED_ShowChar(48,0,t,16);//显示ASCII字符	   
		t++;
		if(t>'~')t=' ';
		OLED_ShowNum(48,16,t,3,16);
		OLED_Refresh();
		delay_ms(500);
		OLED_Clear();
		OLED_ShowChinese(0,0,0,16);  //16*16 中
	  OLED_ShowChinese(0,16,0,24); //24*24 中
		OLED_ShowChinese(24,0,0,32);//32*32 中
		OLED_Refresh();
	  delay_ms(500);
  	OLED_Clear();
		OLED_ShowString(0,0,"ABC",12);//6*12 “ABC”
	  OLED_ShowString(0,12,"ABC",16);//8*16 “ABC”
		OLED_ShowString(28,0,"ABC",24);//12*24 “ABC”
	  OLED_Refresh();
		delay_ms(500);
		OLED_ScrollDisplay(11,4);
	}
}

