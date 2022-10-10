#include "main.hpp"

void computor(std::string arg)
{
	std::vector<Term> terms;

	// trim all whitespaces from input
	arg.erase(std::remove_if(arg.begin(), arg.end(), isspace), arg.end());

	// validate symbols
	const char invalid_symbol = validate_symbols(arg);
	if (invalid_symbol)
	{
		std::cout << "Invalid symbol \'" << invalid_symbol << "\'"
				  << "\n";
		return;
	}

	// can only have one '='
	if (std::count(arg.begin(), arg.end(), '=') != 1)
	{
		std::cout << "Invalid number of \'" << EQ_SYMBOL << "\'"
				  << "\n";
		return;
	}

	// extract and group terms
	extract_terms(arg, terms);

	// simplufy terms
	simplify_terms(terms);
	print_terms(terms);

	// validate equation
	if (validate_equation(terms))
		return ;

	const Solution solution = evaluate_equation(terms);
	print_solution(solution);

	std::cout << "End " << "\n";
}