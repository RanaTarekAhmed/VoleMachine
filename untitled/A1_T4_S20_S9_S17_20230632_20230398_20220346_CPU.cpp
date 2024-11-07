#include "A1_T4_S20_S9_S17_20230632_20230398_20220346_CPU.h"

// Setting the memory of the control unit
void CU::set_memory(Memory* memory1) {
    memory = memory1;
}

// Setting the register of the control unit
void CU::set_register(Register* register1) {
    reg = register1;
}

// Setting the arithmetic logical unit that will be used by the control unit
void CU::set_alu() {
    alu.set_memory(memory);
    alu.set_register(reg);
}

// Execute the instructions given by the user
void CU::execute(int instruction, int address, int xy, int& program_counter) {
    int address_s = (xy - (xy % 10)) / 10, address_t = xy % 10;

    // Instruction 1
    if (instruction == 1) {
        reg->set_cell(address, memory->get_cell(xy));
    }
        // Instruction 2
    else if (instruction == 2) {
        reg->set_cell(address, xy);
    }
        // Instruction 3 and xy = 0
    else if (instruction == 3 && xy == 0) {
        memory->screen.push_back(reg->get_cell(address));
    }
        // Instruction 3 and xy != 0
    else if (instruction == 3) {
        memory->set_cell(xy, reg->get_cell(address));
    }
        // Instruction 4
    else if (instruction == 4) {
        reg->set_cell(address_t, reg->get_cell(address_s));
    }
        // Instruction 5
    else if (instruction == 5) {
        alu.add_2scomp(address_s, address_t, address);
    }
        // Instruction 6
    else if (instruction == 6) {
        alu.add_float(address_s, address_t, address);
    }
        // Instruction 7
    else if (instruction == 7) {
        alu.OR(address_s, address_t, address);
    }
        // Instruction 8
    else if (instruction == 8) {
        alu.AND(address_s, address_t, address);
    }
        // Instruction 9
    else if (instruction == 9) {
        alu.XOR(address_s, address_t, address);
    }
        // Instruction A
     else if (instruction == 10) {
         alu.rotate(address, xy);
     }
        // Instruction B
    else if (instruction == 11 && reg->get_cell(0) == xy){
        program_counter = xy - 1;
    }
        // Instruction C
    else if (instruction == 12) {
        return;
    }
        // Instruction D
    else if (instruction == 13 && reg->get_cell(0) < xy) {
        program_counter = xy - 1;
    }
}


// Constructor of 'CPU;
CPU:: CPU(Memory* memory1, Register* register1)
{
    memory = memory1;
    reg = register1;
    control_unit.set_memory(memory);
    control_unit.set_register(reg);
    control_unit.set_alu();
}

// Fetching the instructions given by the user and them to the memory
void CPU::fetch() {
    for (int i = 0; i < 255; ++i) {
        int instruction = memory->get_cell(i++);
        int xy = memory->get_cell(i);
        control_unit.execute((instruction - (instruction % 10)) / 10, instruction % 10, xy, i);
    }
}
