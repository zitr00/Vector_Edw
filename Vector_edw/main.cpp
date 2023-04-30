#include <iostream>
#include "ewdvector.h"
#include <vector>


int main()
{

	ewd::vector<int> vec;

	/*for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		std::cout << *it << " ";
	}*/

	for (int i = 0; i < 5; ++i)
	{
		int aux;
		std::cin >> aux;
		vec.push_back(aux);
	}

	for (int i = 0; i < 5; ++i)
	{
		std::cout << vec[i]<<" ";
	}
	std::cout << vec.at(2);
	std::cout << vec.capacity();
	return 0;
}