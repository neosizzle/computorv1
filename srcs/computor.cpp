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
		print_err(std::string("Invalid symbol \'") + invalid_symbol + std::string("\'"));
		return;
	}

	// can only have one '='
	if (std::count(arg.begin(), arg.end(), '=') != 1)
	{
		print_err(std::string("Invalid number of  \'") + EQ_SYMBOL + std::string("\'"));
		return;
	}

	// extract and group terms
	extract_terms(arg, terms);

	// simplufy terms
	simplify_terms(terms);

	// print reduced equation
	print(std::string(BOLDWHITE) + std::string("Reduced form: ") + std::string(RESET) + terms_to_str(terms) + " = 0");
	// print_terms(terms);

	// validate equation
	if (validate_equation(terms))
		return ;

	const Solution solution = evaluate_equation(terms);
	print_solution(solution);

	std::cout << "End " << "\n";
}