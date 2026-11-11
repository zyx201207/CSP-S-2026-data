#include <bits/stdc++.h>
using namespace std;

int main() {
	string s, s1, a, a1;
	cin >> s >> s1 >> a >> a1;
	bool n = 0, m = 0, k = 0;
	if (s != "01" && s != "16" && a != "01" && a != "16") {
		if (a == s) {
			cout << 1;
			k = 1;
		} else {
			cout << 0;
		}
		if (k == 1) {
			if (a1[0] == s1[0] && a1[1] == s1[1]) {
				cout << 1;
				n = 1;
			} else {
				cout << 0;
			}
		} else {
			cout << 0;
		}
		if (n == 1 && k == 1) {
			if (a1[2] == 'A' || a1[2] == 'B' || a1[2] == 'C') {
				if (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') {
					cout << 1;
					m = 1;
				} else {
					cout << 0;
				}
			} else if (a1[2] == 'D' || a1[2] == 'F') {
				if (s1[2] == 'D' || s1[2] == 'F') {
					cout << 1;
					m = 1;
				} else {
					cout << 0;
				}
			}
		} else {
			cout << 0;
		}
		if (n == 1 && k == 1 && m == 1) {
			if (a1[2] == 'A' && s1[2] == 'B') {
				cout << 1;
			} else if (a1[2] == 'B' && s1[2] == 'C') {
				cout << 1;
			} else if (a1[2] == 'C' && s1[2] == 'B') {
				cout << 1;
			} else if (a1[2] == 'B' && s1[2] == 'A') {
				cout << 1;
			} else if (a1[2] == 'D' && s1[2] == 'F') {
				cout << 1;
			} else if (a1[2] == 'F' && s1[2] == 'D') {
				cout << 1;
			} else {
				cout << 0;
			}
		} else {
			cout << 0;
		}
	}
	freopen("travel.in", 'i', stdin);
	freopen("travel.out", 'w', stdout);
	return 0;
}