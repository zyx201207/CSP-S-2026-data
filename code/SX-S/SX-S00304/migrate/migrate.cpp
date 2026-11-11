#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6+5;
int c, t, n, d;
int a[N];
int s[N];

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		memset(a, 0, sizeof a);
		memset(s, 0, sizeof s);
		int cutedpoint = n;
		bool cf = 1;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			s[i] = s[i - 1] + a[i];
			if (a[i] - a[i - 1] > d && cf) {
				cutedpoint = i - 1;
				cf = 0;
			}
		}
		if (c >= 11 && c <= 12) {
			int gc = a[2] - a[1];
			int ku = (int)(d / gc);
			int jsd = ku * 2 - 1;
			if (d < gc) {
				cout << 0 << '\n';
				continue;
			}
			if (ku == 1) {
				cout << 0 << '\n';
				continue;
			}
			if (ku > 1) {
				int x = n - jsd;
				if (x < 0)
					x = 0;
				cout << x << '\n';
				continue;
			}
		}
		if (cutedpoint <= 3) {
			cout << 0 << '\n';
			continue;
		}
		if (c >= 1) {
			int gc = a[2] - a[1];
			int ku = (int)(d / gc);
			int jsd = ku * 2 - 1;
			if (d < gc) {
				cout << 0 << '\n';
				continue;
			}
			if (ku == 1) {
				cout << 0 << '\n';
				continue;
			}
			if (ku > 1) {
				int x = cutedpoint - jsd;
				if (x < 0)
					x = 0;
				cout << x << '\n';
				continue;
			}
		}
	}
	return 0;
}
