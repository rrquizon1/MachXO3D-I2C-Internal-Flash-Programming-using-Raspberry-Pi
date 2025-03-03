This is an I2C Internal Flash programming using Raspberry pi 5.


MachXO3D have two sectors for internal flash programming namely CFG0 and CFG1. These sectors can be used for dual-boot instead of using an external flash for golden image. FPGA-TN-02069-1.7 (MachXO3D Programming and Configuration User Guide) shows more information regarding MachXO3D dualboot and other features. This document also describes the instructions used by this programming example.

Source Files

main.c- contains the programming procedure

rbpi-i2c.c- contains function for I2C transaction and programming commands for MachXO3D devices.

data.c- contains the image to be programmed


Some keypoints and other pointers for this example.

1. This example, uses I2C make sure that the I2C_PORT is enabled on your project and that wishbone is instantiated in your design with a valid clock. FPGA-TN-02069 explains this:
 ![image](https://github.com/user-attachments/assets/7f73b417-83fe-4300-a70f-973187e47914)

2. When doing read operation, do not use a stop condition after sending a read comand, instead send an I2C restart and do an I2C Read:
![image](https://github.com/user-attachments/assets/fdb4821e-2f62-49c3-97db-86db4a3f750a)


3.  Jedec file contains binary bitstream data. It is helpful to convert it to hex to be able to use hexadecimal array for programming. Lattice has a Deployment Tool which can be used to convert jedec into hex file:
   ![image](https://github.com/user-attachments/assets/d6d42e34-0e62-4db6-812e-4f32163a7bed)

Sample hex output is below:

![image](https://github.com/user-attachments/assets/b8b0a46a-594c-480d-b277-9d0650d59acb)

You could use a simple script to turn this into a hexadecimal array:
![image](https://github.com/user-attachments/assets/d24c600a-0fb9-4858-b6d3-657027c51ddf)

Flow in main.c:
![image](https://github.com/user-attachments/assets/54e29e23-a9da-4ca4-a21d-77bed2e3a38a)

Sample Terminal Run:
![image](https://github.com/user-attachments/assets/9ae88c06-cc6c-41c5-bbb1-025bd2ee22f4)



