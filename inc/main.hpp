#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <unistd.h>

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
	public :
		float solution_one;
		float solution_two;
		float imaginary_term;
		float imaginary_coefficient;
		int num_sols;
		bool neg_discriminant;
		int for_degree;
};

/**
 * @brief Representation of a dinomial equation
 *
 */
class DinobialEquation
{
	public :
		float a;
		float b;
		float c;
};


/** global consts **/
const char VAR_SYMBOL = 'x';
const char EQ_SYMBOL = '=';
const char KARET_SYMBOL = '^';
const std::vector<char> TERM_SYMBOLS = {'^', '*', VAR_SYMBOL};
const std::vector<char> POLY_LINK_SYMBOLS = {'+', '-'};


/**
 * @brief Math utils
 * 
 */
int ft_abs(int a, int b);
float ft_sqrt(float x, float guess);
float ft_pow(float a, int power);
Solution evaluate_equation(std::vector<Term> terms);

/**
 * @brief Utils
 * 
 */
bool compare_powers(Term one, Term two);
int count_digit(int number);

/**
 * @brief Term operations
 * 
 */
char validate_symbols(std::string str);
void	extract_terms(std::string str, std::vector<Term> &terms);
void	print_terms(std::vector<Term> terms);
void simplify_terms(std::vector<Term> &terms);
int	validate_equation(std::vector<Term> terms);

/**
 * @brief Print functions
 * 
 */
void print_solution(Solution sol);

void computor(std::string input);