#include "main.hpp"

void print_solution(Solution sol)
{
	// print all possible solutions
	if (sol.all_interger_solution && sol.for_degree == 0)
	{
		print(std::string(BOLDWHITE) + std::string("Number of solutions: " )+ std::string(RESET) + "All integers");
		return;
	}
	else if (!sol.all_interger_solution && sol.for_degree == 0)
	{
		print(std::string(BOLDWHITE) + std::string("Number of solutions: " )+ std::string(RESET) + "Impossible");
		return;
	}

	// print number of solutions
	print(std::string(BOLDWHITE) + std::string("Number of solutions: " )+ std::string(RESET) + std::to_string(sol.num_sols));

	// zero discriminant
	if (sol.zero_discriminant)
	{
		// print no discriminant
		print(std::string(BOLDWHITE) + std::string("Dissciminant " )+ std::string(RESET) + "Zero");


		// print solution one
		print(std::string(BOLDWHITE) + std::string("Solution one: " )+ std::string(RESET) + std::to_string(sol.solution_one));

		// if num of sols is 2, print solution 2
		if (sol.num_sols == 2)
			print(std::string(BOLDWHITE) + std::string("Solution two: " )+ std::string(RESET) + std::to_string(sol.solution_two));
	}
	// positive discriminant
	else if (sol.neg_discriminant == false)
	{
		// print positive discriminant
		print(std::string(BOLDWHITE) + std::string("Dissciminant " )+ std::string(RESET) + "Positive");


		// print solution one
		print(std::string(BOLDWHITE) + std::string("Solution one: " )+ std::string(RESET) + std::to_string(sol.solution_one));

		// if num of sols is 2, print solution 2
		if (sol.num_sols == 2)
			print(std::string(BOLDWHITE) + std::string("Solution two: " )+ std::string(RESET) + std::to_string(sol.solution_two));
	}
	else
	{
		// print negative discriminant
		print(std::string(BOLDWHITE) + std::string("Dissciminant " )+ std::string(RESET) + "Negative");


		// print solution one
		print(std::string(BOLDWHITE) + std::string("Solution one: " )+ std::string(RESET) + std::to_string(sol.imaginary_coefficient) + std::string("+") + std::to_string(sol.imaginary_term) + "i");

		// if num of sols is 2, print solution 2
		if (sol.num_sols == 2)
			print(std::string(BOLDWHITE) + std::string("Solution two: " )+ std::string(RESET) + std::to_string(sol.imaginary_coefficient) + std::string("-") + std::to_string(sol.imaginary_term) + "i");
	}
}

/**
 * @brief Prints error message
 *
 */
void print_err(std::string message)
{
	std::cout << BOLDRED << "ft_error: " << RESET;
	std::cout << RED << message << "\n"
			  << RESET;
}

/**
 * @brief prints something without typing std::cout
 * 
 * @param message 
 */
void print(std::string message)
{
	std::cout << message << "\n";
}