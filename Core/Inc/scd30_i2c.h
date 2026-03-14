/*
 * scd30_i2c.h
 *
 *  Created on: Mar 14, 2026
 *      Author: USER
 */

#ifndef INC_SCD30_I2C_H_
#define INC_SCD30_I2C_H_

#include "sensirion_config.h"
#define SCD30_I2C_ADDR_61 0X61

typedef enum{

		SCD30_START_PERIODIC_MEASUREMENT_CMD_ID = 0x10,
	    SCD30_STOP_PERIODIC_MEASUREMENT_CMD_ID = 0x104,
	    SCD30_SET_MEASUREMENT_INTERVAL_CMD_ID = 0x4600,
	    SCD30_GET_MEASUREMENT_INTERVAL_CMD_ID = 0x4600,
	    SCD30_GET_DATA_READY_CMD_ID = 0x202,
	    SCD30_READ_MEASUREMENT_DATA_CMD_ID = 0x300,
	    SCD30_ACTIVATE_AUTO_CALIBRATION_CMD_ID = 0x5306,
	    SCD30_GET_AUTO_CALIBRATION_STATUS_CMD_ID = 0x5306,
	    SCD30_FORCE_RECALIBRATION_CMD_ID = 0x5204,
	    SCD30_GET_FORCE_RECALIBRATION_STATUS_CMD_ID = 0x5204,
	    SCD30_SET_TEMPERATURE_OFFSET_CMD_ID = 0x5403,
	    SCD30_GET_TEMPERATURE_OFFSET_CMD_ID = 0x5403,
	    SCD30_GET_ALTITUDE_COMPENSATION_CMD_ID = 0x5102,
	    SCD30_SET_ALTITUDE_COMPENSATION_CMD_ID = 0x5102,
	    SCD30_READ_FIRMWARE_VERSION_CMD_ID = 0xd100,
	    SCD30_SOFT_RESET_CMD_ID = 0xd304,
}SCD30_CMD_ID;

void scd30_init(uint8_t i2c_address);

int16_t scd30_await_data_ready();

int16_t scd30_blocking_read_measurement_data(float* co2_concentration , float* temperature , float* humidity);

int16_t scd30_start_periodic_measurement(uint16_t ambient_pressure);
/**
 * @brief Stops continuous measurement of the sensor.
 *
 * Stops the continuous measurement of the SCD30.
 *
 * @return error_code 0 on success, an error code otherwise.
 */

int16_t scd30_stop_periodic_measurement();
/**
 * Sets the interval used by the SCD30 sensor to measure in continuous
 * measurement mode. Initial value is 2s. The chosen measurement interval is
 * saved in non-volatile memory and thus is not reset to its initial value after
 * power up.
 */

int16_t scd30_set_measurement_interval(uint16_t interval);

int16_t scd30_get_measurement_interval(uint16_t* interval);

int16_t scd30_get_data_ready(uint16_t* data_ready_flag);

int16_t scd30_read_measurement_data(float* co2_concentration ,
									float* temperatura , float* humidity);
/*
 * Activa o desactiva continuamente automatic self-calibration ( ASC=
 * Continuous automatic self-calibration (ASC) can be (de-)activated with this
 * command. When activated for the first time a period of minimum 7 days is
 * needed so that the algorithm can find its initial parameter set for ASC. The
 * sensor has to be exposed to fresh air for at least 1 hour every day. Also
 * during that period, the sensor may not be disconnected from the power supply.
 * Otherwise the procedure to find calibration parameters is aborted and has to
 * be restarted from the beginning. The successfully calculated parameters are
 * stored in non-volatile memory of the SCD30 having the effect that after a
 * restart the previously found parameters for ASC are still present.
 *
 * @param[in] do_activate Set activate flag.
 *
 * @note Note that the most recently found self-calibration parameters will be
 * actively used for self-calibration disregarding the status of this feature.
 * Finding a new parameter set by the here described method will always
 * overwrite the settings from external recalibration and vice-versa. The
 * feature is switched off by default. To work properly SCD30 has to see fresh
 * air on a regular basis. Optimal working conditions are given when the sensor
 * sees fresh air for one hour every day so that ASC can constantly
 * re-calibrate. ASC only works in continuous measurement mode. ASC status is
 * saved in non-volatile memory. When the sensor is powered down while ASC is
 * activated SCD30 will continue with automatic self-calibration after
 * repowering without sending the command.
 */

int16_t scd30_activate_auto_calibration(uint16_t do_activate);

/*
 * Dado el estado de autocalibracion
 * Lee la salida del estado  de la activacion de la calibracion a si mismo
 * is_active indica si automaticamente la calibracion esta activado
 *
 * Retorna error_code 0 sobre el suceso ,
 */

int16_t scd30_get_auto_calibration_status(uint16_t* is_activate);

int16_t scd30_force_recalibration(uint16_t co2_ref_concentration);


int16_t scd30_get_force_recalibration_status(uint16_t* co2_ref_concentration);

int16_t scd30_set_temperature_offset(uint16_t temperature_offset);

int16_t scd30_get_temperature_offset(uint16_t* temperature_offset);

int16_t scd30_get_altitude_compensation(uint16_t* altitude);


int16_t scd30_read_firmware_version(uint8_t* major, uint8_t* minor);

int16_t scd30_soft_reset();


#endif /* INC_SCD30_I2C_H_ */
