sspiem-rbpi: $(OBJ)
	gcc -o rhodz_i2c rbpi-i2c.c main.c data.c -lgpiod
