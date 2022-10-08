#include "main.hpp"

int main(int argc, char const *argv[])
{
	
	if (argc != 2)
	{
		std::cout << "bad argc\n" ;
		return 1;
	}

	std::string arg = std::string(argv[1]);
	computor(arg);

	return 0;
}
