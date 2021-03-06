/*
 * Samsung Exynos5 SoC series FIMC-IS driver
 *
 *
 * Copyright (c) 2015 Samsung Electronics Co., Ltd
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef fimc_is_helper_i2c_H
#define fimc_is_helper_i2c_H

#include <mach/exynos-fimc-is-sensor.h>
#include <linux/i2c.h>

//#define FIMC_IS_VIRTUAL_MODULE

#ifdef FIMC_IS_VIRTUAL_MODULE
#define i2c_info(fmt, ...) \
	printk(KERN_DEBUG "[^^]"fmt, ##__VA_ARGS__)
#else
#define i2c_info(fmt, ...)
#endif

int fimc_is_i2c_transfer(struct i2c_adapter *adapter, struct i2c_msg *msg, u32 size);
int fimc_is_sensor_addr8_read8(struct i2c_client *client,
	u8 addr, u8 *val);
int fimc_is_sensor_read8(struct i2c_client *client,
	u16 addr, u8 *val);
int fimc_is_sensor_read16(struct i2c_client *client,
	u16 addr, u16 *val);
int fimc_is_sensor_write(struct i2c_client *client,
	u8 *buf, u32 size);
int fimc_is_sensor_addr8_write8(struct i2c_client *client,
	u8 addr, u8 val);
int fimc_is_sensor_write8(struct i2c_client *client,
	u16 addr, u8 val);
int fimc_is_sensor_write16(struct i2c_client *client,
	u16 addr, u16 val);
int fimc_is_sensor_write16_array(struct i2c_client *client,
	u16 addr, u16 *val, u32 num);
#endif
