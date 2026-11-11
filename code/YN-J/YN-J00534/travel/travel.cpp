//wr 2026.10.31 CSP rp++!
#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int ans = 0;

int f(char c) {
	if (c == 'A')
		return 1;
	if (c == 'B')
		return 2;
	if (c == 'C')
		return 3;
	if (c == 'D')
		return 4;
	return 5;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> s1 >> s2;
	bool a = (s1.substr(0, 2) == s2.substr(0, 2));
	bool b = a && (s1.substr(2, 2) == s2.substr(2, 2));
	bool c = b && ((s1[4] <= 'C' && s2[4] <= 'C') || (s1[4] >= 'D' && s2[4] >= 'D'));
	bool d = c && (abs(f(s1[4]) - f(s2[4])) == 1);
	cout << (a ? '0' : '1');
	cout << (b ? '0' : '1');
	cout << (c ? '0' : '1');
	cout << (d ? '0' : '1');
	return 0;
}