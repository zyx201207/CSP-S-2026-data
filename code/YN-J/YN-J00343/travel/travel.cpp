#include <bits/stdc++.h>
using namespace std;
bool b[5], f;
int c1, c2;
string s1, s2;
int q1, q2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (s1[2] == 'A') {
		q1 = 1;
	}
	if (s1[2] == 'B') {
		q1 = 2;
	}
	if (s1[2] == 'C') {
		q1 = 3;
	}
	if (s1[2] == 'D') {
		q1 = 4;
	}
	if (s1[2] == 'F') {
		q1 = 5;
	}
	if (s2[2] == 'A') {
		q2 = 1;
	}
	if (s2[2] == 'B') {
		q2 = 2;
	}
	if (s2[2] == 'C') {
		q2 = 3;
	}
	if (s2[2] == 'D') {
		q2 = 4;
	}
	if (s2[2] == 'F') {
		q2 = 5;
	}
	if (c1 == c2) {
		b[1] = 1;
	} else {
		b[1] = 0;
		b[2] = 0;
		b[3] = 0;
		b[4] = 0;
		f = 1;
	}
	if (s1[0] == s2[0] && s1[1] == s2[1] && f != 1) {
		b[2] = 1;
	} else {
		b[2] = 0;
		b[3] = 0;
		b[4] = 0;
		f = 1;
	}
	if ('A' <= s1[2] && s1[2] <= 'C' && f != 1) {
		if ('A' <= s2[2] && s2[2] <= 'C' && f != 1) {
			b[3] = 1;
		} else {
			b[3] = 0;
			b[4] = 0;
			f = 1;
		}
	} else if ('D' <= s1[2] && s1[2] <= 'F' && f != 1) {
		if ('D' <= s2[2] && s2[2] <= 'F' && f != 1) {
			b[3] = 1;
		} else {
			b[3] = 0;
			b[4] = 0;
			f = 1;
		}
	} else {
		b[3] = 0;
		b[4] = 0;
		f = 1;
	}
	if ((q1 + 1 == q2 || q2 + 1 == q1) && f != 1) {
		b[4] = 1;
	} else {
		b[4] = 0;
	}
	for (int i = 1; i <= 4; i++) {
		cout << b[i];
	}
	return 0;
}