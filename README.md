# stm32l4_getinfo
Reads chip info and core registers<br>
STM32L4xx - read chip info and core registers, output to UART 2 at 115200 8n1<br>
Output should look similar to this:<br>
Connected to UART Two<br>
stm32l475xx/476xx/486xx  Revision 4<br>
ARM Cortex M4 r0p1<br>
Single precision FPU<br>
1024K Flash, 128K RAM (96K SRAM1, 32K SRAM2)<br>
LQFP64<br>
Device Unique ID: 004B0051 5932500A 20343359<br>
Wafer 10 of Lot P2YY34 <br>
Location on wafer: X:81, Y:75<br>
HAL Version: 1.7.2 <br>
BSP Version: 2.0.0 <br>
<br>
Oscillators and clocks<br>
----------------------<br>
            HSE State: Off<br>
            LSE State: Off<br>
            HSI State: On<br>
            LSI State: Off<br>
        SYSCLK Source: PLLCLK<br>
           PLL Source: HSI<br>
                PLL M: /1<br>
                PLL N: *10<br>
                PLL P: /7<br>
                PLL Q: /2<br>
                PLL R: /2<br>
       AHBCLK Divider: /1<br>
      APB1CLK Divider: /1<br>
      APB2CLK Divider: /1<br>
        Flash latency: 4<br>
<br>
Core registers<br>
--------------<br>
           r0: 0x0000000A<br>
           r1: 0x2000033B<br>
           r2: 0x00000000<br>
           r3: 0x12000000<br>
           r4: 0x00000000<br>
           r5: 0x00000000<br>
           r6: 0x00000000<br>
           r7: 0x200000DC<br>
           r8: 0x00000000<br>
           r9: 0x00000000<br>
          r10: 0x00000000<br>
          r11: 0x00000000<br>
          r12: 0x20017100<br>
stack pointer: 0x200170E0<br>
link register: 0x080032B3<br>
<br>
Developed and tested on STM32L476RG-Nucleo<br>
