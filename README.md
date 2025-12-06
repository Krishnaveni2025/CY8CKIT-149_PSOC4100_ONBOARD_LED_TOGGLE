# Bare-Metal Firmware on PSoC 4100S Plus (Cortex-M0+)

This repository contains a complete bare-metal firmware project built from scratch for the **CY8CKIT-149 PSoC 4100S Plus (ARM Cortex-M0+)**.
It demonstrates how to set up a custom startup routine, linker script, and Makefile without relying on vendor HALs or libraries.

## Project Structure

### main.c
Contains the bare-metal application code.
- Configures **Port 1.2** as a GPIO output.
- Toggles **P1.2** in an infinite loop (software delay).

### psoc_startup.c
Contains the vector table and system startup code.
- **Vector Table**: The first word (4 bytes) stores the initial Main Stack Pointer (MSP) value. The subsequent words store the entry point addresses for exception handlers (Reset, NMI, HardFault, etc.).
- **Reset_Handler**:
    - Copies the `.data` section from FLASH to RAM.
    - Initializes the `.bss` section to zero.
    - Calls `main()`.
- **Default_Handler**: A default infinite loop handler for unexpected interrupts.

### psoclinker.ld
The linker script that defines the memory layout (Flash and RAM regions) and section placement.

### Makefile
The build script to compile the project using `arm-none-eabi-gcc` and flash it using OpenOCD.
generates main.o, psoc_startup.o, blinky.elf, blinky.map, blinky.hex, main.exe
## Usage

1. **Build**: Run `make` to compile the project.
2. **Flash**: Run `make program` to flash the firmware to the device.


https://www.linkedin.com/posts/krishnavenipurne_embeddedsystems-baremetal-firmware-activity-7398047546297745408-PczJ?utm_source=social_share_send&utm_medium=member_desktop_web&rcm=ACoAAD5xtIcBWRoURnxLdPDVfPUYc

https://github.com/user-attachments/assets/abf28f8f-d582-4f76-aad9-b847e4d3fd49


https://github.com/user-attachments/assets/bf8ee675-6f24-44f6-a512-b36d41cfe59d


