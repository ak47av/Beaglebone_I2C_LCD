#include "i2c.h"

int i2c_write(i2c_dev *dev, uint8_t addr, uint8_t data)
{
    int ret;
    char buf[2],msg_buf[100];
    buf[0] = addr;
    buf[1] = data;
    ret = write(dev->fd, buf, 2);
    if(ret <= 0)
    {
        sprintf(msg_buf, "i2c write failed\n addr:%d data:%d\n", addr, data);
        perror(msg_buf);
        return -1;
    }
    return 0;
}

/*read "len" many bytes from "addr" of the sensor in to the adresss indicated by "pBuffer" */
int i2c_read(i2c_dev *dev, uint8_t base_addr, char *pBuffer, uint32_t len)
{
    int ret;
    char buf[2], msg_buf[100];
    buf[0] = base_addr;
    ret = write(dev->fd, buf, 1);
    if (ret <= 0)
    {
        perror("write address failed\n");
        return -1;
    }

    ret = read(dev->fd, pBuffer, len);
    if (ret <= 0)
    {
        sprintf(msg_buf, "i2c read failed\n addr:%d\n", base_addr);
        perror(msg_buf);
    }
    return 0;
}

int i2c_begin(i2c_dev *dev)
{
    printf("Device file: %s\n", dev->device_file);
    if((dev->fd = open(dev->device_file, O_RDWR))<0)
    {
        perror("Failed to open I2C device file\n");
        return -1;
    }

    if(ioctl(dev->fd, I2C_SLAVE, dev->slave_addr) < 0)
    {
        perror("Failed to set I2C slave address.\n");
        close(dev->fd);
        return -1;
    }
}