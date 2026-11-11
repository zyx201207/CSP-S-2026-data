#include <iostream>
#include <cstdio>
#include <string>

constexpr auto INPUT = "travel.in";
constexpr auto OUTPUT = "travel.out";

int main()
{
#ifndef LOCAL_DEBUGING
	std::freopen(INPUT, "r", stdin);
	std::freopen(OUTPUT, "w", stdout);
#endif

	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int c1, c2;
	std::string s1, s2;
	std::cin >> c1 >> s1 >> c2 >> s2;
	bool option1 = false;
	bool option2 = false;
	bool option3 = false;
	bool option4 = false;
	std::string num1 = "  ", num2 = "  ";
	num1[0] = s1[0];
	num1[1] = s1[1];
	num2[0] = s2[0];
	num2[1] = s2[1];
	char h1 = s1[2], h2 = s2[2];
	option1 = c1 == c2;
	option2 = option1 && (num1 == num2);
	option3 = option2 && ((h1 <= 'C' && h2 <= 'C') || (h1 >= 'D' && h2 >= 'D'));
	if (h2 > h1)
	{
		std::swap(h1, h2);
	}
	option4 = option3 && ((h1 == 'F' && h2 == 'D') || (h1 == 'C' && h2 == 'B') || (h1 == 'B' && h2 == 'A'));
	std::cout << option1 << option2 << option3 << option4;

	std::cout << std::flush;

	std::fclose(stdout);
	std::fclose(stdin);

	return 0;
}

