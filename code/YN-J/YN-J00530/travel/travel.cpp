#include <bits/stdc++.h>
using namespace std;
#define int long long
string a_c, a_w, b_c, b_w;

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	cin >> a_c >> a_w >> b_c >> b_w;
	if (a_c == b_c) {
		cout << 1;
		int a, b;
		a = ((a_w[0] - '0') * 10) + (a_w[1] - '0');
		b = ((b_w[0] - '0') * 10) + (b_w[1] - '0');
		if (a == b) {
			cout << 1;
			if (a_w[2] >= 'D' && b_w[2] >= 'D') {
				cout << 1 << 1;
			} else if (a_w[2] < 'D' && b_w[2] < 'D') {
				cout << 1;
				if (a_w[2] - 1 == b_w[2] || b_w[2] - 1 == a_w[2]) {
					cout << 1;
				} else {
					cout << 0;
				}
			} else {
				cout << 0 << 0;
			}
		} else {
			cout << 0 << 0 << 0;
		}
	} else {
		cout << 0 << 0 << 0 << 0;
	}
	return 0;
}
