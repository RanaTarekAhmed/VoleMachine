#include "A1_T4_S20_S9_S17_20230632_20230398_20220346_RM.h"
#include "A1_T4_S20_S9_S17_20230632_20230398_20220346_CPU.h"

using namespace std;

class Machine {
    Memory* memory;
    Register* reg;
    CPU cpu;

public:
    // Constructor of 'Machine;
    Machine(Memory* memory_ptr, Register* reg_ptr, CPU& cpu_obj)
            : memory(memory_ptr), reg(reg_ptr), cpu(cpu_obj) {}

    // Loads a program from a file into memory
    void load_program() {
        string filepath;
        cout << "Enter the full path of the instructions file:\n";
        cin >> filepath;
        cout << "Loading program file..." << endl;
        ifstream file(filepath, ios::in);
        if (!file.is_open()) {
            cerr << "Error: Could not open the program file." << endl;
            return;
        }

        string instruction;
        int address = 0;
        while (file >> instruction) {
            // Divide instruction into opcode and operand parts
            memory->set_cell(address++, stoi(instruction.substr(0, 2), nullptr, 16));  // opcode
            memory->set_cell(address++, stoi(instruction.substr(2), nullptr, 16));          // operand
        }
        cout << "Program file loaded successfully!" << endl;
        cpu.fetch();
    }

    // Displays the current state of the memory and the register
    void display_memory_state() {
        cout << "Outputting current state of the machine..." << endl;
        cout << "Memory contents" << endl;

        for (int i = 0; i < 16; ++i) {
            for (int j = 0; j < 16; ++j) {
                cout << setw(2) << setfill('0') << hex << memory->get_cell((i * 16) + j) << "  ";
            }
            cout << endl;
        }
        cout << "\n\nRegister content:\n";
        for (int i = 0; i < 16; i++) {
            cout << setw(2) << setfill('0') << hex << reg->get_cell(i) << "  ";
        }

        cout << "\n\nScreen:\n";
        for (int i = 0; i < memory->screen.size(); ++i) {
            cout << setw(2) << setfill('0') << hex << memory->screen[i] << "  ";
        }
        cout << endl;
    }
};

class Main_UI {
    Machine& machine;

public:
    // Constructor for Main_UI
    Main_UI(Machine& machine_ref) : machine(machine_ref) {}

    // Displays the menu and processes user choices
    void displayMenu() {
        string choice;
        do {
            cout << "\n--- Machine Menu ---" << endl;
            cout << "1. Load Program" << endl;
            cout << "2. Display memory, register and screen" << endl;
            cout << "3. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice == "1")
                machine.load_program();
            else if (choice == "2")
                machine.display_memory_state();
            else if (choice == "3") {
                cout << "Exiting program..." << endl;
                break;
            }
            else
                cout << "Invalid choice! Please try again." << endl;
        } while (choice != "3");
    }
};

int main() {
    // Initialize components
    Memory memory;
    Register reg;
    CPU cpu(&memory, &reg);

    // Create Machine and Main_UI objects
    Machine machine(&memory, &reg, cpu);
    Main_UI ui(machine);

    // Run the menu
    ui.displayMenu();
    return 0;
}
