#include <bits/stdc++.h>
using namespace std;
string c1, c2, s1, s2;
bool p = false, p1 = false;
int main() {
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2) {
		cout << "0000";
		return 0;
	}
	if (s1[0] != s2[0] || s1[1] != s2[1]) {
		cout << "1000";
		return 0;
	}
	for (int i = 0; i <= 2; i++) {
		if (s1[2] == 'A' + i)
			p = true;
		if (s2[2] == 'A' + i)
			p1 = true;
	}
	if (p != p1) {
		cout << "1100";
		return 0;
	}
	if ((s1[2] == 'A' || s2[2] == 'A') && (s1[2] == 'C' || s2[2] == 'C')) {
		cout << "1110";
		return 0;
	}
	cout << "1111";
	return 0;
}
