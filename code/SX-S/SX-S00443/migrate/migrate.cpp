#include <bits/stdc++.h>
using namespace std;
int c, t, xx;
long long a[2000005], ans, m = 1e9, anss;
long long n, d;

void dfs(int l, int r, int s) {
	if (l >= r ) {
		if (s  < m) {
			ans = 0;
			m = s ;
			return ;
		} else if (s  == m) {
			ans++;
			return ;
		} else
			return ;
	}
	if (a[r] - a[l] <= d && l + 1 < r)
		dfs(r, r, s + 1);
	for (int i = l + 1; i <= r; i++) {
		if (a[i] - a[l] <= d) {
			dfs(i, r, s + 1);
		} else
			break;
	}
}

int main() {
//	freopen("migrate.in", "r", stdin);
//	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		xx = 0;
		ans = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (i > 2) {
				if (a[i] - a[i - 1] != a[i - 1] - a[i - 2])
					xx = 1;
			}
		}
		if (xx == 0) {
			int yy = 2 * (a[2] - a[1]);
			while (d >= 2 * yy) {
				ans++;
				yy += a[2] - a[1];
			}
			cout << ans << "\n";
		} else {
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					ans = 0;
					m = 1e9;
					dfs(i, j, 0);
					if (ans == 2)
						anss++;
				}
			}
			cout << anss << "\n";
		}
	}
	return 0;
}
