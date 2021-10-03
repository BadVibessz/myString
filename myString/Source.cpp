#include "str.h"
#include <iostream>
#include <string>

int main()
{
	str a, b;
	std::cin >> a;
	b = "nikita";
	// TODO:проверить operator<T>+ на всех типах
	str c = a + b;                                             // str + str [working]
	//str c = a + " 123";                                      // str + const char* [working]
	//char* d = new char[3]; std::cin >> d; str c = a + d;     // str + char* [working]
	// str + char ?
	// str + const char ?

	std::cout <<c<< std::endl;
	std::cout << c[3] << std::endl;
	std::cout << c.size() << std::endl;

	return 0;
}