****Unfinished WIP****

C program that emulates a CPU

Current functionality: 
parse.c properly parses the input and distributes it to each corresponding component file, where the input is printed back to stdout

Each component operates and takes input as follows:

-----------------------------Clock----------------------------------
The clock device is the heart of the system, providing synchronization between all other devices. On
command, it provides a “tick pulse” to all other devices that need a clock. For diagnostic purposes, the
clock will maintain a monotonically increasing unsigned 16 bit count that can be displayed.

Clock commands:

reset
The reset command sets the internal counter to zero. Example: “clock reset”.
tick <decimal integer>
The tick command accepts a positive decimal integer indicating how many clock ticks should be
issued to attached devices. The internal counter is incremented by the specified number of ticks.

dump
The dump command shows “Clock: “ followed by the value of the internal clock in decimal.
Example: “clock dump” might show:
Clock: 148


-------------------------------Memory--------------------------------
The memory device provides storage for the system. Prior to use, it must be created with the “create”
command, which specifies the size in bytes. At that point, memory is in an undefined condition. The
“reset” command is used to initialize all of memory to zeros. The contents of memory can be displayed
via the “dump” command, and assigned with the “set” command.

Memory commands:

create <size in hex bytes>
The “create” command accepts a single integer parameter which indicates the size of the
memory in bytes. Example: “memory create 0x10000”.

reset
The “reset” command causes all of the allocated memory to be set to zero. Example: “memory
reset”.

dump <hex address> <hex count>
The dump command shows the contents of memory starting at address <address>, and
continuing for <count> bytes. The output should begin with a header showing “Addr”, 1 space,
and then 00-0F with a single space between each. Subsequent lines are formatted such that
each line begins with a 1 byte address (0x and 2 digit upper case hex characters) that is an even
multiple of 16, followed by a single space. Following that, up to 16 bytes of data, in 2 digit upper
case hex is printed. If the address is not a multiple of 16, blank spaces should be printed until
the address is reached. Example: “memory dump 0x04 0x20”
Addr 00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F
0x00 11 44 23 93 50 22 AE DE AD BE EF FF
0x10 AE DE AD C0 DE FA CE FE ED CA FE BE EF 30 A8 EE
0x20 55 AA 10 20

set <hex address> <hex count> <hex byte 1> <hex byte 2> … <hex byte N>
The set commands initializes memory to a user supplied set of values. The “hex address”
specifies where to begin setting memory values, “hex count” is how many bytes will be assigned,
and is followed by “hex count” number of hex bytes, separated by a single space. For this
assignment, the command will never be used with more than 100 hex bytes. Example: “memory
set 0x10 0x05 0x08 0xDE 0xAD 0xBE 0xEF”


----------------------------------CPU-------------------------------------------
This simple CPU device has 8 one byte data registers labeled RA through RH. The CPU also has a 1 byte
program counter (PC) register that holds the address in memory of the next CPU instruction to fetch. For
this assignment, CPU “instructions” will simply be 1 byte of data. On each clock cycle, the CPU will shift
the contents of each register to the next higher register, such that RH receives the content of RG, RG
receives what is in RF, and so on, until finally, RB receives RA. The CPU will then fetch the byte from the
Memory Device pointed to by the PC, place it into RA, and increment the PC by 1. While the CPU doesn’t
do anything useful, this behavior is a means to test the I/O & memory fetch capabilities of the code.

CPU commands:

reset
The “reset” command causes all CPU registers (including PC) to be zero. Example: “cpu reset”.

set reg <reg> <hex byte>
The “set reg” command sets the value of the specified CPU register. The “reg” parameter can be
the value RA-RH, or PC for the program counter. Example: “cpu set reg RE 0xAA”.

dump
The “dump” command shows the value of all of the CPU registers. A sample output would be as
follows:
PC: 0xAA
RA: 0x23
RB: 0x14
RC: 0xFF
RD: 0x44
RE: 0xAA
RF: 0x00
RG: 0x09
RH: 0x18
