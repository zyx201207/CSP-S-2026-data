#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("travel.in", "r", stdin);
	//freopen("travel.out", "w", stdout);
	string s, ss, c, cc;
	cin >> s >> ss >> c >> cc;
	int ans = 0, sum = 0, f = 0, a = 0, b = 0, d = 0, e = 0, v = 0;
	if (s == c) {
		cout << 1;
	} else {
		cout << 0;
		cout << 0;
		cout << 0;
		cout << 0;
		return 0;
	}
	if (ss[1] == cc[1]) {
		cout << 1;
	} else {
		sum = 1;
		cout << 0;
		cout << 0;
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= 2 ; i++) {
		if (ss[2] == 'A' || ss[2] == 'B' || ss[2] == 'C') {
			a = 1;
		} else if (ss[2] == 'D' || ss[2] == 'F') {
			b = 2;
		}
	}
	for (int j = 1; j <= 2 ; j++) {
		if (cc[2] == 'A' || cc[2] == 'B' || cc[2] == 'C') {
			d = 1;
		} else if (cc[2] == 'D' || ss[2] == 'F') {
			e = 2;
		}
	}
	if (a == d || b == e) {
		cout << 1;
	} else {
		cout << 0;
	}
	if (ss[2] == 'A' && cc[2] == 'B' ) {
		cout << 1;
		v = 1;
	} else if (ss[2] == 'B' && cc[2] == 'C' ) {
		cout << 1;
		v = 1;
	} else if (ss[2] == 'D' && cc[2] == 'F' ) {
		cout << 1;
		v = 1;
	} else if (ss[2] == 'B' && cc[2] == 'A' ) {
		cout << 1;
		v = 1;
	} else if (ss[2] == 'C' && cc[2] == 'B' ) {
		cout << 1;
		v = 1;
	} else if (ss[2] == 'F' && cc[2] == 'D' ) {
		cout << 1;
		v = 1;
	}
	if (v == 0) {
		cout << 0;
	}
	return 0;
}