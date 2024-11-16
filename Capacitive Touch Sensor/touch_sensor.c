#include "main.h"
 
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
 
int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
 
  while (1)
  {
      // If Touch is Detected
      if(HAL_GPIO_ReadPin (GPIOB, GPIO_PIN_10))
      {
          HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);
      }
      else
      {
          HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);
      }
  }
}
