#include <bits/stdc++.h>
//#define int long long
using namespace std;
int n, m;
int a[200010];
int ma = -1;

bool cmp(int x, int y) {
	return x > y;
}

void dfs(int u, int t, int ans) {
	if (u >= n) {
		if (t == m)
			ma = max(ans, ma);
		return;
	}
	if (t == m) {
		ma = max(ma, ans);
		return;
	}
	if (t == 0)
		dfs(u + 1, t + 1, a[u]);
	else
		dfs(u + 1, t + 1, ans & a[u]);
	dfs(u + 1, t, ans);
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	dfs(1, 0, 1);
	cout << ma;
	return 0;
}