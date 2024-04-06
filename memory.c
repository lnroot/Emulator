/*
 *Lela Root 1/11/23 memory.c CPU Emulator
 *Memory C file
 *Memory functions: memCreate(int size), memReset(), memSet(int address, int count, int *values), memDump(int address, int count)
 */
#include <stdio.h>
#include <stdlib.h>

#include "memory.h"

void memCreate(int size) {
  printf("memCreate %02X\n", size);
}

void memReset() {
  printf("memReset\n");
}

void memDump(int address, int count) {
  printf("memDump %02X %02X\n", address, count);
}

void memSet(int address, int count, int *values) {
  printf("memSet %02X %02X\n", address, count);
  
  for (int i = 0; i < count; i++) {
    printf("%02X ", values[i]);
  }
  printf("\n");
}
