// Board STM32F103C8T6
// Write in main.c file under src folder
// Rest of the main.c code is AUTO Generated

#include <stm32f1xx_hal.h>  //HAL library

int main(){
  HAL_init();
  
  while(1){
    HAL_GPIO_WritePin(GPIOA, GPIO_Pin_1, 1);
    HAL_Delay(500);
    HAL_GPIO_WritePin(GPIOA, GPIO_Pin_1, 0);
    HAL_Delay(500);
  }

}