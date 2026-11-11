#include <bits/stdc++.h>
using namespace std;

bool z(char q, char w) {
	bool e = (q - 'A' > 2), r = (w - 'A' > 2);
	if (!e ^ r)
		return 1;
	return 0;
}

bool c(char q, char w) {
	int e = q - 'A', r = w - 'A';
	if (w == 'F')
		r = w - 'B';
	return abs(e - r) == 1;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string q, w, e, r;
	cin >> q >> w >> e >> r;
	if (q == e) {
		cout << 1;
		int a, s;
		a += (w[0] - '0') * 10 + (w[1] - '0');
		s += (r[0] - '0') * 10 + (r[1] - '0');
		if (a == s) {
			cout << 1;
			char d = w[2], f = r[2];
			if (z(d, f)) {
				cout << 1;
				if (c(d, f))
					cout << 1;
				else
					cout << 0;
			} else
				cout << "00";
		} else
			cout << "000";
	} else
		cout << "0000";
	return 0;
}