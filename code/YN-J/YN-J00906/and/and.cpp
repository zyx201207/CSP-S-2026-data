#include <bits/stdc++.h>
using namespace std;

int n, m, a[2005], ans, dp[2005][2005];

int dfs(int pos, int cnt) {
	if (dp[pos][cnt] != -1)
		return dp[pos][cnt];

	if (cnt == m)
		return a[pos - 1];

	if (pos == n + 1)
		return a[pos - 1];

	int ans = dfs(pos + 1, cnt);

	ans = max(ans, dfs(pos + 1, cnt + 1)&a[pos]);

	return dp[pos][cnt] = ans;
}

void solve() {
	cin >> n >> m;
	memset(dp, -1, sizeof(dp));

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	cout << dfs(1, 0);
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;
}