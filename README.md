# System Control Program With MBED
### The program is written for the [mbed NXP LPC1768](https://os.mbed.com/platforms/mbed-LPC1768/) and is suitable for [mbed-enabled boards](https://os.mbed.com/platforms/).

This is a basic system control program featuring safety and status indicators. I created it for educational purposes.

## Functionalities
### Inputs
- The Start button starts the system.
- The Stop button stops the system, but the system is paused. Once the button is released, the system continues to run.
- The Guard switch prevents the system from running.
- The High-temperature switch also prevents the system from running.

### Outputs
- The Yellow LED (READY) indicates the system's status. If it is lit, the system is ready to run; if it is flashing, the system is running. If it is off, the system is busy.
- The Blue LED (RUNNING) indicates that the system is running.
- The Red LED (GUARD) indicates the status of the guard switch.
- The Red LED (HIGH TEMPERATURE) indicates that the system is overheated.

## How to Run
You can buy an mbed-enabled board, or you can use the [mbed simulator](https://os.mbed.com/blog/entry/introducing-mbed-simulator/).
If you prefer using a board, you must use [mbed Studio](https://os.mbed.com/studio/) or [Keil Studio](https://studio.keil.arm.com/).

![mbed simulator](mbed_simulator.png)

***Resources***
- [The Definitive Guide to the ARM Cortex-M3](https://www.amazon.com/Definitive-Guide-Cortex-M3-Embedded-Technology/dp/0750685344)
- [Fast and Effective Embedded Systems Design: Applying the ARM mbed](https://www.amazon.com/Fast-Effective-Embedded-Systems-Design/dp/0080977685)
- [The ANSI C Programming Language by Brian W. Kernighan & Dennis M. Ritchie]()
