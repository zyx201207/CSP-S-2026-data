#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	string a, b;
	for (int i = 0; i <= 1; i++) {
		a += s1[i];
		b += s2[i];
	}
	int c, d;
	c = s1[2];
	d = s2[2];
	if (c1 == c2) {
		cout << 1;
		if (a == b) {
			cout << 1;
			if (((65 <= c && c <= 67) && (65 <= d && d <= 67)) || ((68 <= c && c <= 69) && (68 <= d && d <= 69))) {
				cout << 1;
				if (abs(c - d) == 1) {
					cout << 1;
				} else {
					cout << 0;
				}
			} else {
				cout << 0 << 0;
			}

		} else {
			cout << 0 << 0 << 0;
		}
	} else {
		cout << 0 << 0 << 0 << 0;
	}
	return 0;







}