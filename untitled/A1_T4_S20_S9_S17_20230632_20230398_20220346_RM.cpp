#include "A1_T4_S20_S9_S17_20230632_20230398_20220346_RM.h"

// Constructor of 'Memory'
Memory::Memory() {
    memory.assign(SIZE, 0);
}

// Set the value of the block with address 'address' to 'value'
void Memory::set_cell(int address, const int &value) {
    if (address < 0 || address >= SIZE) {
        cout << "Address out of range" << endl;
        return;
    }
    memory[address] = value;
}

// Get the value of the block of address 'address'
int Memory::get_cell(int address) {
    if (address < 0 || address >= SIZE)
        cout << "Address out of range" << endl;
    else
        return memory[address];
}

// Constructor of 'Register'
Register::Register() {
    reg.assign(16, 0);
}

// Set the value of the block with address 'address' to 'value'
void Register::set_cell(int address, const int &value) {
    reg[address] = value;
}

// Get the value of the block of address 'address'
int Register::get_cell(int address) {
    return reg[address];
}