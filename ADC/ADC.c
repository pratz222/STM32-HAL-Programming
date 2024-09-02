#include "main.h"
#include "stdio.h"
#include "string.h"

int main(void)
{
  /* USER CODE BEGIN 1 */

	uint16_t value;   			 // Variable to store the ADC result, which is 16-bit wide (in STM32)
	char msg[10];            // Character array (string) to hold the message that will be transmitted via UART.

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
  MX_ADC_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

	  HAL_ADC_Start(&hadc);							            // Start ADC Conversion
	  HAL_ADC_PollForConversion(&hadc, 10000);      // To stop the ADC Conversion
	  value = HAL_ADC_GetValue(&hadc);              // Get Value after ADC conversion
    
	  sprintf(msg, "%hu\r\n", value);               // To Format the ADC value as a string and store it in msg
                                                  // The "%hu" format specifier is used for unsigned short integers

	  // Now transmit the converted data via UART
	  HAL_UART_Transmit(&huart1, (uint8_t *)msg, strlen(msg), 1000);    // Typecast to convert to 8-bit for UART Transmission


    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

