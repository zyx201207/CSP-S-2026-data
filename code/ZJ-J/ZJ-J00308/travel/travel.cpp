#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string s1, c1, s2, c2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool f = false;
	if (c1[0] == c2[0] && c1[1] == c2[1]) {
		cout << "1";
		f = true;
	} else
		cout << "0";
	bool f1 = false;
	if (f && s1[0] == s2[0] && s1[1] == s2[1]) {
		cout << "1";
		f1 = true;
	} else
		cout << "0";
	bool f2 = false;
	if (f && f1 && ((s1[2] == 'A' && s2[2] == 'B') || (s2[2] == 'A' && s1[2] == 'B') || (s1[2] == 'A' && s2[2] == 'C') || (s2[2] == 'A' && s1[2] == 'C') || (s1[2] == 'B' && s2[2] == 'C') || (s2[2] == 'B' && s1[2] == 'C') || (s1[2] == 'D' && s2[2] == 'F') || (s2[2] == 'D' && s1[2] == 'F'))) {
		cout << "1";
		f2 = true;
	} else
		cout << "0";
	if (f && f1 && f2 && abs((int)s1[2] - (int)s2[2]) <= 1)
		cout << "1";
	else
		cout << "0";
	return 0;
}