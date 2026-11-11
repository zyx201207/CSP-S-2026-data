#include <bits/stdc++.h>
#define int long long
using namespace std;
int const N = 2000006;
int c, t;
int n, d;
int a[N];
int ans, sum;
int mi = 10000000;

void dfs(int x, int z,  int cnt) {
	if (cnt > mi) {
		return ;
	}
	if (x >= z) {
		if (cnt < mi) {
			mi = cnt;
			ans = 1;
			return ;
		} else if (cnt == mi) {
			ans++;
			return ;
		}
	}
	for (int i = 1; i <= d; i++) {
		dfs(x + i, z,  cnt + 1);
	}
	if (ans >= 2) {
		sum++;
	}
	ans = 0;
	dfs(x + 1, z, 1);
	if (ans >= 2) {
		sum++;
	}
	ans = 0;
	dfs(x, z - 1,  1);
	if (ans >= 2) {
		sum++;
	}
	ans = 0;
	dfs(x + 1, z - 1, 1);
	if (ans >= 2) {
		sum++;
	}
	ans = 0;
}

signed main(void) {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		dfs(a[1], a[n], 1);
		cout << sum;
	}
	return 0;
}