#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_tim.h"
#include "soundTests.h"

void initTimer()
{
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE); // включаем тактирование таймера
   /* Другие параметры структуры TIM_TimeBaseInitTypeDef
   * не имеют смысла для базовых таймеров.
   */

    TIM_TimeBaseInitTypeDef base_timer;
    TIM_TimeBaseStructInit(&base_timer);
  /* Делитель учитывается как TIM_Prescaler + 1, поэтому отнимаем 1 */
    base_timer.TIM_Prescaler = 65000 - 1; // делитель 24000
    base_timer.TIM_Period = 1000; //период 1000 импульсов
    TIM_TimeBaseInit(TIM6, &base_timer);

  /* Разрешаем прерывание по обновлению (в данном случае -
   * по переполнению) счётчика таймера TIM6.
   */

    TIM_ITConfig(TIM6, TIM_IT_Update, ENABLE);
    TIM_Cmd(TIM6, ENABLE);  // Включаем таймер

  /* Разрешаем обработку прерывания по переполнению счётчика
   * таймера TIM6. это же прерывание
   * отвечает и за опустошение ЦАП.
   */

    NVIC_EnableIRQ(TIM6_DAC_IRQn);
}

void initOutPin(){
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);  // разрешаем тактирование
    GPIO_InitTypeDef gpio;   // структура
    GPIO_StructInit(&gpio);  // заполняем стандартными значениями
    gpio.GPIO_OType = GPIO_OType_PP;   // подтяжка резисторами
    gpio.GPIO_Mode = GPIO_Mode_OUT;  // работаем как выход
    gpio.GPIO_Pin = GPIO_Pin_13;   // все пины диодов
    GPIO_Init(GPIOD, &gpio);
}

void togglePin(){

  /* Так как этот обработчик вызывается и для ЦАП, нужно проверять,
   * произошло ли прерывание по переполнению счётчика таймера TIM6.
   */
    if (TIM_GetITStatus(TIM6, TIM_IT_Update) != RESET) {
     GPIO_ToggleBits(GPIOD, GPIO_Pin_13);
    }
}
