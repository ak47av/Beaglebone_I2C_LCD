TARGET=lcd_text
TARGET_SRC=lcd_text.c

I2C_SRC=i2c_driver/i2c.c
I2C_INC=i2c_driver/i2c.h
I2C_OBJ=i2c_driver/i2c.o

CC = arm-unknown-linux-gnueabihf-gcc

$(TARGET): $(TARGET_SRC) $(I2C_OBJ)
	$(CC) -o $(TARGET) $(TARGET_SRC) $(I2C_OBJ) -Ii2c_driver

$(I2C_OBJ): $(I2C_SRC) $(I2C_INC)
	$(CC) -c $(I2C_SRC) -o $(I2C_OBJ) 

clean:
	rm ./*/*/*.o $(TARGET) 

REMOTE_USER="debian"
REMOTE_HOST="192.168.0.104"
REMOTE_PATH="/home/debian/applications"
directory=/Users/arun/bbb/EmbeddedLinuxBBB/user_apps/*

upload:
	rsync -avz --progress $(directory) "debian@${REMOTE_HOST}:${REMOTE_PATH}"