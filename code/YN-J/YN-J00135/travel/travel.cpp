#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string s1, c1, s2, c2;
	int h1, h2, h = 1;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1[0] == c2[0] && c1[1] == c2[1])
		cout << 1;
	else {
		cout << 0;
		h = 0;
	}

	if (s1[0] == s2[0] && s1[1] == s2[1] && h)
		cout << 1;
	else {
		cout << 0;
		h = 0;
	}
	if (s1[2] <= 'C')
		h1 = 1;
	else
		h1 = 0;
	if (s2[2] <= 'C')
		h2 = 1;
	else
		h1 = 0;
	if (h1 == h2 && h)
		cout << 1;
	else {
		cout << 0;
		h = 0;
	}
	if ((s2[2] == s1[2] - 1 || s2[2] == s1[2] + 1) && h)
		cout << 1;
	else
		cout << 0;
	return 0;
}