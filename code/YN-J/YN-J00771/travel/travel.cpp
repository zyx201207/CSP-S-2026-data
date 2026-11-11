#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen(" travel5.in", "r", stdin);
	freopen(" travel5.out", "w", stdout);
	int n, m, t = 0;
	string n1, m1;
	cin >> n >> n1 >> m >> m1;
	if (n != m) {
		cout << "0000";
		return 0;
	} else {
		cout << "1";
	}
	for (int i = 0; i < 2; i++) {
		if (n1[i] != m1[i]) {
			t = 1;
		}
	}
	if (t == 1) {
		cout << "000";
		return 0;
	} else {
		cout << "1";
	}
	int s = 0, s2 = 0;
	if (n1[2] >= 'D') {
		if (m1[2] >= 'D') {
			s++;
		}
		s++;
	} else if (n1[2] < 'D') {
		if (m1[2] < 'D') {
			s2++;
		}
		s2++;
	}
	if (s == 2 || s2 == 2) {
		cout << "1";
	} else {
		cout << "00";
		return 0;
	}
	if (abs(n1[2] - m1[2]) == 1) {
		cout << "1";
	} else {
		cout << "0";
	}
	return 0;
}