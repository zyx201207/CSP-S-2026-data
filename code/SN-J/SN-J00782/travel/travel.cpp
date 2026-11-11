//SN-J00782 李承欢 西安市铁一中学
#include <bits/stdc++.h>
#define int long long
using namespace std;

string c1, s1, c2, s2;

signed main () {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2) {
		cout << "0000";
	} else {
		cout << 1;
		if (s1[0] != s2[0] || s1[1] != s2[1]) {
			cout << "000";
		} else {
			cout << 1;
			int x = s1[2] - 'A' + 1;
			int y = s2[2] - 'A' + 1;
			if (max(x, y) >= 4 && min(x, y) <= 3) {
				cout << "00";
			} else {
				cout << 1;
				if (min(x, y) >= 4) {
					cout << 1;
				} else {
					if (max(x, y) == 3 && min(x, y) == 1) {
						cout << 0;
					} else {
						cout << 1;
					}
				}
			}
		}
	}
	return 0;
}
