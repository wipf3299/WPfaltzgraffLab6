/*
 * Gyro.c
 *
 *  Created on: Nov 7, 2023
 *      Author: williampfaltz
 */
#include "Gyro.h"

static HAL_StatusTypeDef HALstatus;
static SPI_HandleTypeDef spi;

void Gyro_Init() {
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitTypeDef GPIO_GyroInitStruct = {0};

	__HAL_RCC_SPI5_CLK_ENABLE();
	__HAL_RCC_GPIOF_CLK_ENABLE();

	GPIO_InitStruct.Pin =       GRYO_SCK_PIN|GYRO_MISO_PIN|GYRO_MOSI_PIN;
	GPIO_InitStruct.Mode =      GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull =      GPIO_NOPULL;
	GPIO_InitStruct.Speed =     GPIO_SPEED_FREQ_LOW;
	GPIO_InitStruct.Alternate = GPIO_AF5_SPI5;
	HAL_GPIO_Init(GYRO_SPI_PORT, &GPIO_InitStruct);


	__HAL_RCC_GPIOC_CLK_ENABLE();

	GPIO_GyroInitStruct.Pin =   CS_PIN;
	GPIO_GyroInitStruct.Mode =  GPIO_MODE_OUTPUT_PP;
	GPIO_GyroInitStruct.Pull =  GPIO_NOPULL;
	GPIO_GyroInitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
	HAL_GPIO_Init(CS_PORT, &GPIO_GyroInitStruct);

	Gyro_SlaveDisable();

	spi.Instance = SPI5;

	spi.Init.Mode = SPI_MODE_MASTER;
	spi.Init.Direction = SPI_DIRECTION_2LINES;
	spi.Init.DataSize = SPI_DATASIZE_8BIT;
	spi.Init.CLKPolarity = SPI_POLARITY_HIGH;
	spi.Init.CLKPhase = SPI_PHASE_2EDGE;
	spi.Init.NSS = SPI_NSS_SOFT;
	spi.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_64;
	spi.Init.FirstBit = SPI_FIRSTBIT_MSB;
	spi.Init.TIMode = SPI_TIMODE_DISABLE;
	spi.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
	spi.Init.CRCPolynomial = 0;

	HAL_SPI_Init(&spi);

	return;
}

void Gyro_RegConfig() {
	uint16_t ctrl1DataBuffer = (write | CTRL_REG1_OFFSET) | (CTRL1_SET << 8);
	uint16_t size = 2;

	Gyro_SlaveEnable();

	while(HAL_GPIO_ReadPin(CS_PORT, CS_PIN) != GPIO_PIN_RESET );

	HALstatus = HAL_SPI_Transmit(&spi, (uint8_t*) &ctrl1DataBuffer, size, TIMEOUT);
	Gyro_HALstatus();

	Gyro_SlaveDisable();

	Gyro_SlaveEnable();

	uint16_t ctrl4DataBuffer = (write | CTRL_REG4_OFFSET) | (CTRL4_SET << 8);

	while(HAL_GPIO_ReadPin(CS_PORT, CS_PIN) != GPIO_PIN_RESET );

	HALstatus = HAL_SPI_Transmit(&spi, (uint8_t*) &ctrl4DataBuffer, size, TIMEOUT);
	Gyro_HALstatus();

	Gyro_SlaveDisable();
	Gyro_SlaveEnable();

	uint16_t ctrl5dataBuffer = (write | CTRL_REG5_OFFSET) | (CTRL5_SET << 8);

	while(HAL_GPIO_ReadPin(CS_PORT, CS_PIN) != GPIO_PIN_RESET );

	HALstatus = HAL_SPI_Transmit(&spi, (uint8_t*) &ctrl5dataBuffer, size, TIMEOUT);
	Gyro_HALstatus();

	Gyro_SlaveDisable();
	Gyro_SlaveEnable();

	uint16_t fifoDataBuffer = (write | FIFO_CTRL_REG_OFFSET) | (FIFO_SET << 8);

	while(HAL_GPIO_ReadPin(CS_PORT, CS_PIN) != GPIO_PIN_RESET );

	HALstatus = HAL_SPI_Transmit(&spi, (uint8_t*) &fifoDataBuffer, size, TIMEOUT);
	Gyro_HALstatus();

	Gyro_SlaveDisable();

	return;
}

