/*
 * Copyright 2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include	"r01lib.h"
#include	"led/PCA9955B.h"
#include	"led/PCA9957.h"

#define	USE_PCA9955B
#ifdef	USE_PCA9955B
I2C			i2c( I2C_SDA, I2C_SCL );	//	SDA, SCL
PCA9955B	ledd( i2c );
#else
SPI			spi( D11, D12, D13, D10 );	//	MOSI, MISO, SCLK, CS
PCA9957		ledd( spi );
#endif

int main(void)
{
#ifdef	USE_PCA9955B
	PRINTF("\r***** Hello, PCA9955B! *****\r\n");

	I2C_device::scan( i2c, 124 ); //  Scan stop at 124
	ledd.begin( 1.0, PCA9955B::ARDUINO_SHIELD );
#else
	PRINTF("\r***** Hello, PCA9957! *****\r\n");

	ledd.begin( 1.0, PCA9957::ARDUINO_SHIELD );
#endif


	while ( true )
	{
		ledd.pwm( 0, 1.0 );
		wait( 0.1 );
		ledd.pwm( 0, 0.0 );
		wait( 0.1 );
	}
}
