#include <bits/stdc++.h>

using namespace std;

char c1[5], s1[5], c2[5], s2[5];
int a, b, c, d, e, f;

int ts(char cc) {
	if (cc >= '0' && cc <= '9') return cc - '0';
	if (cc == 'A') return 1;
	if (cc == 'B') return 2;
	if (cc == 'C') return 3;
	if (cc == 'D') return 5;
	if (cc == 'F') return 6;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	a = ts(c1[0]) * 10 + ts(c1[1]); // chexiang
	b = ts(s1[0]) * 10 + ts(s1[1]); // hang
	c = ts(s1[2]);					// lie
	d = ts(c2[0]) * 10 + ts(c2[1]); // chexiang
	e = ts(s2[0]) * 10 + ts(s2[1]); // hang
	f = ts(s2[2]);					// lie
	if (a != d) {
		cout << "0000\n";
		return 0;
	}
	if (b != e) {
		cout << "1000\n";
		return 0;
	}
	if (!((c <= 3 && f <= 3) || (c >= 5 && f >= 5))) {
		cout << "1100\n";
		return 0;
	}
	if (!(abs(c - f) == 1)) {
		cout << "1110\n";
		return 0;
	}
	cout << "1111\n";
	return 0;
}
