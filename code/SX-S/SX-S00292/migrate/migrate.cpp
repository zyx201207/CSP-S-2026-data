#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, t;
int d;
int a[100000];
int b[100000];
int c[100000];
int ans = 0;
int ac, ak = 4;
int sum;
int mn;

void dfs(int idx, int dis) {
	if (idx > n)
		return ;
	b[idx] = min(b[idx], dis);
	for (int i = idx + 1; i <= n; i++) {

		if (a[idx] + d >= a[i]) {
			dfs(i, dis + 1);
		}
	}
}

void dfs1(int idx, int dis) {
	if (idx > n)
		return ;
	if (b[idx] == dis) {
		c[idx]++;
	}
	for (int i = idx + 1; i <= n; i++) {
		if (a[idx] + d >= a[i]) {
			dfs1(i, dis + 1);
		}
	}
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> ac;
	cin >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			b[i] = 100000;
			c[i] = 0;
		}
		for (int i = 1; i <= n; i++) {

			sum = 0;
			mn = INT_MAX;
			dfs(i, 0);
			dfs1(i, 0);
			for (int j = i + 1; j <= n; j++) {
				if (c[j] == 2) {
					ans++;
				}
				b[i] = 100000;
				c[i] = 0;
			}
		}
		cout << ans << endl;
		ans = 0;
	}
	return 0;
}

