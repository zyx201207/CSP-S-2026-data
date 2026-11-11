#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
int n, m, maxn = 0;

void dfs(int dep, int cnt, int sum) {
	if (dep > n)
		return;
	if (n - dep + cnt < m)
		return;
	if (cnt == m) {
		maxn = max(maxn, sum);
		return;
	}
	dfs(dep + 1, cnt, sum);
	if (sum == 0) {
		sum = a[dep];
		dfs(dep + 1, cnt + 1, a[dep]);
	} else {
		dfs(dep + 1, cnt + 1, sum & a[dep]);
	}
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dfs(1, 0, 0);
	cout << maxn;
	return 0;
}
