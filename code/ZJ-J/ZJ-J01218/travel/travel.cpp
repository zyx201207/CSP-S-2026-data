#include <iostream>
#include <algorithm>
#include <cmath>

#define int long long

signed main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	std::string c1, s1, c2, s2;
	std::cin >> c1 >> s1 >> c2 >> s2;
	int a = 0, b = 0, jud1 = 0, jud2 = 0, num1 = 0, num2 = 0;
	int i = 0, j = 0;
	while('0' <= s1[i] and s1[i] <= '9')
		a = a * 10 + (s1[i] - '0'), i++;
	while('0' <= s2[j] and s2[j] <= '9')
		b = b * 10 + (s2[j] - '0'), j++;
	if('A' <= s1[s1.size() - 1] and s1[s1.size() - 1] <= 'C')
		jud1 = 1;
	else
		jud1 = 2;
	if('A' <= s2[s2.size() - 1] and s2[s2.size() - 1] <= 'C')
		jud2 = 1;
	else
		jud2 = 2;
	num1 = s1[s1.size() - 1] - 'A';
	num2 = s2[s2.size() - 1] - 'A';
	printf("%d", (c1 == c2));
	printf("%d", ((c1 == c2) & (a == b)));
	printf("%d", ((c1 == c2) & (a == b) & (jud1 == jud2)));
	printf("%d", ((c1 == c2) & (a == b) & (jud1 == jud2) & ((int)std::abs(num1 - num2) == 1)));
	return 0;
}