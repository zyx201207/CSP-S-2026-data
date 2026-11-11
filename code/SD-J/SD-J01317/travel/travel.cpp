#include <iostream>
#include <string>
#include <cmath>
#include <stdio.h>

int f(char c)
{
	return (c == 'A' || c == 'B' || c == 'C');
}

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	std::string c1, s1, c2, s2;
	std::cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2)
	{
		std::cout << "0000";
		return 0;
	}
	if(s1.substr(0, 2) != s2.substr(0, 2))
	{
		std::cout << "1000";
		return 0;
	}
	if(f(s1.back()) != f(s2.back()))
	{
		std::cout << "1100";
		return 0;
	}
	if(std::abs((int)s1.back() - (int)s2.back()) > 1)
	{
		if((s1.back() == 'D' && s2.back() == 'F') || (s1.back() == 'F' && s2.back() == 'D'))
		{
			std::cout << "1111";
		} else
		{
			std::cout << "1110";
		}
		return 0;
	}
	std::cout << "1111";
	return 0;
}
