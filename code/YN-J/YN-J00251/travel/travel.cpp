#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string s1, s, s2, ss;
	cin >> s1 >> s >> s2 >> ss;
	if (s1 == s2) {
		cout << 1;
	} else
		cout << 0;
	if (s1 == s2 && s[0] == ss[0] && ss[1] == s[1]) {
		cout << 1;
	} else
		cout << 0;
	if (s1 == s2 && s[0] == ss[0] && ss[1] == s[1]) {
		char c = s[2];
		char cc = ss[2];
		bool flgg = 1;
		if (c == 'A' && cc == 'B' || c == 'A' && cc == 'c')
			cout << 1;
		else if (c == 'B' && cc == 'C' || c == 'B' && cc == 'A')
			cout << 1;
		else if (c == 'C' && cc == 'B' || c == 'C' && cc == 'A')
			cout << 1;
		else if (c == 'D' && cc == 'F' || c == 'F' && cc == 'D')
			cout << 1;
		else {
			cout << 0;
			flgg = 0;
		}
		if (abs((int)c - (int)cc) == 1 && flgg == 1) {
			cout << 1;
		} else if ((c == 'D' && cc == 'F' || c == 'F' && cc == 'D') && flgg == 1) {
			cout << 1;
		} else
			cout << 0;
	} else {
		cout << 0;
		cout << 0;
	}

	return 0;
}
