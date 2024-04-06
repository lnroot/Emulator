/*
 *Lela Root 1/11/23 clock.c CPU Emulator
 *C file for the clock device
 *Methods: clockTick(int ticks), clockReset(), clockDump()
 */
#include <stdio.h>
#include <stdlib.h>

#include "clock.h"
#include "cpu.h"

static unsigned ticks;

void clockReset() {
  ticks = 0;
}

void clockDump() {
  printf("Clock: %d\n\n", ticks);
}

void clockTick(int inputTicks) {
  for (unsigned i = 0; i < inputTicks; i++) {
    cpuDoCycleWork();
    ticks++;
  }
}
