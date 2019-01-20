#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include "sevenSegmentsTests.h"
#include "keyboardTests.h"

void initKeyboard(void)
{
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

    GPIO_InitTypeDef GPIO_InitDef;

    GPIO_InitDef.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
    GPIO_InitDef.GPIO_OType = GPIO_OType_PP;
    GPIO_InitDef.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitDef.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_InitDef.GPIO_Speed = GPIO_Speed_100MHz;
    //Initialize pins
    GPIO_Init(GPIOA, &GPIO_InitDef);
		GPIO_SetBits(GPIOA, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3);
	
		GPIO_InitTypeDef GPIO_InitDef_input;
		GPIO_InitDef.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6;
    GPIO_InitDef.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitDef.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_InitDef.GPIO_Speed = GPIO_Speed_100MHz;
    //Initialize pins
    GPIO_Init(GPIOA, &GPIO_InitDef_input);
}


void startKeyboardTracking(void)
{
		GPIO_ResetBits(GPIOA, GPIO_Pin_0);
		checkFirstLine();
	  GPIO_SetBits(GPIOA, GPIO_Pin_0);
	
		GPIO_ResetBits(GPIOA, GPIO_Pin_1);
		checkFirstLine();
	  GPIO_SetBits(GPIOA, GPIO_Pin_1);
	
		GPIO_ResetBits(GPIOA, GPIO_Pin_2);
		checkFirstLine();
	  GPIO_SetBits(GPIOA, GPIO_Pin_2);
	
		GPIO_ResetBits(GPIOA, GPIO_Pin_3);
		checkFirstLine();
	  GPIO_SetBits(GPIOA, GPIO_Pin_3);
}

void checkFirstLine(void)
{
		if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_4) == Bit_RESET)
		{
			 writeTo7SegmentIndicator(segmentOneNumber);
		}
		if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_5) == Bit_RESET)
		{
			 writeTo7SegmentIndicator(segmentTwoNumber);
		}
		if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_6) == Bit_RESET)
		{
			 writeTo7SegmentIndicator(segmentThreeNumber);
		}
}

void checkSecondLine(void)
{
		if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_4) == Bit_RESET)
		{
			 writeTo7SegmentIndicator(segmentFourNumber);
		}
		if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_5) == Bit_RESET)
		{
			 writeTo7SegmentIndicator(0); // Five button
		}
		if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_6) == Bit_RESET)
		{
			 writeTo7SegmentIndicator(0); // Six Button
		}
}

void checkThirdLine(void)
{
		if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_4) == Bit_RESET)
		{
			 writeTo7SegmentIndicator(0); // Seven button
		}
		if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_5) == Bit_RESET)
		{
			 writeTo7SegmentIndicator(0); // Eight button
		}
		if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_6) == Bit_RESET)
		{
			 writeTo7SegmentIndicator(0); // Nine button
		}
}

void checkFourthLine(void)
{
		if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_5) == Bit_RESET)
		{
			 writeTo7SegmentIndicator(0); // Zero button
		}
}
