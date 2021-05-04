//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//中景园电子
//店铺地址：http://shop73023976.taobao.com
//
//  文 件 名   : main.c
//  版 本 号   : v2.0
//  作    者   : HuangKai
//  生成日期   : 2018-0101
//  最近修改   : 
//  功能描述   : STM32L053C8T6开发板点亮显示屏实验
//              说明: 
//              ----------------------------------------------------------------
//              GND    电源地
//              VCC  接5V或3.3v电源
//              D0   接PA0（SCL）
//              D1   接PA1（SDA）
//              RES  接PA2
//              DC   接PA3
//              CS   接PA4               
//              ----------------------------------------------------------------
// 修改历史   :
// 日    期   : 
// 作    者   : HuangKai
// 修改内容   : 创建文件
//版权所有，盗版必究。
//Copyright(C) 中景园电子2018
#include "main.h"
#include "stm32l0xx_hal.h"
#include "oled.h"
#include "bmp.h"


void SystemClock_Config(void);

int main(void)
{
	u8 t=' ';
	SystemClock_Config();
  HAL_Init();
  OLED_Init();
	LED_ON;
  while (1)
  {  
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
}

void SystemClock_Config(void)  
{  
  
  RCC_OscInitTypeDef RCC_OscInitStruct;  
  RCC_ClkInitTypeDef RCC_ClkInitStruct;  
  
  __PWR_CLK_ENABLE();  
  
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);  
  
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;  
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;  
  RCC_OscInitStruct.HSICalibrationValue = 16;  
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;  
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;  
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLLMUL_4;  
  RCC_OscInitStruct.PLL.PLLDIV = RCC_PLLDIV_2;  
  HAL_RCC_OscConfig(&RCC_OscInitStruct);  
  
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_SYSCLK;  
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;  
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;  
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;  
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;  
  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1);  
  
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);  
  
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);  
  
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);  
}

