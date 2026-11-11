#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string rc, rs, xc, xs;
	cin >> rc >> rs >> xc >> xs;
	if (rc == xc) {
		cout << 1;
	} else {
		cout << 0;
	}
	if (rc == xc && rs[0] == xs[0] && rs[1] == xs[1]) {
		cout << 1;
	} else {
		cout << 0;
	}
	if (rc == xc && rs[0] == xs[0] && rs[1] == xs[1]) {
		if (rs[2] == 'D' || rs[2] == 'F') {
			if (xs[2] == 'D' || xs[2] == 'F') {
				cout << 1;
			} else {
				cout << 0;
			}
		} else {
			if (xs[2] == 'A' || xs[2] == 'B' || xs[2] == 'C') {
				cout << 1;
			} else {
				cout << 0;
			}
		}
	} else {
		cout << 0;
	}
	if (rc == xc && rs[0] == xs[0] && rs[1] == xs[1]) {
		if (rs[2] == 'D' || rs[2] == 'F') {
			if (xs[2] == 'D' || xs[2] == 'F') {
				cout << 1;
			} else {
				cout << 0;
			}
		} else {
			if (xs[2] == 'A' || xs[2] == 'B' || xs[2] == 'C') {
				ll x = xs[2] - '0';
				ll r = rs[2] - '0';
				if (abs(x - r) == 1) {
					cout << 1;
				} else {
					cout << 0;
				}
			} else {
				cout << 0;
			}
		}
	} else {
		cout << 0;
	}
	return 0;
}