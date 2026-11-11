#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int a = 0, b = 0, c = 0;
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << "1";
		a++;
	} else {
		cout << "0";
	}
	for (int i = 0; i < s1.size() - 1; i++) {
		if (a == 1 && s1[i] == s2[i]) {
			b++;
		} else {
			cout << "0";
		}
	}
	if (b == 2) {
		cout << "1";
		if (s1[2] == 'A' && s2[2] == 'c' || s1[2] == 'C' && s2[2] == 'A') {
			cout << "1";
		} else if (s1[2] == 'A' && s2[2] == 'B' || s1[2] == 'B' && s2[2] == 'A') {
			cout << "1";
			c++;
		} else if (s1[2] == 'B' && s2[2] == 'c' || s1[2] == 'C' && s2[2] == 'B') {
			cout << "1";
			c++;
		} else if (s1[2] == 'D' && s2[2] == 'F' || s1[2] == 'F' && s2[2] == 'D') {
			cout << "1";
			c++;
		} else {
			cout << "0";
		}
	} else {
		cout << "0";
	}
	if (c == 1) {
		cout << "1";
	} else {
		cout << "0";
	}

	return 0;
}