#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
string rs, xs, r, x;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> r >> rs >> x >> xs;
	if (r != x) {
		cout << "0000";
	} else {
		if (xs[0] != rs[0] || xs[1] != rs[1]) {
			cout << 1000;
		} else {
			if (xs[2] > 'C' && rs[2] <= 'C') {
				cout << 1100;
			} else if (xs[2] <= 'C' && rs[2] > 'C') {
				cout << 1100;
			} else {
				if (abs(int(xs[2] - rs[2])) == 1) {
					cout << 1111;
				} else {
					cout << 1110;
				}
			}
		}
	}
	return 0;
}