#include <bits/stdc++.h>
using namespace std;
string rc, rs, xc, xs;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> rc >> rs >> xc >> xs;
	if (rc == xc) {
		cout << "1";
		bool f = 1;
		for (int i = 0; i < 2; i++) {
			if (rs[i] != xs[i])
				f = 0;
		}
		if (f == 1) {
			cout << "1";
			if (max(int(rs[2]), int(xs[2])) >= 'D' && min(int(rs[2]), int(xs[2])) <= 'C') {
				cout << "00";
			} else {
				cout << "1";
				if (max(int(rs[2]), int(xs[2])) - min(int(rs[2]), int(xs[2])) == 1) {
					cout << "1";
				} else {
					cout << "0";
				}
			}
		} else {
			cout << "000";
		}
	} else {
		cout << "0000";
	}
	return 0;
}