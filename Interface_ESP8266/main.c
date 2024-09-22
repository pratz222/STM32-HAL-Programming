#include "stm32f10x_hal.h"
#include <string.h>

UART_HandleTypeDef huart2;

void SystemClock_Config(void);

static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);

void ESP8266_Init(void);
void ESP8266_SendData(char* data);


int main(void) {
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  
  MX_USART2_UART_Init();
  
  ESP8266_Init();
  while (1) {
    
    ESP8266_SendData("Hello World!");
    HAL_Delay(5000);
  
  }
}


void ESP8266_Init(void) {
  char buffer[50];
  HAL_UART_Transmit(&huart2, (uint8_t*)"AT+RST\r\n", strlen("AT+RST\r\n"), 1000);
  HAL_Delay(2000);
  HAL_UART_Transmit(&huart2, (uint8_t*)"AT+CWMODE=1\r\n", strlen("AT+CWMODE=1\r\n"), 1000);
  HAL_Delay(2000);
  sprintf(buffer, "AT+CWJAP=\"SSID\",\"password\"\r\n");
  HAL_UART_Transmit(&huart2, (uint8_t*)buffer, strlen(buffer), 1000);
  HAL_Delay(2000);
}

void ESP8266_SendData(char* data) {
  char buffer[50];
  sprintf(buffer, "AT+CIPSEND=%d\r\n", strlen(data));
  HAL_UART_Transmit(&huart2, (uint8_t*)buffer, strlen(buffer), 1000);
  HAL_Delay(1000);
  HAL_UART_Transmit(&huart2, (uint8_t*)data, strlen(data), 1000);
  HAL_Delay(1000);
}
