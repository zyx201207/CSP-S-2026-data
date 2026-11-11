#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int a, c, e = 0, f = 0, p = 1;
	string b, d;
	cin >> a >> b >> c >> d;
	e += (b[0] - '0') * 10 + (b[1] - '0') * 1;
	f += (d[0] - '0') * 10 + (d[1] - '0') * 1;
	if (a == c && p == 1) {
		cout << 1;
	} else {
		p = 0;
		cout << 0;
	}
	if (e == f && p == 1) {
		cout << 1;
	} else {
		p = 0;
		cout << 0;
	}
	if (((b[2] == 'D' && d[2] == 'F') || (b[2] == 'A' && d[2] == 'B') || (b[2] == 'A' && d[2] == 'C') || (b[2] == 'B'
	        && d[2] == 'C')) && p == 1) {
		cout << 1;
	} else {
		p = 0;
		cout << 0;
	}
	if (((b[2] == 'D' && d[2] == 'F') || (b[2] == 'A' && d[2] == 'B') || (b[2] == 'B' && d[2] == 'C')) && p == 1) {
		cout << 1;
	} else {
		p = 0;
		cout << 0;
	}
	return 0;
}