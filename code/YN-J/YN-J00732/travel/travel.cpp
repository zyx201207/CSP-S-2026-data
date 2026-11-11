#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.in", "w", stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	int a1, a2, b1, b2;
	char c1, c2;
	cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
	if (a1 == a2) {
		cout << 1;
		if (b1 == b2) {
			cout << 1;
			if (((c1 >= 'A' && c1 <= 'C') && (c2 >= 'A' && c2 <= 'C')) || ((c1 >= 'D' && c1 <= 'E') && (c2 >= 'D' && c2 <= 'E'))) {
				cout << 1;
				if (c1 + 1 == c2 || c1 - 1 == c2) {
					cout << 1;
				} else {
					cout << 0;
				}
			} else {
				cout << "00";
			}
		} else {
			cout << "000";
		}
	} else {
		cout << "0000";
	}
	return 0;
}