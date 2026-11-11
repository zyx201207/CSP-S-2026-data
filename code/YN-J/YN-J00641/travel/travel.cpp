#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string s1x, s1z, s2x, s2z;
	cin >> s1x >> s1z >> s2x >> s2z;
	if (s1x == s2x) {
		cout << '1';
	} else {
		cout << '0' << '0' << '0' << '0';
		return 0;
	}
	string s1 = "", s2 = "";
	s1 += s1z[0] + s1z[1];
	s2 += s2z[0] + s2z[1];
	if (s1 == s2) {
		cout << '1';
	} else {
		cout << '0' << '0' << '0';
		return 0;
	}
	int f = 0;
	if (s1z[2] <= 'C' && s2z[2] <= 'C') {
		cout << '1';
		f = 1;
	} else if (s1z[2] > 'C' && s2z[2] > 'C') {
		cout << '1';
	} else {
		cout << '0' << '0';
		return 0;
	}
	if (f == 1) {
		if (s1z[2] != 'B' && s2z[2] != 'B') {
			cout << '0';
			return 0;
		} else {
			cout << '1';
		}
	} else {
		cout << '1';
	}
	return 0;
}