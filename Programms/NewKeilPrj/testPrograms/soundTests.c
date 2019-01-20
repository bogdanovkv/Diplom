#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_tim.h"
#include "soundTests.h"

void initTimer()
{
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE); // �������� ������������ �������
   /* ������ ��������� ��������� TIM_TimeBaseInitTypeDef
   * �� ����� ������ ��� ������� ��������.
   */

    TIM_TimeBaseInitTypeDef base_timer;
    TIM_TimeBaseStructInit(&base_timer);
  /* �������� ����������� ��� TIM_Prescaler + 1, ������� �������� 1 */
    base_timer.TIM_Prescaler = 65000 - 1; // �������� 24000
    base_timer.TIM_Period = 1000; //������ 1000 ���������
    TIM_TimeBaseInit(TIM6, &base_timer);

  /* ��������� ���������� �� ���������� (� ������ ������ -
   * �� ������������) �������� ������� TIM6.
   */

    TIM_ITConfig(TIM6, TIM_IT_Update, ENABLE);
    TIM_Cmd(TIM6, ENABLE);  // �������� ������

  /* ��������� ��������� ���������� �� ������������ ��������
   * ������� TIM6. ��� �� ����������
   * �������� � �� ����������� ���.
   */

    NVIC_EnableIRQ(TIM6_DAC_IRQn);
}

void initOutPin(){
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);  // ��������� ������������
    GPIO_InitTypeDef gpio;   // ���������
    GPIO_StructInit(&gpio);  // ��������� ������������ ����������
    gpio.GPIO_OType = GPIO_OType_PP;   // �������� �����������
    gpio.GPIO_Mode = GPIO_Mode_OUT;  // �������� ��� �����
    gpio.GPIO_Pin = GPIO_Pin_13;   // ��� ���� ������
    GPIO_Init(GPIOD, &gpio);
}

void togglePin(){

  /* ��� ��� ���� ���������� ���������� � ��� ���, ����� ���������,
   * ��������� �� ���������� �� ������������ �������� ������� TIM6.
   */
    if (TIM_GetITStatus(TIM6, TIM_IT_Update) != RESET) {
     GPIO_ToggleBits(GPIOD, GPIO_Pin_13);
    }
}
