#include "i2n.h"
#include <iostream>

int main()
{
	int integer;

	std::cout << "Please input an integer." << std::endl;
	std::cin >> integer;
	std::cout << "You have inputted:\n" << i2n(integer) << std::endl;

	system("pause");
	return 0;
}
