#include <iostream>
#include <string>
#include <stdio.h>
std::string check(int, int, char, int, int, char);
int to_int(std::string);

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	std::string c1, s1, c2, s2;
	std::cin >> c1 >> s1 >> c2 >> s2;
	std::cout << check(to_int(c1), to_int(s1.substr(0, 2)), s1[2], to_int(c2), to_int(s2.substr(0, 2)), s2[2]) << std::endl;
}

std::string check(int x1, int y1, char c1, int x2, int y2, char c2){
	if(x1 != x2)
		return "0000";
	if(y1 != y2)
		return "1000";
	bool f1 = (c1 == 'A' || c1 == 'B' || c1 == 'C'), f2 = (c2 == 'A' || c2 == 'B' || c2 == 'C');
	if(f1 != f2)
		return "1100";
	if((std::abs((int)c1 - (int)c2)) != 1)
		return "1110";
	return "1111";
}

int to_int(std::string str){
	int ans = 0;
	for(int i = 0; i < str.length(); i++)
		ans = ans * 10 + str[i] - '0';
	return ans;
}
