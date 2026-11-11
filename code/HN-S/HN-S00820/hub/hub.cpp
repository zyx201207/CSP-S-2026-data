#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e6 + 5;

vector<int> G[N];
bool vis[N];
int c, T, n, k, num, ans = INT_MAX, siz[N], dep[N], dp[N];

void dfs (int u, int fa, int dis) {
//	cout << u << ' ' << fa << ' ' << dis << '\n';
	if (vis[u]) {
		num = min (num, dis);
		return ;
	}
	for (int v : G[u]) {
		if (v == fa) continue;
		dfs (v, u, dis + 1);
	}
}

void DFS (int cur, int K) {
	if (K > k) return ;
	if (cur > n) {
		int maxx = 0;
		for (int i = 1; i <= n; i++) {
			if (!vis[i]) {
				num = n - 1;
				dfs (i, 0, 0);
				maxx = max (maxx, num);
			}
		}
		ans = min (ans, maxx);
	}
	vis[cur] = 1;
	DFS (cur + 1, K + 1);
	vis[cur] = 0;
	DFS (cur + 1, K);
}

void dfs1 (int u, int fa) {
	siz[u] = 1;
	dep[u] = dep[fa] + 1;
	for (int v : G[u]) {
		if (v == fa) continue;
		dfs1 (v, u);
		siz[u] += siz[v];
	}
}

void dfs2 (int u, int fa) {
	for (int v : G[u]) {
		if (v == fa) continue;
		dp[u] = dp[fa] + siz[1] - siz[u] - siz[u];
		dfs2 (v, u);
	}
}

void Solve () {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		G[i].clear ();
	} 
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		G[u].push_back (v);
		G[v].push_back (u);
	}
	if (n == k) {
		cout << 0 << '\n';
	} else if (n - 1 == k) {
		cout << 1 << '\n';
	} else if (n - 2 == k) {
		cout << 2 << '\n';
	} else {
		cout << k - 1 << '\n';
	}
}

signed main() {
	freopen ("hub.in", "r", stdin);
	freopen ("hub.out", "w", stdout);
	ios::sync_with_stdio (false);
	cin.tie (0), cout.tie (0);
	cin >> c >> T;
	while (T--) {
		Solve ();
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

0 1
5 2
1 2
2 3
3 4
4 5
*/
