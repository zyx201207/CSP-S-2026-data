#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freout("travel.out", "w", stdout);
	int c1, c2, s1, s3;
	char s2, s4;
	char n, m;
	cin >> c1 >> s1 >> s2 >> c2 >> s3 >> s4;
	if (c1 == c2) {
		cout << "1";
	} else {
		cout << "0";
	}
	if (s1 == s3) {
		cout << "1";
	} else {
		cout << "0";
	}
	n = s2;
	m = s4;
	if (n >= 'A' && n <= 'C' && m >= 'A' && m <= 'C' || n >= 'D' && n <= 'E' && m >= 'D' && m <= 'E') {
		cout << "1";
	} else {
		cout << "0";
	}
	n = s2;
	m = s4;
	if (n == 'A' && m == 'B' || n == 'B' && m == 'A' || n == 'C' && n == 'B' || m == 'B' && m == 'C' || n == 'D'
	        && n == 'E') {

		cout << "1";
	} else if (n == 'E' && m == 'D') {
		cout << "1";
	} else {
		cout << "0";
	}
	return 0;
}