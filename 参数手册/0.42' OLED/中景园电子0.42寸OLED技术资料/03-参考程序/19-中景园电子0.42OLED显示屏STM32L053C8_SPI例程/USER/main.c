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
//  ��������   : STM32L053C8T6�����������ʾ��ʵ��
//              ˵��: 
//              ----------------------------------------------------------------
//              GND    ��Դ��
//              VCC  ��5V��3.3v��Դ
//              D0   ��PA0��SCL��
//              D1   ��PA1��SDA��
//              RES  ��PA2
//              DC   ��PA3
//              CS   ��PA4               
//              ----------------------------------------------------------------
// �޸���ʷ   :
// ��    ��   : 
// ��    ��   : HuangKai
// �޸�����   : �����ļ�
//��Ȩ���У�����ؾ���
//Copyright(C) �о�԰����2018
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

