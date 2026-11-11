#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
string c1, s1, c2, s2;
int x, p, c, l;

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		x = 1;
	}
	if (s1[0] + s1[1] == s2[0] + s2[1] && x == 1) {
		p = 1;
		if (s1[2] == 'F') {
			if (s2[2] == 'D') {
				c = 1;
			}
		}
		if (s1[2] == 'D') {
			if (s2[2] == 'F') {
				c = 1;
			}
		}
		if (s1[2] == 'A') {
			if (s2[2] == 'B' || s2[2] == 'C') {
				c = 1;
			}
		}
		if (s1[2] == 'B') {
			if (s2[2] == 'A' || s2[2] == 'C') {
				c = 1;
			}
		}
		if (s1[2] == 'C') {
			if (s2[2] == 'B' || s2[2] == 'A') {
				c = 1;
			}
		}
	}
	if (s1[2] + 1 == s2[2] || s1[2] == s2[2] + 1 && p == 1) {
		l = 1;
	}
	cout << x << p << c << l;
	return 0;
}