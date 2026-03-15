  /*
 * sensirion_i2c_hal.c
 *
 *  Created on: Mar 13, 2026
 *      Author: USER
 */


#include "stm32f4xx_hal.h"

#include "sensirion_common.h"
#include "sensirion_config.h"
#include "sensirion_i2c_hal.h"


extern I2C_HandleTypeDef hi2c1;

void sensirion_i2c_hal_init(void){

	/*
	 __HAL_RCC_I2C1_CLK_ENABLE();

	  hi2c1.Instance = I2C1;
	  hi2c1.Init.ClockSpeed = 100000;
	  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
	  hi2c1.Init.OwnAddress1 = 0;
	  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	  hi2c1.Init.OwnAddress2 = 0;
	  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;

	  HAL_I2C_Init(&hi2c1);
	*/
}

void sensirion_i2c_hal_free(void){

}

int8_t sensirion_i2c_hal_read(uint8_t address, uint8_t* data, uint8_t count){

	return (int8_t)HAL_I2C_Master_Receive(&hi2c1,(uint16_t)(address<<1), data, count, 150);

}
int8_t sensirion_i2c_hal_write(uint8_t address , const uint8_t* data,uint8_t count){

	return (int8_t)HAL_I2C_Master_Transmit(&hi2c1, (uint16_t)(address<<1), (uint8_t*)data, count, 150);
}

void sensirion_i2c_hal_sleep_usec(uint32_t useconds){

	uint32_t msec=useconds/1000;
	if(useconds % 1000 > 0){
		msec++;
	}

	HAL_Delay(msec);
}
