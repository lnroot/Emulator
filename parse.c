/*
 *1/11/23 Lela Root parse.c CPU Emulator
 *Parse C File
 *Reads in input
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//my files
#include "cpu.h"

#include "memory.h"

#include "clock.h"

//Helper method that parses clock commands and then calls the proper clock methods
int callClock()
{
  char command [7];
  fscanf(stdin, "%s", command);//read in command

  if (strcmp("reset", command) == 0)
    {
      clockReset();
      
    } else if(strcmp("tick", command) == 0)
    {
        int numTicks;
        fscanf(stdin, "%d", &numTicks);
        clockTick(numTicks);
      
    } else if(strcmp("dump", command) == 0)
    {	
        clockDump();
	
    } else
    {	    
	printf("error -- unknown command");
	    
    }
  return 0;
}

//Helper method that parses CPU commands and calls CPU methods
int callCpu()
{
  char command [7];
  fscanf(stdin, "%s", command);//read in command

  if (strcmp("reset", command) == 0)
    {
      cpuReset();
      
    } else if(strcmp("set", command) == 0)
    {
        char reg[3];
	int val;
        fscanf(stdin, "%*s %s %x", reg, &val);
	cpuSet(reg, val);
	
    } else if(strcmp("dump", command) == 0)
    {
        cpuDump();
	
    } else
    {
      printf("error -- unknown command");
      
    }

  return 0;
}

//Helper method that parses memory commands and calls memory methods
int callMemory()
{
  char command [7];
  fscanf(stdin, "%s", command);//read in command

  if (strcmp("create", command) == 0)
    {
      int size;
      fscanf(stdin, "%x", &size);
      memCreate(size);
      
    } else if(strcmp("reset", command) == 0)
    {
      memReset();
      
    } else if(strcmp("dump", command) == 0)
    {
      int address;
      int count;
      fscanf(stdin, "%x %x", &address, &count);
      memDump(address, count);
      
    } else if(strcmp("set", command) == 0)
    {
      int address;
      int count;

      fscanf(stdin, "%x %x", &address, &count);

      int bytes [count];

      //add the bytes to a temporary array of size count
      for (int i = 0; i < count; i++)
	{
	  fscanf(stdin, "%x", &bytes[i]);
	  
	}

      memSet(address, count, bytes);
      
    } else
    {
      printf("error -- unknown command");
      
    }

  return 0;
}

int main()
{
  char device [7];

  while( fscanf(stdin, "%s", device) > 0) {//read in device
  
    if(strcmp("clock", device) == 0)
      {
	callClock();
      
      } else if(strcmp("cpu", device) == 0)
      {
	callCpu();
      
      } else if(strcmp("memory", device) == 0)
      {
	callMemory();
      
      } else
      {
	printf("error - unknown device");

      }
  }

}
