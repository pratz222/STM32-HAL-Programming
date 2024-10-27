#include "main.h"

TIM_HandleTypeDef htim2;

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);

int main(void)
{
  int32_t dutyCycle = 0;
  HAL_Init();

  SystemClock_Config();

  MX_GPIO_Init();
  MX_TIM2_Init();

  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);

  while (1)
  {
	   while(dutyCycle < 65535)
	        {
	            TIM2->CCR1 = dutyCycle;
	            dutyCycle += 100;
	            HAL_Delay(1);
	        }
	        while(dutyCycle > 0)
	        {
	            TIM2->CCR1 = dutyCycle;
	            dutyCycle -= 100;
	            HAL_Delay(1);
	        }
  }

}
