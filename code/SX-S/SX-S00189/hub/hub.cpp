#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<vector<int>> G(1000010);
bool vis[1000010];

int fa[1000010];

void add(int x, int y) {
	fa[y] = x;
}

void dfs(int p, int nowK) {
	for (int i = p; i <= n; i ++) {
		if (!vis[i] && nowK <= k) {
			vis[i] = true;

			dfs(i, nowK + 1);

			vis[i] = false;
		}
	}
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i ++) {
		fa[i] = i;
	}

	for (int i = 1; i < n; i ++) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v), G[v].push_back(u);
	}

	dfs(1, 0);

	return 0;
}
