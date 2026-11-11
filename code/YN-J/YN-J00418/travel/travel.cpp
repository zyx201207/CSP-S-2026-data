#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("in.travel", "r", stdin);
	freopen("out.travel", "w", stdout);
	string a, b, c, d;
	int q, w, e, z, x;
	z = 0;
	x = 0;
	cin >> a >> b >> c >> d;
	if (a == c) {
		cout << 1;
		q = 1;
	} else {
		cout << 0 << 0 << 0 << 0;
		q = 0;
		return 0;
	}
	if (b[0] == d[0] && b[1] == d[1]) {
		cout << 1;
		w = 1;
	} else {
		cout << 0 << 0 << 0;
		w = 0;
		return 0;
	}
	if (b[2] == 'D' || b[2] == 'F') {
		z = 1;
	} else {
		z = 0;
	}
	if (d[2] == 'D' || d[2] == 'F') {
		x = 1;
	} else {
		x = 0;
	}
	if (z == x) {
		cout << 1;
		e = 1;
	} else {
		cout << 0 << 0;
		e = 0;
		return 0;
	}
	z = 0;
	x = 0;
	if (q == 1 && w == 1 && e == 1) {
		z = 1;
	}
	if (b[2] == d[2] + 'b' - 'a' || b[2] == d[2] + 'a' - 'b') {
		x = 1;
	}
	if (z == x && z == 1) {
		cout << 1;
	} else {
		cout << 0;
	}
}