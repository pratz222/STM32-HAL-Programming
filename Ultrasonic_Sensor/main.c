#include "stm32f1xx_hal.h"

#define TRIG_PIN GPIO_PIN_9
#define TRIG_PORT GPIOA
#define ECHO_PIN GPIO_PIN_10
#define ECHO_PORT GPIOA

void delay_us(uint16_t us);
uint32_t measure_distance();

int main(void) {
    // Initialize the HAL Library
    HAL_Init();
  
    // Configure the system clock
    SystemClock_Config();

    __HAL_RCC_GPIOA_CLK_ENABLE();  // Enable GPIOA clock

    GPIO_InitTypeDef GPIO_InitStruct = {0};
  
    // Trigger Pin configuration
    GPIO_InitStruct.Pin = TRIG_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(TRIG_PORT, &GPIO_InitStruct);
  
    // Echo Pin configuration
    GPIO_InitStruct.Pin = ECHO_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(ECHO_PORT, &GPIO_InitStruct);
  
    while (1) {
        // Measure distance
        uint32_t distance = measure_distance();
      
        printf("Distance: %lu cm\n", distance);
        HAL_Delay(100); 
    }
}


void delay_us(uint16_t us) {
    __HAL_TIM_SET_COUNTER(&htim1, 0);  // Set the counter value to 0
    while (__HAL_TIM_GET_COUNTER(&htim1) < us);  // Wait for the counter to reach the us input in the parameter
}

// Function to measure distance using the HC-SR04 ultrasonic sensor
uint32_t measure_distance() {
    uint32_t local_time = 0;
  
    // Trigger the ultrasonic burst
    HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, GPIO_PIN_SET);
    delay_us(10);  // 10us pulse width
    HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, GPIO_PIN_RESET);

    // Wait for the Echo Pin to go HIGH
    while (HAL_GPIO_ReadPin(ECHO_PORT, ECHO_PIN) == GPIO_PIN_RESET);
  
    // Measure the time the Echo Pin stays HIGH
    while (HAL_GPIO_ReadPin(ECHO_PORT, ECHO_PIN) == GPIO_PIN_SET) {
        local_time++;
        delay_us(1);
    }

    uint32_t distance = local_time * 0.0343 / 2;

    return distance;
}
