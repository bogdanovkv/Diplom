#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"


void initVD(void)
{
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
    GPIO_InitTypeDef GPIO_InitDef;
    GPIO_InitDef.GPIO_Pin = GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14;
    GPIO_InitDef.GPIO_OType = GPIO_OType_PP;
    GPIO_InitDef.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitDef.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_InitDef.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_Init(GPIOD, &GPIO_InitDef);
}

void testVD(void)
{
    volatile int i;
    while (1) {
        // Toggle leds
        GPIO_ToggleBits(GPIOD, GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14);
        // Waste some tome
        for (i = 0; i < 1000000; i++);
    }
}
