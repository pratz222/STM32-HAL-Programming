#include "main.h"
 
#define BUFF_LEN  1
 
UART_HandleTypeDef huart1;
 
uint8_t RX_BUFF[BUFF_LEN] = {0};
 
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
 
int main(void)
{
    HAL_Init();
  
    SystemClock_Config();
  
    MX_GPIO_Init();
  
    MX_USART1_UART_Init();
  
    HAL_UART_Receive_IT(&huart1, RX_BUFF, BUFF_LEN);
 
    while (1)
    {
        if(RX_BUFF[0] == '1')
        {
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1);
        }
        else if(RX_BUFF[0] == '0')
        {
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0);
        }
    }
}
 
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if(huart->Instance == huart1.Instance)
    {
    HAL_UART_Receive_IT(&huart1, RX_BUFF, BUFF_LEN);
    }
}
