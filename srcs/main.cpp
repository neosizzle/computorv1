#include "main.hpp"

int main(int argc, char const *argv[])
{
	
	if (argc != 2)
	{
		print_err("Bad argc");
		return 1;
	}

	std::string arg = std::string(argv[1]);
	computor(arg);

	return 0;
}