void Gyro_GetDeviceID() {
	uint8_t dataBuffer = (read | WHOAMI_REG_OFFSET);
	uint16_t receivedData = 0x00;
	uint16_t size = 2;

	Gyro_SlaveEnable();

	while(HAL_GPIO_ReadPin(CS_PORT, CS_PIN) != GPIO_PIN_RESET );

	HALstatus = HAL_SPI_TransmitReceive(&spi, (uint8_t*) &dataBuffer, (uint8_t*) &receivedData, size, TIMEOUT);
	Gyro_HALstatus();

	uint16_t DataReturned = (0xFF00 & receivedData) >> 8;
	printf("The Device ID is: %d \n", DataReturned);

	Gyro_SlaveDisable();

	return;
}

void Gyro_DummyRead() {
	uint8_t dataBuffer = (read | WHOAMI_REG_OFFSET);
	uint16_t receivedData = 0x00;
	uint16_t size = 2;

	Gyro_SlaveEnable();

	while(HAL_GPIO_ReadPin(CS_PORT, CS_PIN) != GPIO_PIN_RESET );

	HALstatus = HAL_SPI_TransmitReceive(&spi, (uint8_t*) &dataBuffer, (uint8_t*) &receivedData, size, TIMEOUT);
	Gyro_HALstatus();

	Gyro_SlaveDisable();

	return;
}

void Gyro_ON() {
	uint8_t dataBuffer = (read | CTRL_REG1_OFFSET);
	uint16_t receivedData = 0x00;
	uint16_t size = 2;

	Gyro_SlaveEnable();

	while(HAL_GPIO_ReadPin(CS_PORT, CS_PIN) != GPIO_PIN_RESET );

	HALstatus = HAL_SPI_TransmitReceive(&spi, (uint8_t*) &dataBuffer, (uint8_t*) &receivedData, size, TIMEOUT);
	Gyro_HALstatus();

	uint16_t toSend = receivedData;

	Gyro_SlaveDisable();

	uint16_t dataBuffer2 = (write | CTRL_REG1_OFFSET) | ((toSend |= ON_VALUE) << 8);

	Gyro_SlaveEnable();

	while(HAL_GPIO_ReadPin(CS_PORT, CS_PIN) != GPIO_PIN_RESET );

	HALstatus = HAL_SPI_Transmit(&spi, (uint8_t*) &dataBuffer2, size, TIMEOUT);
	Gyro_HALstatus();

	Gyro_SlaveDisable();

	return;
}

void Gryo_Reboot() {
	uint8_t dataBuffer = (read | CTRL_REG5_OFFSET);
	uint16_t receivedData = 0x00;
	uint16_t size = 2;

	Gyro_SlaveEnable();

	while(HAL_GPIO_ReadPin(CS_PORT, CS_PIN) != GPIO_PIN_RESET );

	HALstatus = HAL_SPI_TransmitReceive(&spi, (uint8_t*) &dataBuffer, (uint8_t*) &receivedData, size, TIMEOUT);
	Gyro_HALstatus();

	uint16_t toSend = receivedData;

	Gyro_SlaveDisable();

	uint16_t dataBuffer2 = (write | CTRL_REG5_OFFSET) | ((toSend |= REBOOT_VAL) << 8);

	Gyro_SlaveEnable();

	while(HAL_GPIO_ReadPin(CS_PORT, CS_PIN) != GPIO_PIN_RESET );

	HALstatus = HAL_SPI_Transmit(&spi, (uint8_t*) &dataBuffer2, size, TIMEOUT);
	Gyro_HALstatus();

	Gyro_SlaveDisable();

	return;
}

uint16_t celsiusToFahrenheit(uint16_t data) {
	uint16_t toReturn = 32;

	data = (data + 6) * 1.8;

	return data + toReturn;
}

void Gyro_GetTemp() {
	uint8_t dataBuffer = (read | OUTTEMP_REG_OFFSET);
	uint16_t receivedData = 0x00;
	uint16_t size = 2;

	Gyro_SlaveEnable();

	while(HAL_GPIO_ReadPin(CS_PORT, CS_PIN) != GPIO_PIN_RESET );

	HALstatus = HAL_SPI_TransmitReceive(&spi, &dataBuffer, (uint8_t*) &receivedData, size, TIMEOUT);
	Gyro_HALstatus();

	uint16_t DataReturned = (0xFF00 & receivedData) >> 8;

	uint16_t tempF = celsiusToFahrenheit(DataReturned);

	printf("The Device Temperature is: %d Fahrenheit.\n", tempF);

	Gyro_SlaveDisable();

	return;
}

