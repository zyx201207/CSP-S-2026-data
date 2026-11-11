#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
string n, a, b, c, d, ans;
int x, y, flg;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> b >> c >> d;
	if (a == c) {
		cout << 1;
	} else {
		cout << 0;
		flg = 1;
	}
	if (flg) {
		cout << 0 << 0 << 0;
		return 0;
	}
	x += int(b[0] - '0') * 10 + int(b[1] - '0');
	y += int(d[0] - '0') * 10 + int(d[1] - '0');
	if (x == y) {
		cout << 1;
	} else {
		cout << 0;
		flg = 1;
	}
	if (flg) {
		cout << 0 << 0;
		return 0;
	}
	if (b[2] == 'F' || b[2] == 'D') {
		if (d[2] == 'F' || d[2] == 'D') {
			cout << 1 << 1;
			return 0;
		} else {
			cout << 0;
			flg = 1;
		}
	}
	if (flg) {
		cout << 0;
		return 0;
	}
	if (b[2] == 'C' || b[2] == 'B' || b[2] == 'A') {
		if (d[2] == 'C' || d[2] == 'B' || d[2] == 'A') {
			cout << 1;
		} else {
			cout << 0;
			flg = 1;
		}
	}
	if (flg) {
		cout << 0;
		return 0;
	}
	if (abs(int(b[2] - 'A') - int(d[2] - 'A')) <= 1) {
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
}
//by yyy 2026.10.31