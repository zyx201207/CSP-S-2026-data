#include <bits/stdc++.h>
using namespace std;
string c1, c2, s1, s2;
string s;
bool f = 1;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;

	if (c1 == c2)
		cout << 1;
	else
		cout << 0;

	for (int i = 0; i <= 1; i++) {
		if (s1[i] != s2[i]) {
			f = 0;
		}
	}
	bool f1 = 1;
	if (f == 1) {
		if (s1 == s2) {
			cout << 0 << 0;
		} else {
			cout << 1;
			char s21 = s1[2] + 1, s22 = s1[2] - 1;
			if (s1[2] == 'A' && (s2[2] == 'B' || s2[2] == 'C')) {
				cout << 1;
			} else if (s1[2] == 'B' && (s2[2] == 'A' || s2[2] == 'C')) {
				cout << 1;
			} else if (s1[2] == 'C' && (s2[2] == 'A' || s2[2] == 'B')) {
				cout << 1;
			} else if (s1[2] == 'F' && s2[2] == 'D') {
				cout << 1;
			} else if (s1[2] == 'D' && s2[2] == 'F') {
				cout << 1;
			} else {
				cout << 0;
				f1 = 0;
			}
		}
	} else {
		cout << 0 << 0;
	}

	char s11 = s1[1] + 1, s22 = s1[1] - 1, s1a = s1[2] + 1, s1b = s1[2] - 1;
	if (s1 == s2)
		cout << 0;
	else if (f1) {
		if (s1[0] == s2[0]) {
			if ((s11 == s2[1] && s1[2] == s2[2]) || (s22 == s2[1] && s1[2] == s2[2]) || (s1[1] == s2[1] && (s2[2] == s1a
			        || s2[2] == s1b))) {
				cout << 1;
			} else {
				cout << 0;
			}
		} else if (s2[0] == '1' || s1[0] == '1') {
			if (s2[0] == '1' && s2[1] == '0' && s1[1] == '9')
				cout << 1;
			else if (s1[0] == '1' && s1[1] == '0' && s2[1] == '9')
				cout << 1;
			else
				cout << 0;
		}
	} else
		cout << 0;

	return 0;
}