# Overview
<br/>Arduino code for board-to-board communication with HM-10 bluetooth modules. 
## DSD TECH HM-10 Datasheet
<br/>Datasheet for DSD TECH HM-10 modules. Useful for finding AT Commands needed for connection. Here is my recommendation for a simple connection (not the best, but it has worked well for me in the past):
<br/>1) Open the SOFTWARE_SERIAL_V1.ino script and upload it to both Arduino boards, ensure the HM-10 module is wired correctly to the specified pins of the software serial port.
<br/>2) Get the MAC addresses of both modules using the serial monitor and the AT+ADDR? command.
<br/>3) Initialize one module as central (AT+ROLE1) and one as peripheral (AT+ROLE0).
<br/>4) Write AT+IMME1 to both modules, this will disable connections until an AT+START command is issued to the peripheral.
<br/>5) From the central module, send a connection command (see AT+CO in the datasheet) with the peripheral's MAC address
<br/>With 2 functioning modules, this should result in the 2 bluetooth modules being connected. Now data can be sent via UART between them!
