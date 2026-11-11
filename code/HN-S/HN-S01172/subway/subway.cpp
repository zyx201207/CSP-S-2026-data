#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 505, M = 5e5 + 10, Q = 1e5 + 10;

int c, n, m, d, q, k[N], w[M];
vector<int> a[N], t[N];
vector<pair<int, int> > sta[M];
int minn = 1e18;

void dfs(int idx, int line, int fa, int tar, int sum) {
	if (line > n)
		return;
	if (idx < 1 || idx > k[line])
		return;
	int cur = a[line][idx];
//	cout << "Query:" << cur << '\n';
	if (sum > minn)
		return;
	if (cur == tar) {
		minn = min(minn, sum + t[line][idx]);
		return;
	}
	if (idx == 1) {
		if (idx + 1 == fa)	
			return;
		dfs(idx + 1, line, idx, tar, sum);
	} else if (idx == k[line]) {
		if (idx - 1 == fa)
			return;
		dfs(idx - 1, line, idx, tar, sum);
	} else {
		if (idx - 1 != fa)
			dfs(idx - 1, line, idx, tar, sum);
		if (idx + 1 != fa)
			dfs(idx + 1, line, idx, tar, sum);
	}
	for (auto it : sta[cur]) {
		if (it.first == line)
			continue;
		dfs(it.second, it.first, 0, tar, sum + (t[line][idx] + t[it.first][it.second]));
	}
	return;
}

void Solve(int x, int y) {
	minn = 1e18;
	for (auto it : sta[x]) { 
		dfs(it.second, it.first, 0, y, w[x] + w[y] + t[it.first][it.second]);
	}
	cout << minn << '\n';
} 

signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		a[i].resize(k[i] + 1), t[i].resize(k[i] + 1);
		for (int j = 1; j <= k[i]; j++) {
			int x, y;
			cin >> x >> y;
			a[i][j] = x, t[i][j] = y;
			sta[x].push_back({i, j});
		}
	}
	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		Solve(x, y);
	}
	return 0;
}

