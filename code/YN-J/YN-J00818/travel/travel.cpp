#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int a, b;
	string c, d;
	cin >> a >> c;
	cin >> b >> d;
	if (a == b) {
		cout << "1";
		if (c[0] == d[0] && c[1] == d[1]) {
			cout << "1";
			if ((c[2] <= 'C' && d[2] <= 'C') || (c[2] > 'C' && d[2] > 'C')) {
				cout << "1";
				if (abs(c[2] - d[2]) == 1) {
					cout << "1";
				} else {
					cout << "0";
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