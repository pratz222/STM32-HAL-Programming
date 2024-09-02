// Board: STM32F103C8T6
// IDE: STM32CubeIDE
// Rest of the main.c code is AUTO Generated

int main(void)
{
  /* USER CODE BEGIN 1 */

	uint8_t msg1[] = "Hello";
	uint8_t newline[] = "\r\n";
	uint8_t msg2[] = "I'm Pratyush";
	uint8_t received[10];

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
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */


  // Sending data to other Device using UART

  HAL_UART_Transmit(&huart1, msg1, sizeof(msg1), 20);
  HAL_UART_Transmit(&huart1, newline , sizeof(newline), 20);
  HAL_UART_Transmit(&huart1, msg2, sizeof(msg2), 20);


  // Receiving data and displaying it Again

  HAL_UART_Transmit(&huart1, received, sizeof(received), 5000);   // Timeout = 5000 bcoz it needs time to receive and read incoming data
  HAL_UART_Transmit(&huart1, newline , sizeof(newline), 20);
  HAL_UART_Transmit(&huart1, received, sizeof(received), 20);

}
