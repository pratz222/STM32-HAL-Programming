
 #include "math.h"
 #include "stm32f10x_hal.h"

 #define DAC_CHANNEL  DAC_CHANNEL_1
 #define DAC_TRIGGER  DAC_TRIGGER_NONE
 #define SINE_WAVE_SAMPLES  128
 DAC_HandleTypeDef hdac;
 
// Sine wave lookup table
 const uint16_t sineWave[SINE_WAVE_SAMPLES] = {
 2048, 2447, 2831, 3185, 3495, 3750, 3939, 4056,
 4095, 4056, 3939, 3750, 3495, 3185, 2831, 2447,
 2048, 1648, 1264, 910, 600, 345, 156, 39,
 0, 39, 156, 345, 600, 910, 1264, 1648,
 2048
 };

 void SystemClock_Config(void);
 static void MX_DAC_Init(void);
 
 int main(void)
 {
   HAL_Init();
   SystemClock_Config();
   MX_DAC_Init();
   while (1)
   {
     for (uint16_t i = 0; i < SINE_WAVE_SAMPLES; i++)
   {
   HAL_DAC_SetValue(&hdac, DAC_CHANNEL,
   DAC_ALIGN_12B_R, sineWave[i]);
   HAL_Delay(10); // Adjust delay for desired frequency
   }
   }
 }

 static void MX_DAC_Init(void)
 {
 hdac.Instance = DAC;
 if (HAL_DAC_Init(&hdac) != HAL_OK)
 {
 Error_Handler();
 }
DAC_ChannelConfTypeDef sConfig = {0};
 sConfig.DAC_SampleAndHold =
 DAC_SAMPLEANDHOLD_DISABLE;
 sConfig.DAC_Trigger = DAC_TRIGGER;
 sConfig.DAC_HighFrequency =
 DAC_HIGH_FREQUENCY_INTERFACE_MODE_DISABL
 E;
 sConfig.DAC_OutputBuffer =
 DAC_OUTPUTBUFFER_ENABLE;
 if (HAL_DAC_ConfigChannel(&hdac, &sConfig,
 DAC_CHANNEL) != HAL_OK)
 {
 Error_Handler();
 }
 }
