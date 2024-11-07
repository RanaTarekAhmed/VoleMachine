#ifndef UNTITLED_A1_T4_S20_S9_S17_20230632_20230398_20220346_ALU_H
#define UNTITLED_A1_T4_S20_S9_S17_20230632_20230398_20220346_ALU_H

#include "A1_T4_S20_S9_S17_20230632_20230398_20220346_RM.h"

class ALU {
    Memory *memory;
    Register *reg;
public:
    void set_memory(Memory* memory1);
    void set_register(Register* register1);

    float hexa_to_float(uint32_t hexa);
    uint32_t float_to_hexa(float float_value);

    void add_float(int address_s, int address_t, int address);
    void add_2scomp(int address_s, int address_t, int address);

    void OR(int address_s, int address_t, int address);
    void AND(int address_s, int address_t, int address);
    void XOR(int address_s, int address_t, int address);
    void rotate(int address, int rotations);
};


#endif //UNTITLED_A1_T4_S20_S9_S17_20230632_20230398_20220346_ALU_H
