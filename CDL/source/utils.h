#include <iostream>
#include <vector>
#include <string>
#include <map>

#define NO_REG 32

/*
 * Each command has 2 or 3 parameters
 */
struct lines{
    std::string p1, p2, p3;
};

/**
 *  Reads the input from standard input
 *
 *  @v (std::vector<lines>commands) the vector of comands which are delimited
 *  by lines
 *
 *  @n (int) the number of processors
 */
void cmds_read(std::vector<lines> &commands, int &n);

/**
 *  Increments every element in a vector of ints that is smaller than a specific
 *  number (size)
 *
 *  @v (std::vector<int>) the vector which we are about to increment
 *
 *  @size (int) the reference number
 */
void increment(std::vector<int> &v, int size);

/*
 *  Checks if a vector has at least one element smaller than number (size)
 *
 *  @v (std::vector<int>) the vector through which we search
 *
 *  @size (int) the size we check
 */
bool check(std::vector<int> v, int size);

/*
 *  A function that generates the strings Ri (i = 0 : 31) which we use for the
 *  dictionary
 *
 *  @registers (std::vector<std::string>) the vector in which we save the strings
 */
void generate_reg_names(std::vector<std::string> &registers);

/*
 *  The registers have the default value of 0 with the exception of R0
 *  which has the value of the number of the its processor
 *
 *  @reg (std::map<std::string, int>) the dictionary which has a string
 *  generated with generate_reg_names() as the key and the value a ints
 *
 *  @registers (std::vector<std::string>) the string that contains the names
 *  of the registers
 *
 *  @x (int) the value that we assign to the R0 register
 */
void initialize_reg(std::map<std::string, int> &reg,
    std::vector<std::string> registers, int x);

/*
 *  Prints the output in the requested format
 *
 *  @registers (std::vector<std::string>) the string that contains the names
 *  of the registers
 *
 *  @reg (std::map<std::string, int>) the map in which the registers and their
 *  values are stored
 */
void print(std::vector<std::string> registers, std::map<std::string, int> reg);
