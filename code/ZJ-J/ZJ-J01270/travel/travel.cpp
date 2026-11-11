#include <bits/stdc++.h>
using namespace std;
int a, d, b, e, c, f;
char cc, ff;
string bc, ef;
int main() {
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	cin >> a >> bc >> d >> ef;
	if (a == d) {
		cout << 1;
	}
	else {
		cout << "0000";
		return 0;
	}
	b = bc[0] * 10 + bc[1];
	e = ef[0] * 10 + ef[1];
	cc = bc[2];
	ff = ef[2];
	if (cc == 'A') c = 1;
	if (cc == 'B') c = 2;
	if (cc == 'C') c = 3;
	if (cc == 'D') c = 4;
	if (cc == 'E') c = 5;
	if (ff == 'A') f = 1;
	if (ff == 'B') f = 2;
	if (ff == 'C') f = 3;
	if (ff == 'D') f = 4;
	if (ff == 'E') f = 5;
	if (b == e) {
		cout << 1;
	}
	else {
		cout << "000";
		return 0;
	}
	if (c <= 3 && f <= 3) {
		cout << 1;
	}
	else if (c >= 4 && f >= 4) {
		cout << 1;
	}
	else {
		cout << "00";
		return 0;
	}
	if (abs(c - f) == 1 && c + f != 7) {
		cout << 1;
	}
	else {
		cout << 0;
	}
	return 0;
}
