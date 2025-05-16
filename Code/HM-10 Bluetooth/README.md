# Overview
<br/>Arduino code for board-to-board communication with HM-10 bluetooth modules. 
## DSD TECH HM-10 Datasheet
<br/>Datasheet for DSD TECH HM-10 modules. Useful for finding AT Commands needed for connection. Here is my recommendation for a simple connection (not the best, but it has worked well for me in the past):
<br/>1) Open the SOFTWARE_SERIAL_V1.ino script and upload it to both Arduino boards, ensure the HM-10 module is wired correctly to the specified pins of the software serial port. You must now ensure that your serial monitor is configured to have no line ending (instead of CR/Newline), the HM-10 module will only properly receive AT commands with this configuration. Also ensure your baud rate is set to 9600 as this is the default for the DSD TECH HM-10 modules.
<br/>2) Get the MAC addresses of both modules using the serial monitor and the AT+ADDR? command.
<br/>3) Initialize one module as central (AT+ROLE1) and one as peripheral (AT+ROLE0).
<br/>4) Write AT+IMME1 to both modules, this will disable connections until an AT+START command is issued to the peripheral.
<br/>5) From the central module, send a connection command (see AT+CO in the datasheet) with the peripheral's MAC address
<br/>With 2 functioning modules, this should result in the 2 bluetooth modules being connected. Now data can be sent via UART between them!
## SOFTWARE_SERIAL_V1.ino
<br/>Code for basic communications between an HM-10 bluetooth module and an arduino's serial monitor.
## SEED_Controller_V3_Trim.ino
<br/>Code for a transmitter controller to interface with UVM 2024->2025 SEED Team 24's AWGR project. Included to reference Bluetooth transmission code and the code that structures a packet of data to send.
## SEED_Robot_Receiver_V3_Serial.ino
<br/>Code for UVM 2024->2025 SEED Team 24's AWGR bluetooth receiver. Included to reference Bluetooth receiving code, as well as the code to pull data from a sent packet and interpret it for numerical usage.
