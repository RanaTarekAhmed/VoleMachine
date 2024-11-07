#ifndef UNTITLED_A1_T4_S20_S9_S17_20230632_20230398_20220346_RM_H
#define UNTITLED_A1_T4_S20_S9_S17_20230632_20230398_20220346_RM_H
#include <bits/stdc++.h>
using namespace std;

class Memory {
    int SIZE = 256;
    vector<uint32_t> memory;
public:
    vector<uint32_t> screen;
    Memory();
    void set_cell(int address, const int &value);
    int get_cell(int address);
};


class Register {
    vector<uint32_t> reg;
public:
    Register();
    void set_cell(int address, const int &value);
    int get_cell(int address);
};
#endif //UNTITLED_A1_T4_S20_S9_S17_20230632_20230398_20220346_RM_H
