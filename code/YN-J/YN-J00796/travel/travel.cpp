#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int k, k2, k3, k4;
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1[0] == '0' && c1[1] == '1' || c1[0] == '1' && c1[1] == '6') {
		k = 1;
	} else {
		k = 2;
	}
	if (c2[0] == '0' && c2[1] == '1' || c2[0] == '1' && c2[1] == '6') {
		k2 = 1;
	} else {
		k2 = 2;
	}
	if (k == k2) {
		cout << 1;
		if (s1[0] == s2[0] && s1[1] == s2[1]) {
			cout << 1;
			if (s1[2] == 'F' || s1[2] == 'D') {
				k3 = 1;
			} else {
				k3 = 2;
			}
			if (s2[2] == 'F' || s2[2] == 'D') {
				k4 = 1;
			} else {
				k4 = 2;
			}
			if (k3 == k4) {
				cout << 1;
				if (abs(s1[2] - s2[2]) == 1) {
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