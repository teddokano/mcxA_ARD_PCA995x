/*
 * Copyright 2024 Tedd OKANO
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include	"r01lib.h"
r01lib_start;	/* *** place this word before making instance of r01lib classes *** */

#include	"led/PCA9955B.h"
#include	"led/PCA9957.h"

#define	USE_PCA9955B
#ifdef	USE_PCA9955B
I2C			i2c;
PCA9955B	ledd( i2c );
#else
SPI			spi;
PCA9957		ledd( spi );
#endif

int main(void)
{
	PRINTF("\r***** Hello, PCA9955B! *****\r\n");

#ifdef	USE_PCA9955B
	I2C_device::scan( i2c, 124 ); //  Scan stop at 124
	ledd.begin( 1.0, PCA9955B::ARDUINO_SHIELD );
#else
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
