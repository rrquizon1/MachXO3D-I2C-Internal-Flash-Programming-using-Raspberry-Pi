#ifndef _RBPI_I2C_H_
#define _RBPI_I2C_H_

extern int fd;
int i2c_write_byte(int length, unsigned char *data_bytes);
int i2c_write_and_read( unsigned char *write_data, int write_len, unsigned char *read_data, int read_len);
int i2c_init();
int i2c_write_long(unsigned char *write_command, int writecomm_len, unsigned char *write_data, int writedata_len);
void device_id();
void isc_enable_sram();
void isc_erase_sram();
void isc_erase_flash();
void isc_enable_flash();
void sr_read();
void lsc_init_address();
void flash_program();
void verify_flash();
void program_done();
void isc_disable();
extern struct gpiod_line *crst;

#endif
