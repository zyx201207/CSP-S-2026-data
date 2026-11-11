#include <bits/stdc++.h>
using namespace std;

struct seat {
	int x;
	string s;
} x, r;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	char a, b;
	cin >> a >> b;
	x.x = (a - '0') * 10 + b;
	cin >> x.s >> a >> b;
	r.x = (a - '0') * 10 + b;
	cin >> r.s;
	if (x.x == r.x) {
		cout << 1;
	} else {
		cout << "0000";
		return 0;
	}
	if (x.s[0] == r.s[0] && x.s[1] == r.s[1]) {
		cout << 1;
	} else {
		cout << "000";
		return 0;
	}
	if (x.s[2] >= 'D' && r.s[2] >= 'D') {
		cout << 1;
	} else if (x.s[2] <= 'C' && r.s[2] <= 'C') {
		cout << 1;
	} else {
		cout << "00";
		return 0;
	}
	if (abs(x.s[2] - r.s[2]) == 1 && !((x.s[2] == 'C' && r.s[2] == 'D') || (x.s[2] == 'D' && r.s[2] == 'C'))) {
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
}
