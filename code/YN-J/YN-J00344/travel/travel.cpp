#include <bits/stdc++.h>
using namespace std;
string c1, c2, s1, s2;
int f;

int main() {
	freopen("travel.in", 'r', stdin);
	freopen("travel.out", 'w', stdin);
	cin >> c1 >> s1 >> c2 >> s2;
	int a = 10 * (s1[0] - '0') + (s1[1] - '0'), b = 10 * (s2[0] - '0') + (s2[1] - '0');

	if (c1 == c2) {
		f = 1;
		cout << 1;
	} else
		cout << 0;

	if (f  && a == b) {
		cout << 1;
	} else
		cout << 0;

	if (f && a == b && ((s1[2] - 'A') < 3 && (s2[2] - 'A') < 3) || ((s1[2] - 'A') >= 3 && (s2[2] - 'A') >= 3)) {
		cout << 1;
	} else
		cout << 0;

	if (f && a == b && ((s1[3] - 'A') < 3 && (s2[2] - 'A') < 3 && ((s1[2] - 'A' + 1 == s2[2] - 'A')
	                    || (s1[2] - 'A' - 1 == s2[2] - 'A'))) || ((s1[2] - 'A') >= 3 && (s2[2] - 'A') >= 3)) {
		cout << 1;
	} else
		cout << 0;
	return 0;
}