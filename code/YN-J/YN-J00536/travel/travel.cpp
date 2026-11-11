#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c1, c2;
	string s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	char sr = s1[2];
	char sx = s2[2];
	if (sr > 'C') {
		sr += 2;
	}
	if (sx > 'C') {
		sx += 2;
	}
	int pr = (s1[0] - '0') * 10 + (s1[1] - '0');
	int px = (s2[0] - '0') * 10 + (s2[1] - '0');
	//cout << c1 << ' ' << c2 << ' ' << sr << ' ' << sx << ' ' << pr << ' ' << px << ' ';
	int f = 1;
	if (c1 == c2 && f == 1) {
		cout << 1;
	} else {
		f = 0;
		cout << 0;
	}
	if (pr == px && f == 1) {
		cout << 1;
	} else {
		f = 0;
		cout << 0;
	}
	if (abs(sr - sx) <= 2 && f == 1) {
		cout << 1;
	} else {
		f = 0;
		cout << 0;
	}
	if (abs(sr - sx) == 1 && f == 1) {
		cout << 1;
	} else {
		f = 0;
		cout << 0;
	}
	return 0;
}