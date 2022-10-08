#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

/**
 * @brief Representation of a term
 *
 */
class Term
{
	public :
		float constant;
		int power;
		bool is_neg;
};

/**
 * @brief Representation of a solution
 *
 */
class Solution
{
	float solution_one;
	float solution_two;
	int num_sols;
};

/** global consts **/
const char VAR_SYMBOL = 'x';
const char EQ_SYMBOL = '=';
const char KARET_SYMBOL = '^';
const std::vector<char> TERM_SYMBOLS = {'^', '*', VAR_SYMBOL};
const std::vector<char> POLY_LINK_SYMBOLS = {'+', '-'};

/**
 * @brief Utils
 * 
 */
char validate_symbols(std::string str);
void	extract_terms(std::string str);

void computor(std::string input);