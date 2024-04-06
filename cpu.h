/*
 *1/11/23 Lela Root cpu.h Emulator
 *CPU header file
 *CPU functions: cpuReset(), cpuSet(char* reg, int val), cpuDump() 
 */

#include <stdlib.h>
#include <stdio.h>

/*struct CPU {
  uint8_t regs[8]; //registers
  uint8_t PC; //Program Counter

  }*/

void cpuDoCycleWork();
  
void cpuReset();

void cpuDump();

void cpuSet(char* reg, int val);

