#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
string x, y, x1, y2;

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> x >> y >> x1 >> y2;

	if (x != x1) {
		cout << 0 << 0 << 0 << 0;
	} else {
		cout << 1;

		if (y[0] == y2[0] && y[1] == y2[1]) {
			cout << 1;

			if (y[2] <= 'C' && y2[2] <= 'C') {
				cout << 1;

				if (abs(y[2] - y2[2]) == 1) {
					cout << 1;
				} else {
					cout << 0;
				}
			} else if (y[2] >= 'D' && y2[2] >= 'D') {
				cout << 1 << 1;
			} else  {
				cout << 0 << 0;
			}
		} else {
			cout << 0 << 0 << 0;
		}
	}

	return 0;
}