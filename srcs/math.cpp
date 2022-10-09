#include "main.hpp"

/**
 * @brief returns absolute value between two numbers
 * 
 * @param a 
 * @param b 
 * @return int 
 */
int ft_abs(int a, int b)
{
	if (a > b) return a - b;
	else return b - a;
}