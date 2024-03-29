#include "main.hpp"

/**
 * @brief euclids method to return greatest common divider
*/
static float ft_gcd(int a, int b)
{
	if (a < b) return 1;
	if (b == 0) return a;
	return ft_gcd(b, a % b);
}

/**
 * @brief returns absolute value
 * 
 * @param a 
 */
static float ft_ab(float a)
{
	if (a < 0)
		return a * -1;
	return a;
}

/**
 * @brief returnslowest fraction of a number
 * 
 * @param a 
 * @return string
 */
std::string ft_lowest_frac(float num)
{
	int whole = num;
	int currBase = 1;
	int denom = 1000;
	int numer = 0;
	int num_neg = 0;
	std::string res = "";

	if (num < 0)
	{
		num_neg = 1;
		num *= -1;
	}	
	for (size_t i = 0; i < 3; i++)
	{
		int factor = ft_pow(10, 2 - i);
		num -= (int)num;
		num = num * 10;
		currBase *= 10;
		numer += (int)num * factor;
	}

	if (whole != 0)
		res += std::to_string(whole) + " + ";
	else if (num_neg)
		res += " - ";
	res += std::to_string(int(ft_ab(numer / ft_gcd(denom, numer))));
	res += " / ";
	res += std::to_string(int(ft_ab(denom / ft_gcd(denom, numer))));
	return res;
}

/**
 * @brief returns absolute value between two numbers
 * 
 * @param a 
 * @param b 
 * @return int 
 */
float ft_abs(float a, float b)
{
	if (a > b) return a - b;
	else return b - a;
}

/**
 * @brief Evaluates the of number a raised by the power of power
 * 
 * @param a 
 * @param power 
 * @return double 
 */
float ft_pow(float a, int power)
{
	if (power == 0)
		return 1;
	if (power == 1)
		return a;
	if (power < 0)
		return 0;
	return (ft_pow((a * a), power - 1));
}

/**
 * @brief Evaluate the square root of a number using Babylonian Method
 * https://www.youtube.com/watch?v=CnMBo5nG_zk
 * 
 * @param x number to evaluate
 * @param guess current guess
 * @return float 
 */

/**
 * @brief Evaluate the square root of a decimal number without using external libraries
 * 
 * @param x number to evaluate
 * @return float 
 */
float ft_sqrt(float x, float guess)
{
	const float inverse = x / guess;

	// std::cout << "guess " << guess << "\n";
	// std::cout << "inverse " << inverse << "\n";
	// std::cout << "guess - inverse " << ((guess - inverse)*100000) << "\n";
	// sleep(2);

	// return 0 if x == 0
	if (x == 0) return x;

	// return guess if guess and x / guess are equal
	if (int((guess - inverse)*100000) == 0)
		return guess;

	// take the avg of two and make it the new guess
	const float new_guess = (inverse + guess) / 2;
	return ft_sqrt(x, new_guess);
}

/**
 * @brief Generate DinomialEquation object based on terms given
 * 
 * @param terms 
 * @return DinobialEquation 
 */
static DinobialEquation generate_eq(std::vector<Term> terms)
{
	float a;
	float b;
	float c;
	DinobialEquation res;

	a = terms[0].constant;
	if (terms[0].is_neg) a *= -1;
	if (terms.size() == 2)
	{
		if (terms[1].power == 0)
		{
			b = 0;
			c = terms[1].constant;
			if (terms[1].is_neg) c *= -1;
		}
		else
		{
			b = terms[1].constant;
			if (terms[1].is_neg) b *= -1;
			c = 0;
		}
	}
	else
	{
		b = terms[1].constant;
		if (terms[1].is_neg) b *= -1;
		c = terms[2].constant;
		if (terms[2].is_neg) c *= -1;
	}
	res.a = a;
	res.b = b;
	res.c = c;
	return res;
}

/**
 * @brief evaluate monomial distribution in the form of ax+b=0
 * 
 * @param terms 
 * @return Solution 
 */
static Solution evaluate_monomial(std::vector<Term> terms)
{
	Solution res;
	float result;
	float b;
	float a;

	res.neg_discriminant = false;
	res.zero_discriminant = false;
	res.num_sols = 1;
	res.solution_one = 0;
	res.solution_two = 0;
	res.imaginary_coefficient = -1;
	res.imaginary_term = -1;
	res.for_degree = 1;
	res.all_interger_solution = false;
	
	// if length of terms is 1, return solution
	if (terms.size() == 1) return res;

	// print banner
	print(std::string(BOLDGREEN) + "========== CALCUATION ==========" + std::string(RESET));

	a = terms[0].constant;
	if (terms[0].is_neg) a *= -1;

	b = terms[1].constant;
	if (terms[1].is_neg) b *= -1;

	result = ((b * -1) / a);
	res.solution_one = result;
	res.solution_two = result;

	//print result formula
	print(std::string(BOLDWHITE) + std::string("Solution: ") + std::string(RESET) + std::string(BOLDWHITE) + std::to_string(b) + std::string(RESET) + std::string(" * -1 / ") + std::string(BOLDWHITE) + std::to_string(a) + std::string(RESET));

	// print banner
	print(std::string(BOLDGREEN) + "========== CALCUATION END ==========" + std::string(RESET));

	return res;
}

