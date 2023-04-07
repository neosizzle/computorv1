#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <unistd.h>
#include <sstream>

#ifndef __MAIN__H__
#define __MAIN__H__

#define RESET "\033[0m"
#define BLACK "\033[30m"			  /* Black */
#define RED "\033[31m"				  /* Red */
#define GREEN "\033[32m"			  /* Green */
#define YELLOW "\033[33m"			  /* Yellow */
#define BLUE "\033[34m"				  /* Blue */
#define MAGENTA "\033[35m"			  /* Magenta */
#define CYAN "\033[36m"				  /* Cyan */
#define WHITE "\033[37m"			  /* White */
#define BOLDBLACK "\033[1m\033[30m"	  /* Bold Black */
#define BOLDRED "\033[1m\033[31m"	  /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m"	  /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m"  /* Bold Yellow */
#define BOLDBLUE "\033[1m\033[34m"	  /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define BOLDCYAN "\033[1m\033[36m"	  /* Bold Cyan */
#define BOLDWHITE "\033[1m\033[37m"	  /* Bold White */

/**
 * @brief Representation of a term
 *
 */
class Term
{
public:
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
public:
	float solution_one;
	float solution_two;
	float imaginary_term;
	float imaginary_coefficient;
	int num_sols;
	bool neg_discriminant;
	bool zero_discriminant;
	int for_degree;
	int all_interger_solution;
};

/**
 * @brief Representation of a dinomial equation
 *
 */
class DinobialEquation
{
public:
	float a;
	float b;
	float c;
};

/** global consts **/
const char VAR_SYMBOL = 'X';
const char EQ_SYMBOL = '=';
const char KARET_SYMBOL = '^';
const std::vector<char> TERM_SYMBOLS = {'^', '*', VAR_SYMBOL};
const std::vector<char> POLY_LINK_SYMBOLS = {'+', '-'};

/**
 * @brief Math utils
 *
 */
float ft_abs(float a, float b);
float ft_sqrt(float x, float guess);
float ft_pow(float a, int power);
Solution evaluate_equation(std::vector<Term> terms);

/**
 * @brief Utils
 *
 */
bool compare_powers(Term one, Term two);
int scount_digit(const char *str);

/**
 * @brief Term operations
 *
 */
char validate_symbols(std::string str);
void extract_terms(std::string str, std::vector<Term> &terms);
void print_terms(std::vector<Term> terms);
void simplify_terms(std::vector<Term> &terms);
int validate_equation(std::vector<Term> terms);
std::string terms_to_str(std::vector<Term> terms);

/**
 * @brief Print functions
 *
 */
void print_solution(Solution sol);
void print_err(std::string message);
void print(std::string message);

void computor(std::string input);
#endif  //!__MAIN__H__
