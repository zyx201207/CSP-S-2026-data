#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c1, c2, a, b, c, d;
	string s1, s2;
	cin >> c1 ;
	for (int i; i < 2; i++)
		cin >> s1[i];
	cin >> c2 ;
	for (int i; i < 2; i++)
		cin >> s2[i];
	if (c1 = c2) {
		a = 1, c = 1 ;
	}

	else
		a = 0, c = 0;
	if (s1 != s2)
		b = 0, d = 0;

	else if (s1[0] == s2[0] && s1[1] == s2[1])
		b = 1, d = 0;
	else
		b = 1, d = 1;

	cout << a << b << c << d;
	fclose stdin;
	fclose stdout;
	return 0;

}