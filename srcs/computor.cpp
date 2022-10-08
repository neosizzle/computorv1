#include "main.hpp"

void computor(std::string arg)
{
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

	// extract terms
	extract_terms(arg);
	

	// 

	std::cout << "End " << "\n";
}