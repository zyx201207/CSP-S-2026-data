#include <bits/stdc++.h>
using namespace std;

int main() {
	std::string c1, s1, c2, s2;
	std::cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2)
		std::cout << "1";
	else
		std::cout << "0";
	if (s1[0: 2] == s2[0: 2])
		std::cout << "1";
	else
		std::cout << "0";
	if (s1[0: 2] == s2[0: 2] && s1[2] != d && s1[2] != c && s2[2] != c && s2[2] != d)
		std::cout << "1";
	else
		std::cout < "0";
	if (s1[2] - s2[2] == 0 || s2[2] - s1[2] == 0)
		std::cout << "1";
	else
		std::cout << "0";
	return 0;
}