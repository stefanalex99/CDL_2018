#include "utils.h"

void increment(std::vector<int> &v, int size) {
    int s = v.size();

    for (int i = 0; i < s; i++) {
        if (v[i] < size) {
            v[i]++;
        }
    }
}

void cmds_read(std::vector<lines> &commands, int &n) {
    lines buff;
    std::cin >> n;

    while (!feof(stdin)) {
        std::cin >> buff.p1;
        std::cin >> buff.p2;
        if (buff.p1 != "snd" && buff.p1 != "rcv") {
            std::cin >> buff.p3;
        }
        commands.push_back(buff);
    }
}

bool check(std::vector<int> v, int size) {
    int n = v.size();
    for (int i = 0; i < n; i++) {
        if (v[i] < size) {
            return true;
        }
    }

    return false;
}

void generate_reg_names(std::vector<std::string> &registers) {
    for (int i = 0; i < NO_REG; i++) {
        registers[i] = "R" + std::to_string(i);
    }
}

void initialize_reg(std::map<std::string, int> &reg,
    std::vector<std::string> registers, int x) {
    for (int i = 1; i < NO_REG; i++) {
        reg[registers[i]] = 0;
    }

    reg["R0"] = x;
}

void print(std::vector<std::string> registers, std::map<std::string, int> reg) {

    for (int i = 0;i < NO_REG; i++) {
        if (reg[registers[i]]) {
            std::cout << reg[registers[i]] << " ";
        }
    }
    std::cout << std::endl;
}
