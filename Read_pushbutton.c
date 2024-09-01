// Board: STM32F103C8T6

int main(void)
{

  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();

  int button=0;
  
  while (1)
  {
	  button = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);

	  if(button==1){
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);
	  }
	  else{
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);
	  }


  }

}
