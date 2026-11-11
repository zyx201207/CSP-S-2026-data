#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, ans = -1e9, a[N], b[N];
bool vis[N];

void dfs(int pos) {
	if (pos == m + 1) {
		int sum = b[1];
		for (int i = 2; i <= m; i++)
			sum &= b[i];
		ans = max(ans, sum);
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i])
			continue;
		vis[i] = 1, b[pos] = a[i];
		dfs(pos + 1);
		vis[i] = 0;
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	dfs(1);
	cout << ans << '\n';
	return 0;
}