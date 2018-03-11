#include "utils.h"
#include <queue>
#include <limits.h>
#include <algorithm>

/*
 *  Sets the value of a certain register to a certain one
 *
 *  @reg (std::map<std::string, int>) the map in which we store the values
 *  of the registers of a single processor
 *
 *  x (std::string) the key of the value to be changed
 *
 *  y (int) the value
 */
void set(std::map<std::string, int> &reg, std::string x, int y);

/*
 *  Adds a number to a certain value of a certain register
 *
 *  @reg (std::map<std::string, int>) the map in which we store the values
 *  of the registers of a single processor
 *
 *  x (std::string) the key of the value to be changed
 *
 *  y (int) the value
 */
void add(std::map<std::string, int> &reg, std::string x, int y);

/*
 *  Multiplies the value of a certain register by a certain value
 *
 *  @reg (std::map<std::string, int>) the map in which we store the values
 *  of the registers of a single processor
 *
 *  x (std::string) the key of the value to be changed
 *
 *  y (int) the value
 */
void mul(std::map<std::string, int> &reg, std::string x, int y);

/*
 *  Calculates the value of a certain register mod another value
 *
 *  @reg (std::map<std::string, int>) the map in which we store the values
 *  of the registers of a single processor
 *
 *  x (std::string) the key of the value to be changed
 *
 *  y (int) the value
 */
void mod(std::map<std::string, int> &reg, std::string x, int y);

/*
 *  Executes a conditioned jump through the commands
 *
 *  @registers (std::vector<std::string>) the vector in which the names of the
 *  registers are stored
 *
 *  @it (int) the iterrator through the commands
 *
 *  @commands (std::vector<lines>) the commands vector
 *
 *  @reg (std::map<std::string,int>) the map in which we store the values
 *  of the registers of a single processor
 */
void jgz(std::vector<std::string> registers, int &it,
    std::vector<lines> commands, std::map<std::string,int> &reg);
