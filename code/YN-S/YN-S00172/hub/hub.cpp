//2026.10.31  zyb  hub
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5, L = 21;
int n, k, ans;
vector<int>e[N];
int c[N];
int up[N][L], dep[N];

void tdfs(int u) {
	for (int i = 1; i < L; i++) {
		up[u][i] = up[up[u][i - 1]][i - 1];
	}
	for (auto v : e[u]) {
		if (v == up[u][0])
			continue;
		up[v][0] = u;
		dep[v] = dep[u] + 1;
		tdfs(v);
	}
}

int dis(int x, int y) {
	if (dep[x] < dep[y])
		swap(x, y);
	int res = dep[x] - dep[y];
	for (int i = L - 1; i >= 0; i--)
		if (dep[up[x][i]] >= dep[y])
			x = up[x][i];
	if (x == y)
		return res;
	int d = dep[y];
	for (int i = L - 1; i >= 0; i--) {
		if (up[x][i] != up[y][i])
			x = up[x][i], y = up[y][i];
	}
	return res + 2 * (d - dep[x] + 1);
}

void dfs(int pos, int cnt) {
	if (cnt > k)
		return ;
	if (pos == n + 1) {
		if (cnt < k)
			return ;
		int res = 0;
		for (int i = 1; i <= n; i++) {
			if (c[i] == 1 && c[up[i][0]] == 0)
				res++;
		}
		if (res > 2)
			return ;
		res = 0;
		for (int i = 1, minn; i <= n; i++) {
			if (c[i])
				continue;
			minn = 1e9;
			for (int j = 1; j <= n; j++) {
				if (c[j] == 0)
					continue;
				minn = min(minn, dis(i, j));
			}
			res = max(res, minn);
		}
		ans = min(ans, res);
		return ;
	}
	for (int i = 0; i <= 1; i++) {
		c[pos] = i;
		dfs(pos + 1, cnt + i);
		c[pos] = 0;
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int id, T;
	cin >> id >> T;
	while (T--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
			e[i].clear();
		for (int i = 1, u, v; i < n; i++) {
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dep[0] = -1;
		ans = 1e18;
		tdfs(1);
		dfs(1, 0);
		cout << ans << '\n';
	}
	return 0;
}