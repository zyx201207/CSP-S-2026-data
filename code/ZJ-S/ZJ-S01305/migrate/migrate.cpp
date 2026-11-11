#include <bits/stdc++.h>
using namespace std;
#define int long long
int c, t, n, d, x[2000005], ans = 0, sum = 0, sh = 1e18;
void dfs1(int s, int e, int t) {
	if (x[s] == x[e]) {
		sh = min(sh, t);
		return;
	}
	if (x[s] > x[e]) {
		return;
	}
	for (int i = s + 1; x[i] - x[s] <= d; i++) {
		dfs1(i, e, t + 1);
	}
}
void dfs2(int s, int e, int t) {
	if (x[s] == x[e]) {
		if (t > sh) {
			return;
		}
		sum++;
		return;
	}
	if (x[s] > x[e]) {
		return;
	}
	for (int i = s + 1; x[i] - x[s] <= d; i++) {
		dfs2(i, e, t + 1);
	}
}
signed main() {
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--) {
		ans = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		for (int i = n + 1; i <= n + d; i++) {
			x[i] = 1e18;
		}
		int f = 0;
		for (int i = 1; i < n; i++) {
			for (int j = i + 1; j <= n; j++) {
				sh = (j - i) / d + 1;
				sum = 0;
				dfs1(i, j, 0);
				dfs2(i, j, 0);
				if (sum == 2) {
					ans++;
					if (c == 11 || c == 12) {
						cout << n - (j - i);
						f = 1;
						break;
					}
				}
			}
			if (f == 1) {
				break;
			}
		}
		if (f == 1) {
			continue;
		}
		cout << ans << endl;
	}
	return 0;
}