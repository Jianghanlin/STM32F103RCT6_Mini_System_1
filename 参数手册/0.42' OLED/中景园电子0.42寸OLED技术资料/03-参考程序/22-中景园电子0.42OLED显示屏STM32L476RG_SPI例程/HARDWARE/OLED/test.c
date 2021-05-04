#include "oled.h"
#include "bmp.h"

void Show_Test(void)
{
	u8 t=' ';
		OLED_ShowPicture(0,0,72,5,BMP1);
		HAL_Delay(500);
		OLED_Clear();
		OLED_ShowChinese(12,0,0,16);//中
		OLED_ShowChinese(28,0,1,16);//景
		OLED_ShowChinese(44,0,2,16);//园
		OLED_ShowString(8,16,"2019/02",16);
		OLED_Refresh();
		HAL_Delay(500);
		OLED_Clear();
		OLED_ShowString(0,0,"ASCII:",16);  
		OLED_ShowString(0,16,"CODE :",16);
		OLED_ShowChar(48,0,t,16);//显示ASCII字符	   
		t++;
		if(t>'~')t=' ';
		OLED_ShowNum(48,16,t,3,16);
		OLED_Refresh();
		HAL_Delay(500);
		OLED_Clear();
		OLED_ShowChinese(0,0,0,16);  //16*16 中
	  OLED_ShowChinese(0,16,0,24); //24*24 中
		OLED_ShowChinese(24,0,0,32);//32*32 中
		OLED_Refresh();
	  HAL_Delay(500);
  	OLED_Clear();
		OLED_ShowString(0,0,"ABC",12);//6*12 “ABC”
	  OLED_ShowString(0,12,"ABC",16);//8*16 “ABC”
		OLED_ShowString(28,0,"ABC",24);//12*24 “ABC”
	  OLED_Refresh();
		HAL_Delay(500);
		OLED_ScrollDisplay(11,4);
}










