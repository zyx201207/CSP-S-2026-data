#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	bool f1 = false, f2 = false, f3 = false;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1[0] == c2[0] && c1[1] == c2[1]) {
		cout << 1;
		f1 = true;
	} else {
		cout << 0;
	}
	if (f1 && s1[0] == s2[0] && s1[1] == s2[1]) {
		cout << 1;
		f2 = true;
	} else
		cout << 0;
	if (f1 && f2 && (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C')) {
		if (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') {
			cout << 1;
			f3 = true;
		} else
			cout << 0;
	} else if (f1 && f2 && (s1[2] == 'D' || s1[2] == 'F')) {
		if (s2[2] == 'D' || s2[2] == 'F') {
			cout << 1;
			f3 = true;
		} else
			cout << 0;
	} else
		cout << 0;
	int t = abs(s1[2] - s2[2]);
	if (t == 1 && f1 && f2 && f3)
		cout << 1;
	else
		cout << 0;
	return 0;
}