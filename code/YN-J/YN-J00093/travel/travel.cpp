#include <bits/stdc++.h>
using namespace std;
int c1, c2, sl1, sl2;
char s1, s2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> sl1 >> s1 >> c2 >> sl2 >> s2;

	if (c1 == c2)
		printf("1");
	else
		printf("0");

	if (sl1 == sl2 && c1 == c2)
		printf("1");
	else
		printf("0");

	if (c1 == c2 && sl1 == sl2 && ((s1 >= 'A' && s1 <= 'C' && s2 >= 'A' && s2 <= 'C') || (s1 >= 'D' && s1 <= 'E'
	                               && s2 >= 'D'
	                               && s2 <= 'E')))
		printf("1");
	else
		printf("0");

	if (abs((int)s1 - s2) == 1 && ((s1 != 'C' && s2 != 'D') && (s1 != 'D' && s2 != 'C')) && sl1 == sl2 && c1 == c2)
		printf("1");
	else
		printf("0");
	return 0;
}