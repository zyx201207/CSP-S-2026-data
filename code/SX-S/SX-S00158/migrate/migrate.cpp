#include <bits/stdc++.h>
using namespace std;
long long x[2000005];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c, t;
	cin >> c >> t;
	while (t--) {
		long long n, d;
		cin >> n >> d;
		int w = 0;
		int y = 0;
		for (int i = 1; i <= n; i++) {
			int a;
			cin >> a;
			x[i] = a - y;
			y = a;
			if (x[i] <= d)
				w = i;
		}
		long long s = 0;
		int c1 = 0;
		for (int i = 2; i <= w; i++) {
			s += x[i];
		}
		if (s < d) {
			cout << 0 << endl;
			continue;
		}
		int ans = 0;
		for (int h = 3; h <= w; h++) {
			bool b = 1;
			s = 0;
			for (int i = 2; i <= h; i++) {
				s += x[i];
				if (s == d) {
					c1++;
					s = 0;
				}
				if (s > d) {
					b = 0;
					break;
				}
			}
			if (!b)
				continue;
			s = 0;
			int c2 = 0;
			for (int i = h; i >= 2; i--) {
				s += x[i];
				if (s == d) {
					c2++;
					s = 0;
				}
				if (s > d) {
					b = 0;
					break;
				}
			}
			if (!b)
				continue;
			if (c1 == c2 && c1 != 0)
				ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
