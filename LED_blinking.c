// Board STM32F103C8T6
// Write in main.c file under src folder

#include <stm32f1xx_hal.h>  //HAL library
HAL_init();

int main(){
  while(1){
    HAL_GPIO_WritePin(GPIOA, GPIO_Pin_1, 1);
    HAL_Delay(500);
    HAL_GPIO_WritePin(GPIOA, GPIO_Pin_1, 0);
    HAL_Delay(500);
  }

}
