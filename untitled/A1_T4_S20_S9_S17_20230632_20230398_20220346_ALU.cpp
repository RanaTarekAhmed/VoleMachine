#include "A1_T4_S20_S9_S17_20230632_20230398_20220346_ALU.h"

// Setting the memory
void ALU::set_memory(Memory *memory1) {
    memory = memory1;
}

// Setting the register
void ALU::set_register(Register *register1) {
    reg = register1;
}

// Hexadecimal form to floating point form
float ALU::hexa_to_float(uint32_t hexa) {
    float result;
    std::memcpy(&result, &hexa, sizeof(result));
    return result;
}

// Floating point form to hexadecimal form
uint32_t ALU::float_to_hexa(float float_value) {
    uint32_t result;
    std::memcpy(&result, &float_value, sizeof(result));
    return result;
}

// Add floating point values located in address_s and address_t and place the result in the register of address 'address'.
void ALU::add_float(int address_s, int address_t, int address) {
    float s = hexa_to_float(memory->get_cell(address_s));
    float t = hexa_to_float(memory->get_cell(address_t));
    float result = s + t;
    reg->set_cell(address, float_to_hexa(result));
}

// Add two's complement values located in address_s and address_t and place the result in the register of address 'address'.
void ALU::add_2scomp(int address_s, int address_t, int address) {
    int32_t s = static_cast<int32_t>(memory->get_cell(address_s));
    int32_t t = static_cast<int32_t>(memory->get_cell(address_t));
    int32_t result = s + t;
    reg->set_cell(address, static_cast<uint32_t>(result));
}

// OR the values located in address_s and address_t and place the result in the register of address 'address'.
void ALU::OR(int address_s, int address_t, int address) {
    uint32_t s = memory->get_cell(address_s);
    uint32_t t = memory->get_cell(address_t);
    uint32_t result = s | t;
    reg->set_cell(address, result);
}

// AND the values located in address_s and address_t and place the result in the register of address 'address'.
void ALU::AND(int address_s, int address_t, int address) {
    uint32_t s = memory->get_cell(address_s);
    uint32_t t = memory->get_cell(address_t);
    uint32_t result = s & t;
    reg->set_cell(address, result);
}

// XOR the values located in address_s and address_t and place the result in the register of address 'address'.
void ALU::XOR(int address_s, int address_t, int address) {
    uint32_t s = memory->get_cell(address_s);
    uint32_t t = memory->get_cell(address_t);
    uint32_t result = s ^ t;
    reg->set_cell(address, result);
}

// Rotate the bit pattern in register R x bits to the right
void ALU::rotate(int address, int rotations) {
    rotations %= 32;
    int value = reg->get_cell(address);
    int result = (value >> rotations) | (rotations << (32 - rotations));
    reg->set_cell(address, result);
}

