/*====================================================================================================*/
/*====================================================================================================*/
#include "drivers\nrf5x_system.h"
#include "drivers\nrf5x_adc.h"
#include "modules\module_serial.h"

#include "imuCube.h"
/*====================================================================================================*/
/*====================================================================================================*/
void IMUCube_Init( void )
{
  IMUCube_CKOCK_Config();
  IMUCube_GPIO_Config();
  IMUCube_ADC_Config();
  IMUCube_UART_Config();
}
/*====================================================================================================*/
/*====================================================================================================*/
void IMUCube_Loop( void )
{
  uint16_t adc = 0;
  float vol = 0;

  while(1) {
    delay_ms(100);
    adc = ADC_Read(NRF_ADC_CONFIG_INPUT_7);
    vol = adc * 0.0070157f;
    printf("VOL = %2.4f V, AD = %d\r\n", vol, adc);
  }
}
/*====================================================================================================*/
/*====================================================================================================*/