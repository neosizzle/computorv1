#include "main.hpp"

/**
 * @brief Compares two terms by their powers
 *
 */
bool compare_powers(Term one, Term two)
{
	return one.power > two.power;
}

/**
 * @brief Prints out terms in a polynomial standard
 *
 * @param terms
 */
void print_terms(std::vector<Term> terms)
{
	for (std::vector<Term>::iterator iter = terms.begin(); iter != terms.end(); ++iter)
	{
		const Term curr_term = *iter;

		// decide wether to print + or not for positive terms
		if (curr_term.is_neg)
			std::cout << '-';
		else if (iter != terms.begin())
			std::cout << '+';

		// print constant
		if (curr_term.constant == 0)
		{
			std::cout << '0';
			continue;
		}
		std::cout << curr_term.constant;

		// print variable
		std::cout << VAR_SYMBOL;

		// print power
		std::cout << KARET_SYMBOL << curr_term.power;
	}
	std::cout << "\n";
}

/**
 * @brief Parses term string into term struct
 *
 * @param term_str
 * @return Term
 */
Term parse_term(std::string term_str)
{
	Term res;
	int read_idx;
	int constant;
	int power;
	int is_neg;
	int const_is_var;

	read_idx = 0;
	const_is_var = 0;
	power = 0;
	is_neg = false;

	// look for '-'
	if (term_str[read_idx] == '-')
	{
		is_neg = true;
		++read_idx;
	}

	// look for '+'
	if (term_str[read_idx] == '+')
		++read_idx;

	// obtain constant value
	if (term_str[read_idx] == VAR_SYMBOL)
	{
		constant = 1;
		const_is_var = 1;
	}
	else
		constant = atoi(term_str.c_str() + read_idx);

	// increm read idx
	read_idx += count_digit(constant);

	// if '*' is found, increm read index so it points to variable
	if (term_str[read_idx] == '*')
		++read_idx;

	// if a karet is found, record power
	if (term_str[read_idx + 1] == '^')
		power = atoi(term_str.c_str() + (read_idx + 2));
	// case where const is the variable itself
	else if (const_is_var)
	{
		power = atoi(term_str.c_str() + (read_idx + 1));
		if (!power)
			++power;
	}
	// case wherer const(variable)
	else if (term_str[read_idx] == VAR_SYMBOL)
		power = 1;
	else
		power = 0;

	res.is_neg = is_neg;
	res.power = power;
	res.constant = constant;
	return res;
}

/**
 * @brief Check if current term is a valid term before passing it to parser
 *
 * @param term_str term to validate
 * @return int 1 if not valid, 0 otherwise
 */
int validate_term(std::string term_str)
{
	// check for sole '+' and '-'
	if (term_str == "+" || term_str == "-")
		return 1;

	// can only have 1 or 0 '*'
	if (std::count(term_str.begin(), term_str.end(), '*') > 1)
		return 1;

	const int MULT_IDX = term_str.find('*');

	if (MULT_IDX != std::string::npos)
	{

		// '*' must not be first or last char
		if (MULT_IDX == 0 || MULT_IDX == term_str.length() - 1)
			return 1;

		// '*' must be followed by the variable and must be predeceased by constant
		if (term_str[MULT_IDX + 1] != VAR_SYMBOL)
			return 1;

		if (!isdigit(term_str[MULT_IDX - 1]))
			return 1;
	}

	const int VAR_IDX = term_str.find(VAR_SYMBOL);
	if (VAR_IDX != std::string::npos)
	{
		// 'x' must not be followed by the variable and must only be predeceased by '^'
		if (VAR_IDX == term_str.length() - 2 && term_str[VAR_IDX + 1] != '^')
			return 1;

		if (VAR_IDX > 0 && term_str[VAR_IDX - 1] == VAR_SYMBOL)
			return 1;
	}

	const int KARET_IDX = term_str.find(KARET_SYMBOL);
	if (KARET_IDX != std::string::npos)
	{
		// '^' must be followed by a variable
		if (term_str[KARET_IDX - 1] != VAR_SYMBOL)
			return 1;

		// after '^' must have digit
		if (!isdigit(term_str[KARET_IDX + 1]))
			return 1;

		// power must be less than 3 and more than -1
		const int power = atoi(term_str.c_str() + KARET_IDX + 1);
		if (power > 2 || power < 0)
			return 1;
	}

	return 0;
}

// moves rhs terms to lhs individually
void group_terms(std::vector<Term> &lhs, std::vector<Term> &rhs)
{

	for (std::vector<Term>::iterator rhs_iter = rhs.begin(); rhs_iter != rhs.end(); ++rhs_iter)
	{
		Term curr;

		curr = *rhs_iter;
		curr.is_neg = !curr.is_neg;
		lhs.push_back(curr);
	}
}

// extract terms and simplify
void extract_terms(std::string str, std::vector<Term> &terms)
{
	int read_start;
	int read_end;
	std::string curr_term_str;
	char curr;

	read_start = 0;
	read_end = 1;

	// read until '=' is found (LHS)
	while (str[read_start] != EQ_SYMBOL)
	{
		read_end = read_start + 1;

		while (read_end < str.length())
		{
			curr = str[read_end];
			if (std::find(POLY_LINK_SYMBOLS.begin(), POLY_LINK_SYMBOLS.end(), curr) != POLY_LINK_SYMBOLS.end() || curr == EQ_SYMBOL)
			{
				curr_term_str = str.substr(read_start, read_end - read_start);
				// return 1 here
				if (validate_term(curr_term_str))
				{
					std::cout << "bad token |" << curr_term_str << "|\n";
					exit(1);
				}

				// push to term array
				const Term term = parse_term(curr_term_str);
				terms.push_back(term);
				break;
			}
			++read_end;
		}
		read_start = read_end;
	}

	// read until end of string (RHS)
	++read_start;
	std::vector<Term> rhs_terms;
	while (str[read_start] != 0)
	{
		read_end = read_start + 1;

		while (read_end < str.length() + 1)
		{
			curr = str[read_end];
			if (std::find(POLY_LINK_SYMBOLS.begin(), POLY_LINK_SYMBOLS.end(), curr) != POLY_LINK_SYMBOLS.end() || curr == 0)
			{
				curr_term_str = str.substr(read_start, read_end - read_start);
				// return 1 here
				if (validate_term(curr_term_str))
				{
					std::cout << "bad token |" << curr_term_str << "|\n";
					exit(1);
				}

				// push to term array
				const Term term = parse_term(curr_term_str);
				rhs_terms.push_back(term);
				break;
			}
			++read_end;
		}
		read_start = read_end;
	}

	// move rhs to lhs (group terms)
	group_terms(terms, rhs_terms);
	// print_terms(rhs_terms);

	// simplify terms

	// sort terms by power
	std::sort(terms.begin(), terms.end(), compare_powers);
}