#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <i2c/smbus.h>  // Using libi2c-dev for SMBus operations
#include <string.h>
#include "rbpi-i2c.h"
#include "data.h"
#include <gpiod.h>

int main() {
    
    

    int CFG=1;

    i2c_init();
 
    usleep(1000);
    device_id(); //i2c read device ID Check
    isc_enable_sram(); //isc_enable: Enters Programming Mode:SRAM
    isc_erase_sram(); //SRAM Erase   
    sr_read();//Status Register Read
    isc_enable_flash();//ISC_ENABLE: Enters Programming Mode: Flash
    lsc_init_address(CFG);
    isc_erase_flash(CFG);//ISC_ERASE: Flash
    sr_read();   //Status Register Read 
    lsc_init_address(CFG);// Address of internal flash set
    flash_program();//program flash
    lsc_init_address(CFG); //address of itnernal flash set
    verify_flash(); // Verify contents of the internal flash
    lsc_init_address(CFG);
    program_done(); //program done bit of CFG sector
    usleep(1000);
    sr_read();// Read Status Register
    isc_disable();//ISC_DISABLE: Exits programming mode*/



    // Close the I2C bus
    close(fd);
    return EXIT_SUCCESS;
}
