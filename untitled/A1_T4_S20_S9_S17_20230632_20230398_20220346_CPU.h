#ifndef UNTITLED_A1_T4_S20_S9_S17_20230632_20230398_20220346_CPU_H
#define UNTITLED_A1_T4_S20_S9_S17_20230632_20230398_20220346_CPU_H

#include "A1_T4_S20_S9_S17_20230632_20230398_20220346_RM.h"
#include "A1_T4_S20_S9_S17_20230632_20230398_20220346_ALU.h"
class CU {
    Memory* memory;
    Register* reg;
    ALU alu;
public:
    void set_memory(Memory* memory1);
    void set_register(Register* register1);
    void set_alu();
    void execute(int instruction, int address, int xy, int& program_counter);
};


class CPU {
    Memory* memory;
    Register* reg;
    CU control_unit;
public:
    CPU(Memory* memory1, Register* register1);
    void fetch();
};

#endif //UNTITLED_A1_T4_S20_S9_S17_20230632_20230398_20220346_CPU_H
