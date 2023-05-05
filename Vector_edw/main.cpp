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
	//ewd::vector<int> copie(std::move(vec));
	ewd::vector<int> copie(vec);
	for (int i = 0; i < copie.size(); ++i)
	{
		std::cout << copie[i]<<" ";
	}
	copie.erase(1,3);
	std::cout << std::endl;
	for (int i = 0; i < copie.size(); ++i)
	{
		std::cout << copie[i] << " ";
	}
	return 0;
}