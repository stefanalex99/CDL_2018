#include "commands.h"

void set(std::map<std::string, int> &reg, std::string x, int y) {
    reg[x] = y;
}

void add(std::map<std::string, int> &reg, std::string x, int y) {
    if (reg[x] + y > INT_MAX) {
        reg[x] = INT_MIN;
    } else {
        reg[x] += y;
    }
}

void mul(std::map<std::string, int> &reg, std::string x, int y) {
    if (reg[x] * y > INT_MAX) {
        reg[x] = INT_MIN;
    } else if (reg[x] * y < INT_MIN) {
        reg[x] = INT_MIN;
    } else {
        reg[x] *= y;
    }
}

void mod(std::map<std::string, int> &reg, std::string x, int y) {
    reg[x] %= y;
}

void jgz(std::vector<std::string> registers, int &it,
    std::vector<lines> commands, std::map<std::string,int> &reg) {

    if (std::find(registers.begin(), registers.end(), commands[it].p2)
    != registers.end()) {
        if (reg[commands[it].p2] > 0) {
            if (std::find(registers.begin(), registers.end(),
            commands[it].p3) != registers.end()) {
                it += reg[commands[it].p3] - 1;
            } else {
                it += std::stoi(commands[it].p3) - 1;
            }
        }
    } else {
        if (std::stoi(commands[it].p2) > 0) {
            if (std::find(registers.begin(), registers.end(),
            commands[it].p3) != registers.end()) {
                it += reg[commands[it].p3] - 1;
            } else {
                it += std::stoi(commands[it].p3) - 1;
            }
        }
    }
}