/**
 * @brief evaluate binomial equation in the form of ax^2+bx+c=0 (assumes a is not 0 and eq is simplified)
 * 
 * @param terms 
 * @return Solution 
 */
static Solution evaluate_bonimial(std::vector<Term> terms)
{
	const DinobialEquation eq = generate_eq(terms);
	float discriminant;

	// run quadratic formula (-b +- sqrt(b^2-4ac))/2a
	Solution res;
	res.neg_discriminant = false;
	res.zero_discriminant = false;
	res.num_sols = -1;
	res.solution_one = 0;
	res.solution_two = 0;
	res.imaginary_coefficient = -1;
	res.imaginary_term = -1;
	res.for_degree = 2;
	res.all_interger_solution = false;

	// print banner
	print(std::string(BOLDGREEN) + "========== CALCUATION ==========" + std::string(RESET));

	// print a, b, and c
	print(std::string(BOLDWHITE) + std::string("a: ") + std::string(RESET) + std::to_string(eq.a));
	print(std::string(BOLDWHITE) + std::string("b: ") + std::string(RESET) + std::to_string(eq.b));
	print(std::string(BOLDWHITE) + std::string("c: ") + std::string(RESET) + std::to_string(eq.c));


	// evaluate discriminant b^2-4ac
	discriminant = ft_pow(eq.b, 2) - 4 * eq.a * eq.c;

	// print discriminant
	print(std::string(BOLDWHITE) + std::string("b^2-4ac (discriminant): ") + std::string(RESET) + std::to_string(discriminant));

	if (discriminant < 0)
	{
		res.neg_discriminant = true;
		discriminant *= -1;
	}
	if (discriminant == 0)
		res.zero_discriminant = true;
	float discriminant_squared = ft_sqrt(discriminant, discriminant / 2);

	// print discriminant squared
	print(std::string(BOLDWHITE) + std::string("Discriminant squared: ") + std::string(RESET) + std::to_string(discriminant_squared));


	print(std::string(BOLDWHITE) + std::string("First solution: ") + std::string(RESET) + std::string(BOLDWHITE) + std::to_string((int)eq.b) + std::string(RESET) + std::string(" * -1 + ") + std::string(BOLDWHITE) + std::to_string(discriminant_squared) + std::string(RESET) + std::string(" / 2 * ") + std::string(BOLDWHITE) + std::to_string((int)eq.a) + std::string(RESET));
	print(std::string(BOLDWHITE) + std::string("Second solution: ") + std::string(RESET) + std::string(BOLDWHITE) + std::to_string((int)eq.b) + std::string(RESET) + std::string(" * -1 - ") + std::string(BOLDWHITE) + std::to_string(discriminant_squared) + std::string(RESET) + std::string(" / 2 * ") + std::string(BOLDWHITE) + std::to_string((int)eq.a) + std::string(RESET));

	// evaluate the result from formula
	const float first_sol = ((eq.b * -1) + discriminant_squared) / (2 * eq.a);
	const float second_sol = ((eq.b * -1) - discriminant_squared) / (2 * eq.a);
	res.solution_one = first_sol;
	res.solution_two = second_sol;

	// evalute imaginary terms and coefficients if discriminant is negative
	if (res.neg_discriminant)
	{
		res.imaginary_coefficient = (eq.b * -1) / (2 * eq.a);
		res.imaginary_term = discriminant_squared / (2 * eq.a);
	}

	// populate num_sols
	if (res.neg_discriminant) res.num_sols = 0;
	if (first_sol == second_sol) res.num_sols = 1;
	else res.num_sols = 2;

	// print footer
	print(std::string(BOLDGREEN) + "========== CALCUATION END ==========" + std::string(RESET));
	return res;
}


/**
 * @brief evaluate evaluates zero degreee sol
 * 
 * @param terms 
 * @return Solution 
 */
static Solution evaluate_zerodegree(std::vector<Term> terms)
{
	DinobialEquation eq;

	eq.a = 0;
	eq.b = 0;
	eq.c = terms.size() > 0 ? terms[0].constant : 0;

	Solution res;
	res.neg_discriminant = false;
	res.zero_discriminant = false;
	res.num_sols = -1;
	res.solution_one = 0;
	res.solution_two = 0;
	res.imaginary_coefficient = -1;
	res.imaginary_term = -1;
	res.for_degree = 0;
	res.all_interger_solution = eq.c == 0;

	return res;
}


Solution evaluate_equation(std::vector<Term> terms)
{
	// calls evaluate_bonimialeval if degree of polynomial is 2, evaluate_monomial when degree is 1
	if (terms[0].power == 2) return evaluate_bonimial(terms);
	else if (terms[0].power == 1) return evaluate_monomial(terms);
	else return evaluate_zerodegree(terms);

}