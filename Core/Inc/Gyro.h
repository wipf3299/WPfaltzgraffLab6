/*
 * Gyro.h
 *
 *  Created on: Nov 7, 2023
 *      Author: williampfaltz
 */

#include "stm32f4xx_hal.h"
#include <stdio.h>

#ifndef INC_GYRO_H_
#define INC_GYRO_H_

#define GYRO_SPI SPI5

#define GYRO_SPI_PORT GPIOF
#define GRYO_SCK_PIN  GPIO_PIN_7
#define GYRO_MISO_PIN GPIO_PIN_8
#define GYRO_MOSI_PIN GPIO_PIN_9

#define CS_PORT GPIOC
#define CS_PIN  GPIO_PIN_1

#define TIMEOUT 10000

#define CTRL_REG1_OFFSET 0x20
#define CTRL_REG2_OFFSET 0x21
#define CTRL_REG3_OFFSET 0x22
#define CTRL_REG4_OFFSET 0x23
#define CTRL_REG5_OFFSET 0x24
#define FIFO_CTRL_REG_OFFSET 0x2e

#define WHOAMI_REG_OFFSET  0x0f
#define OUTTEMP_REG_OFFSET 0x26

#define XOUTL_REG_OFFSET 0x28
#define XOUTH_REG_OFFSET 0x29

#define YOUTL_REG_OFFSET 0x2a
#define YOUTH_REG_OFFSET 0x2b

#define ZOUTL_REG_OFFSET 0x2c
#define ZOUTH_REG_OFFSET 0x2d

#define CTRL1_SET 0x1f
#define CTRL4_SET 0x10
#define CTRL5_SET 0xc0
#define FIFO_SET  0x40

#define REBOOT_VAL 0x80
#define ON_VALUE   0x08

#define read  (1 << 7)
#define write (0 << 7)

void Gyro_Init();
void Gyro_GetDeviceID();
void Gyro_ON();
void Gryo_Reboot();
void Gyro_GetTemp();
void Gyro_GetXYZ();
void Gyro_RegConfig();
void Gyro_HALstatus();
void Gyro_SlaveEnable();
void Gyro_SlaveDisable();
void Gyro_DummyRead();

#endif /* INC_GYRO_H_ */






























