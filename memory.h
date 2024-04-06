/*
 *1/11/23 Lela Root memory.h CPU Emulator
 *Memory header file
 *Memory functions: memCreate(int size), memSet(int address, int count, int *values), memReset(), memDump(int address, int count)
 */

#include <stdlib.h>
#include <stdio.h>


void memSet(int address, int count, int *values);

void memCreate(int size);

void memReset();

void memDump(int address, int count);

