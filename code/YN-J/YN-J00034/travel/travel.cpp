#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool cx = 1, cp = 1, cc = 1, cz = 1;
	if (c1 != c2) {
		cx = 0;
		cout << "0000";
		return 0;
	}
	string s11, s21;
	s11 = s1[0] + s1[1];
	s21 = s2[0] + s2[1];
	if (s11 != s21) {
		cp = 0;
		cout << "1000";
		return 0;
	}
	char s1a, s2a;
	s1a = s1[2];
	s2a = s2[2];
	if (s1a < 'D' && s2a >= 'D') {
		cc = 0;
		cout << "1100";
		return 0;
	}
	int z = abs(s1a - s2a);
	if (z != 1) {
		cz = 0;
		cout << "1110";
		return 0;
	}
	cout << "1111";
	return 0;
}