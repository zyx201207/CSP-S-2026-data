#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int n, m, a[N], vis[N], ans;

void dfs(int dep, int sum) {
	if (dep == m) {
		ans = max(ans, sum);
	}

	for (int i = 1; i <= n; i++) {

		if (vis[i] == 0) {
			vis[i] = 1;
			dfs(dep + 1, sum & a[i]);
			vis[i] = 0;
		}
	}
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	int mx = 2e20;
	dfs(0, mx);
	cout << ans;
	return 0;
}