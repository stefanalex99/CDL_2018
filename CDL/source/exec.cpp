#include "exec.h"

void proc_run(int &it, std::vector<lines> commands,
    std::vector<std::string> registers, std::map<std::string,int> &reg,
    std::queue<int> &sndto0, std::queue<int> &sndto1) {

    if (commands[it].p1 == "set") {
        if (std::find(registers.begin(), registers.end(), commands[it].p3)
        != registers.end()) {
            set(reg, commands[it].p2, reg[commands[it].p3]);
        } else {
            set(reg, commands[it].p2, std::stoi(commands[it].p3));
        }
    } else if (commands[it].p1 == "add") {
        if (std::find(registers.begin(), registers.end(), commands[it].p3)
        != registers.end()) {
            add(reg, commands[it].p2, reg[commands[it].p3]);
        } else {
            add(reg, commands[it].p2, std::stoi(commands[it].p3));
        }
    } else if (commands[it].p1 == "mul") {
        if (std::find(registers.begin(), registers.end(), commands[it].p3)
        != registers.end()) {
            mul(reg, commands[it].p2, reg[commands[it].p3]);
        } else {
            mul(reg, commands[it].p2, std::stoi(commands[it].p3));
        }
    } else if (commands[it].p1 == "mod") {
        if (std::find(registers.begin(), registers.end(), commands[it].p3)
        != registers.end()) {
            mod(reg, commands[it].p2, reg[commands[it].p3]);
        } else {
            mod(reg, commands[it].p2, std::stoi(commands[it].p3));
        }
    } else if (commands[it].p1 == "jgz") {
        jgz(registers, it, commands, reg);
    } else if (commands[it].p1 == "snd") {
        if (std::find(registers.begin(), registers.end(), commands[it].p2)
        != registers.end()) {
            sndto1.push(reg[commands[it].p2]);
        } else {
            sndto1.push(std::stoi(commands[it].p2));
        }
    } else if (commands[it].p1 == "rcv") {
        if (!sndto0.empty()) {
            reg[commands[it].p2] = sndto0.front();
            sndto0.pop();
        }
    }
}

void cmds_execute(std::vector<lines> commands,
    std::vector<std::string> registers,
    std::vector<std::map<std::string, int> > &regs) {

    int size = commands.size();
    int N = regs.size();
    std::vector<std::queue<int> > sndto(N);
    std::vector<int> iters(N, 0);

    for (; check(iters, size); increment(iters, size)) {
        for (int i = 0; i < N - 1; i++) {
            if (commands[iters[i]].p1 == "rcv") {
                if (sndto[i].empty()) {
                    return;
                }
            }
            proc_run(iters[i], commands, registers, regs[i], sndto[i],
            sndto[i + 1]);
        }

        if (commands[iters[N - 1]].p1 == "rcv") {
            if (sndto[N - 1].empty()) {
                return;
            }
        }

        proc_run(iters[N - 1], commands, registers, regs[N - 1], sndto[N - 1],
        sndto[0]);
    }
}

void gen_result() {
    std::vector<lines> commands;
    int N;
    cmds_read(commands, N);

    std::vector<std::map<std::string, int> > regs(N);

    std::vector<std::string> registers(NO_REG);

    generate_reg_names(registers);

    for (int i = 0; i < N; i++) {
        initialize_reg(regs[i], registers, i);
    }

    cmds_execute(commands, registers, regs);

    for (int i = 0; i < N; i++) {
        print(registers, regs[i]);
    }
}
