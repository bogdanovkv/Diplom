#include <stdio.h>
#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include "sevenSegmentsTests.h"


void initSegmentIndicator(void)
{
	 RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	 GPIO_InitTypeDef GPIO_InitDef;

	 GPIO_InitDef.GPIO_Pin = GPIO_Pin_11 | GPIO_Pin_12;
	 GPIO_InitDef.GPIO_OType = GPIO_OType_PP;
	 GPIO_InitDef.GPIO_Mode = GPIO_Mode_OUT;
	 GPIO_InitDef.GPIO_PuPd = GPIO_PuPd_NOPULL;
	 GPIO_InitDef.GPIO_Speed = GPIO_Speed_100MHz;
	 GPIO_Init(GPIOD, &GPIO_InitDef);
	 GPIO_ResetBits(GPIOD, GPIO_Pin_11);
}

void writeTo7SegmentIndicator(int data)
{
	for(int i = 0; i < 8; i++)
	{
		int shouldSet = 0;
		shouldSet |= 1 << i;

		if (data & shouldSet)
		{
			passOneToSevenSegment();
		}
		else
		{
			passZeroToSevenSegment();
		}
	}
}

void passOneToSevenSegment(void)
{
	GPIO_SetBits(GPIOD, GPIO_Pin_12);
	delay(10);
	clockForSevenSegment();
}

void passZeroToSevenSegment(void)
{
	GPIO_ResetBits(GPIOD, GPIO_Pin_12);
	delay(10);
	clockForSevenSegment();
}

void clockForSevenSegment(void)
{
	int delayAmount = 10;
	GPIO_SetBits(GPIOD, GPIO_Pin_11);
	delay(delayAmount);
	GPIO_ResetBits(GPIOD, GPIO_Pin_11);
	delay(delayAmount);
}

void delay(int ticks)
{
    volatile int i;
    for (i = 0; i < ticks; i++){};
}

void clear(void)
{
	for (int i = 0; i < 4; i++)
	{
		writeTo7SegmentIndicator(clearScreenValue);
	}
}
