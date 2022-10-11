#include "main.hpp"

void print_solution(Solution sol)
{
	// print number of solutions
	print(std::string(BOLDWHITE) + std::string("Number of solutions: " )+ std::string(RESET) + std::to_string(sol.num_sols));

	// positive discriminant
	if (sol.neg_discriminant == false)
	{
		// print positive discriminant
		if (sol.for_degree == 2)
			print(std::string(BOLDWHITE) + std::string("Dissciminant " )+ std::string(RESET) + "Positive");


		// print solution one
		print(std::string(BOLDWHITE) + std::string("Solution one: " )+ std::string(RESET) + std::to_string(sol.solution_one));

		// if num of sols is 2, print solution 2
		if (sol.num_sols == 2)
			print(std::string(BOLDWHITE) + std::string("Solution two: " )+ std::string(RESET) + std::to_string(sol.solution_two));
	}
	else
	{
		// print positive discriminant
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