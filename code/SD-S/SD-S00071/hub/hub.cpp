#include<bits/stdc++.h>
using namespace std;
#define int long long
int c, t, n, k, x[51], a[51][51], vis[51], dep[51], dep2[51], ans = INT_MAX;
vector<int> e[51], e2[51];
inline void dfs2 (int p) {
	for (auto y : e2[p]) {
		if (!vis[y]) {
			vis[y] = 1;
			dfs2(y);
		}
	}
}
inline void dfs3 (int p) {
	for (auto y : e[p]) {
		if (!vis[y]) {
			vis[y] = 1;
			dep[y] = dep[p] + 1;
			dfs3(y);
		}
	}
}
inline void dfs (int p, int id) {
	if (p == k + 1) {
		for (int i = 1; i <= n; i++) dep2[i] = INT_MAX;
		for (int i = 1; i <= n; i++) e2[i].clear();
		memset(vis, 0, sizeof(vis));
		memset(dep, 0, sizeof(dep));
		for (int i = 1; i <= k; i++) {
			for (int j = i + 1; j <= k; j++) {
				if (a[x[i]][x[j]]) {
					e2[x[i]].push_back(x[j]);
					e2[x[j]].push_back(x[i]);
				}
			}
		}	
		int cnt = 0;
		for (int i = 1; i <= k; i++) {
			if (!vis[x[i]]) {
				vis[x[i]] = 1;
				cnt++;
				if (cnt > 2) return;
				dfs2(x[i]);
			}
		}
		int maxx = 0;
		for (int i = 1; i <= k; i++) {
			memset(vis, 0, sizeof(vis));
			memset(dep, 0, sizeof(dep));
			vis[x[i]] = 1;
			dfs3(x[i]);
			for (int j = 1; j <= n; j++) dep2[j] = min(dep2[j], dep[j]);	
		}
		for (int i = 1; i <= n; i++) {
			maxx = max(maxx, dep2[i]);
		}
		if (maxx < ans) ans = maxx;
		return;
	}
	for (int i = id + 1; i <= n; i++) {
		x[p] = i;
		dfs(p + 1, i);
	}
}
signed main () {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%lld%lld", &c, &t);
	while (t--) {
		scanf("%lld%lld", &n, &k);
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= n; i++) e[i].clear();
		for (int i = 1; i <= n - 1; i++) {
			int u, v;
			scanf("%lld%lld", &u, &v);
			e[u].push_back(v);
			e[v].push_back(u);
			a[u][v] = a[v][u] = 1;
		}
		ans = INT_MAX;
		dfs(1, 0);
		printf("%lld\n", ans);
	}
}
/*
0 1
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
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9*/
