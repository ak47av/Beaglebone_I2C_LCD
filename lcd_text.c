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

#include "i2c.h"

#define I2C2_DEVICE_FILE "/dev/i2c-2"
#define LCD_SLAVE_ADDR 0x27

int main(void)
{
    i2c_dev LCD;
    strcpy(LCD.device_file, I2C2_DEVICE_FILE);
    LCD.slave_addr = LCD_SLAVE_ADDR;

    i2c_begin(&LCD); 

}