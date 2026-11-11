#include <bits/stdc++.h>
using namespace std;
#define int long long
int c1, c2;
string s1, s2, ans;

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		string sr = "";
		string sx = "";
		for (int i = 0; i <= 1; i++) {
			sr += s1[i];
			sx += s2[i];
		}
		if (sr == sx) {
			if (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') {
				if (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') {
					if (abs(s1[2] - s2[2]) == 1) {
						cout << 1 << 1 << 1 << 1;
					} else {
						cout << 1 << 1 << 1 << 0;
					}
				} else {
					cout << 1 << 1 << 0 << 0;
				}
			} else {
				if (s2[2] == 'D' || s2[2] == 'F') {
					cout << 1 << 1 << 1 << 1;
				} else {
					cout << 1 << 1 << 0 << 0;
				}
			}
		} else {
			cout << 1 << 0 << 0 << 0;
		}
	} else {
		cout << 0 << 0 << 0 << 0;
	}
	return 0;
}