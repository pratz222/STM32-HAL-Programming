// Board: STM32F103C8T6
// IDE: STM32CubeIDE
// Rest of the config. code is autogenerated based on IOC settings

int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM3_Init();
  /* USER CODE BEGIN 2 */

  // ALTERNATE METHOD without while loop
            // In ARR Register we have already set 1000
           // Now to set duty cycle we need to change value in CCR register 1000 = 100%, 500 = 50%, 250 = 25%, 0 = 0% duty cycle
          // TIM3 ->CCR4 = 500;                // Set 50% duty cycle\
  
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4);        // Start PWM signal on channel 4


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
    {
	  for(int i = 0; i <= 1000; i++)
	  {
		  __HAL_TIM_SET_COMPARE(&htim3 , TIM_CHANNEL_4, i);
		  HAL_Delay(1);
	  }
	  for(int i = 1000; i > 0; i--)
	  {
		  __HAL_TIM_SET_COMPARE(&htim3 , TIM_CHANNEL_4, i);
		  HAL_Delay(1);
	  }

  }
  /* USER CODE END 3 */
}
