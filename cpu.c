/*
 *1/11/23 Lela Root cpu.c CPU Emulator
 *CPU C file
 *CPU functions: cpuReset(), cpuDump(), cpuSet(char* reg, int val)
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "cpu.h"
#include "memory.h"
#define regCount 8

struct CPU {

  uint8_t regs[regCount];
  uint8_t PC;
};

static struct CPU cpu;

void cpuDoCycleWork() {
  //move reg values down from RA to RH, RA value is unchanged and old RH value is gone
  for (int r = 1; r < regCount; r++) {
    cpu.regs[r] = cpu.regs[r - 1];
  }

  //fetch byte from memory at PC for new RA value
  bool memDone;
  memStartFetch(cpu.PC, 1, &cpu.regs[0], &memDone);

  //increment PC
  cpu.PC++;
}

void cpuReset() {
  printf("cpuReset\n");
}

void cpuDump() {
  printf("PC: 0x%02X\n")
}

void cpuSet(char* reg, int val) {
  printf("cpuSet reg %s %02X\n", reg, val);
}
