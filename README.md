# PIC18F2525 with with character 20x4 LCD display

----
## Low level trials with pic18f2525 and adc/dac spi peripherals
> IDE MPLAB X IDE 5.05
> Compiler XC8 v2.00

> Use of legacy Microchip's peripheral libraries "plib"  with remarks:

- as for LCD -> changed ports assignments, means the libraries have to be re-located as follows:
  - header file "xlcd.h" moved and included as a local project's  header files, modified respectively
  - source files moved and included as a local project's files , so they are being recompiled

- plib concept used also for spi communications 
  - My git repo for plib archive (while I was still able to find them on Microchip's website):
[plib](https://github.com/neykovsimeon/pic18_plib_legacy.git) 

 - Very helpful "Getting started" tutorial for MPLAB X IDE and XC8:
 [Refrence - YouTube channel StudentCompanion](https://www.youtube.com/watch?v=mUofSucHx_E&list=PL3lfkED2i6JcJH-OETxsI43e8M-7eLeL-)
 
 - Very useful tutorial for microcontrollers lcd menu
 [Reference - YouTube channel projectsHigaski, LCD menu tutorial for microcontrollers](https://www.youtube.com/watch?v=PFzNBtnfJ6Y&list=PLfGDzGG5F5eYNBkXs0tTdXqLB3KE5CFgx) 

> use of Universal Programmer MiniPro TL866A. Fuses config comes directly with hex file as per #pragma config statements in respective header file