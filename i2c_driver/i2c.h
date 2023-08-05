/*================================================
BBB_expansion_header_P9_pins     MPU6050 pins
===================================================
P9_19                              SCL
P9_20                              SDA
P9_3                               VCC 3.3v
P9_1                               GND
==================================================== */

#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdint.h>

typedef struct
{
    int fd;
    char device_file[20];
    uint8_t slave_addr;
}i2c_dev;

int i2c_write(i2c_dev *dev, uint8_t addr, uint8_t data);

int i2c_read(i2c_dev *dev, uint8_t base_addr, char *pBuffer, uint32_t len);

int i2c_begin(i2c_dev *dev);