void Gyro_GetXYZ() {
	uint8_t x1dataBuffer = (read | XOUTL_REG_OFFSET);
	uint16_t receivedData = 0x00;
	uint16_t size = 2;

	Gyro_SlaveEnable();

// x values
	while(HAL_GPIO_ReadPin(CS_PORT, CS_PIN) != GPIO_PIN_RESET );

	HALstatus = HAL_SPI_TransmitReceive(&spi, &x1dataBuffer, (uint8_t*) &receivedData, size, TIMEOUT);
	Gyro_HALstatus();

	uint16_t xvalL = (0xFF00 & receivedData) >> 8;

	Gyro_SlaveDisable();
	Gyro_SlaveEnable();

	uint8_t x2dataBuffer = (read | XOUTH_REG_OFFSET);
	receivedData = 0x00;

	while(HAL_GPIO_ReadPin(CS_PORT, CS_PIN) != GPIO_PIN_RESET );

	HALstatus = HAL_SPI_TransmitReceive(&spi, &x2dataBuffer, (uint8_t*) &receivedData, size, TIMEOUT);
	Gyro_HALstatus();

	uint16_t xvalH = (0xFF00 & receivedData) >> 8;

	Gyro_SlaveDisable();
	Gyro_SlaveEnable();

//y values
	uint8_t y1dataBuffer = (read | YOUTL_REG_OFFSET);
	receivedData = 0x00;

	while(HAL_GPIO_ReadPin(CS_PORT, CS_PIN) != GPIO_PIN_RESET );

	HALstatus = HAL_SPI_TransmitReceive(&spi, &y1dataBuffer, (uint8_t*) &receivedData, size, TIMEOUT);
	Gyro_HALstatus();

	uint16_t yvalL = (0xFF00 & receivedData) >> 8;

	Gyro_SlaveDisable();
	Gyro_SlaveEnable();

	uint8_t y2dataBuffer = (read | YOUTH_REG_OFFSET);
	receivedData = 0x00;

	while(HAL_GPIO_ReadPin(CS_PORT, CS_PIN) != GPIO_PIN_RESET );

	HALstatus = HAL_SPI_TransmitReceive(&spi, &y2dataBuffer, (uint8_t*) &receivedData, size, TIMEOUT);
	Gyro_HALstatus();

	uint16_t yvalH = (0xFF00 & receivedData) >> 8;

	Gyro_SlaveDisable();
	Gyro_SlaveEnable();

//z values
	uint8_t z1dataBuffer = (read | ZOUTL_REG_OFFSET);
	receivedData = 0x00;

	while(HAL_GPIO_ReadPin(CS_PORT, CS_PIN) != GPIO_PIN_RESET );

	HALstatus = HAL_SPI_TransmitReceive(&spi, &z1dataBuffer, (uint8_t*) &receivedData, size, TIMEOUT);
	Gyro_HALstatus();

	uint16_t zvalL = (0xFF00 & receivedData) >> 8;

	Gyro_SlaveDisable();
	Gyro_SlaveEnable();

	uint8_t z2dataBuffer = (read | ZOUTH_REG_OFFSET);
	receivedData = 0x00;

	while(HAL_GPIO_ReadPin(CS_PORT, CS_PIN) != GPIO_PIN_RESET );

	HALstatus = HAL_SPI_TransmitReceive(&spi, &z2dataBuffer, (uint8_t*) &receivedData, size, TIMEOUT);
	Gyro_HALstatus();

	uint16_t zvalH = (0xFF00 & receivedData) >> 8;

	int16_t xvalF = (xvalL) | (xvalH << 8);

	int16_t yvalF = (yvalL) | (yvalH << 8);

	int16_t zvalF = (zvalL) | (zvalH << 8);

	printf("The x value is: %d \n", xvalF);

	printf("The y value is: %d \n", yvalF);

	printf("The z value is: %d \n", zvalF);

	Gyro_SlaveDisable();

	return;
}

void Gyro_HALstatus() {
	if (HALstatus != HAL_OK) {
		for(;;);
	} else {
		return;
	}
}

void Gyro_SlaveEnable() {
	HAL_GPIO_WritePin(CS_PORT, CS_PIN, GPIO_PIN_RESET);
	return;
}

void Gyro_SlaveDisable() {
	HAL_GPIO_WritePin(CS_PORT, CS_PIN, GPIO_PIN_SET);
	return;
}
























