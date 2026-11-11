#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "w", stdin);
	freopen("travel.out", "r", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2) {
		cout << "0000";
		return 0;
	}
	if (s1[0] != s2[0] || s2[1] != s1[1]) {
		cout << "1000";
		return 0;
	}
	int a, s;
	if (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') {
		s = 1;
	} else {
		s = 2;
	}
	if (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') {
		a = 1;
	} else {
		a = 2;
	}
	if (a != s) {
		cout << "1100";
		return 0;
	}
	long long m = abs(s1[2] - s2[2]);
	if (m != 1) {
		cout << "1110";
	} else {
		cout << "1111";
	}
	return 0;
}