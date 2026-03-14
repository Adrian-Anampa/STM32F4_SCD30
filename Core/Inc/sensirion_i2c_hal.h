/*
 * sensirion_i2c_hal.h
 *
 *  Created on: Mar 13, 2026
 *      Author: USER
 */

#ifndef INC_SENSIRION_I2C_HAL_H_
#define INC_SENSIRION_I2C_HAL_H_


#include "sensirion_config.h"

/*-- Funcion que selecciona el bus i2c actual por indice--- */

int16_t sensirion_i2c_hal_select_bus(uint8_t bus_idx);

/*------Funcion para iniciarlizar la comunicacion i2c ----*/

void sensirion_i2c_hal_init(void);

/*------Funcion que libera todos los recursos inicializados
 *  por sensirion_i2c_hal_init ----*/

void sensirion_i2c_hal_free(void);

/*------Ejecuta una lectura de transicion en el bus I2C
 * leyendo un dado numero de bits ----*/

int8_t sensirion_i2c_hal_read(uint8_t address, uint8_t* data, uint8_t count);

/*------Ejecuta una transicion de escritura en el bus I2C
 * enviando un numero dado de bytes ----*/

int8_t sensirion_i2c_hal_write(uint8_t address , const uint8_t* data,uint8_t count);

/*------Duerme por un dado numero de microsegundos , la funcion deberia
 * retardar la ejecuccion aproximada, pero no menor que el tiempo dado
 *
 * Cuando usas hardware I2C
 * A pesar de la unidad , una precision de <10 ms es suficiente
 *
 * Cuando utilizan software i2c
 *
 * La precision necesaria depender de la frecuencia i2c deseada, i.e
 * debe ser exacto sobre medio ciclo de reloj( define in
 * SENSIRION_I2C_CLOCK_PERIOD_USEC in sensirion_sw_i2c_gpio.h
 *
 * Ejemplo con 400Khz requiere una precision de 1/(2*400kHz) == 1.25usec  ----*/

void sensirion_i2c_hal_sleep_usec(uint32_t useconds);




#endif /* INC_SENSIRION_I2C_HAL_H_ */
