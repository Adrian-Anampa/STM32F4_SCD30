/*
 * sensirion_common.h
 *
 *  Created on: Mar 13, 2026
 *      Author: USER
 */

#ifndef INC_SENSIRION_COMMON_H_
#define INC_SENSIRION_COMMON_H_

#include "sensirion_config.h"

#define NO_ERROR 0
#define NOT_IMPLEMENTED_ERROR 31

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(x) (sizeof(x)/sizeof(*(x)))
#endif

#define SENSIRION_COMMAND_SIZE 2
#define SENSIRION_WORD_SIZE 2
#define SENSIRION_NUM_WORDS(x) (sizeof(x)/ SENSIRION_WORD_SIZE)
#define SENSIRION_MAX_BUFFER_WORD 32

/*--------------Enumera para describir los tipos de enteros----*/
typedef enum {
	BYTE=1 ,
	SHORT =2,
	INTEGER =4,
	LONG_INTEGER=8,
}INT_TYPE;

/*----Convierte un arreglo de bytes a un entero de 16bits--*/

int16_t sensirion_common_bytes_to_int16_t(const uint8_t* bytes);

/*----Convierte un arreglo de bytes a un entero de 32bits--*/

int32_t sensirion_common_bytes_to_int32_t(const uint8_t* bytes);


uint16_t sensirion_common_bytes_to_uint16_t(const uint8_t* bytes);


uint32_t sensirion_common_bytes_to_uint32_t(const uint8_t* bytes);


float sensirion_common_bytes_to_float_t(const uint8_t* bytes);


void sensirion_common_uint32_to_bytes_t(const uint32_t value,const uint8_t* bytes);

void sensirion_common_uint16_to_bytes_t(const uint16_t value,const uint8_t* bytes);

void sensirion_common_int32_to_bytes_t(const int32_t value,const uint8_t* bytes);

void sensirion_common_int16_to_bytes_t(const int16_t value,const uint8_t* bytes);

void sensirion_common_float_to_bytes_t(const float value,const uint8_t* bytes);

/*-- Copia los bytes de un arreglo a otro ---

 	 @param source Arreglo de bytes que se van a copiar
 	 @param destination arreglo de byter que se copiaran
 	 @param data_length numero de bytes a copiar
  */

void sensirion_common_copy_bytes(const uint8_t* source, uint8_t* destination , uint16_t data_length);

/*-- Copia los bytes desde un arreglo de bytes a enteros

 	 @param source Arreglo de bytes a ser copiado
 	 @parm int_value Apunta al entero de bytes a ser copiado
 	 @param int_type Tipo(size) de el intero a ser copiado

  ---*/


void sensirion_common_to_integer(const uint8_t* source, uint8_t* destination , INT_TYPE int_type, uint8_t data_length);


#endif /* INC_SENSIRION_COMMON_H_ */
