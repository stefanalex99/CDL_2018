#include "commands.h"

/*
 *  Runs one command for a single processor
 *
 *  @it (int) the current position iterrator through commands
 *
 *  @commands (std::vector<lines>) the commands vector
 *
 *  @reg (std::map<std::string,int>) the map in which we store the values
 *  of the registers of a single processor
 *
 *  @sndto0 (std::queue<int>) the queue of the values to be recieved
 *
 *  @sndto1 (std::queue<int>) the queue of the values to be sent
 */
void proc_run(int &it, std::vector<lines> commands,
    std::vector<std::string> registers, std::map<std::string,int> &reg,
    std::queue<int> &sndto0, std::queue<int> &sndto1);

/*
 *  Executes all the commands for all the processors
 *
 *  @commands (std::vector<lines>) the commands vector
 *
 *  @registers (std::vector<std::string>) the vector in which the names of the
 *  registers are stored
 *
 *  @reg (std::map<std::string,int>) the map in which we store the values
 *  of the registers of a single processor
 */
void cmds_execute(std::vector<lines> commands,
    std::vector<std::string> registers,
    std::vector<std::map<std::string, int> > &regs);

/*
 *  Generates and prints the results
 */
void gen_result();
