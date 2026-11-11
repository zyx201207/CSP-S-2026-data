#include <bits/stdc++.h>
using namespace std;

int n, m, re[200005], dp[20005][20005];

int dfs(int x, int y) {
	if (x == 0 || y == 0) {
		return 0;
	}

	if (dp[x][y] != -1) {
		return dp[x][y];
	}

	int ans = dfs(x - 1, y);

	if (y == m && x == n) {
		ans += re[x];
	}

	ans = max(ans, (dfs(x - 1, y - 1) & re[x]));

	dp[x][y] = ans;
	return ans;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	memset(dp, -1, sizeof(dp));

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> re[i];
	}

	cout << dfs(n, m);

	return 0;
}