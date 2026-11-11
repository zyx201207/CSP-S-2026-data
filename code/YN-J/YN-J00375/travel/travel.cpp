#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int a, b, ax, bx, ay, by, ta, tb;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	a = (c1[0] - '0') * 10 + (c1[1] - '0');
	b = (c2[0] - '0') * 10 + (c2[1] - '0');
	ax = (s1[0] - '0') * 10 + (s1[1] - '0');
	ay = s1[2] - 64;
	bx = (s2[0] - '0') * 10 + (s2[1] - '0');
	by = s2[2] - 64;
	if (ay == 6)
		ay = 5;
	if (by == 6)
		by = 5;
	if (ay > 3)
		ta = 0;
	else
		ta = 1;
	if (by > 3)
		tb = 0;
	else
		tb = 1;
	if (a == b) {
		cout << 1;
		if (ax == bx) {
			cout << 1;
			if (ta == tb) {
				cout << 1;
				if (abs(ay - by) == 1) {
					cout << 1;
				} else
					cout << 0;
			} else
				cout << "00";
		} else
			cout << "000";
	} else
		cout << "0000";
	return 0;
}