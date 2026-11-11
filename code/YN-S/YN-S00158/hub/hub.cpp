#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int c, t, n, k, a[N], dep[N], f[N], minn = N, ok = 1;
vector<int>e[N];

void dfs1(int x, int fa) {
	if (a[x] == 1) {
		if (a[fa] == 0)
			ok--;
		dep[x] = f[x] = 0;
	} else {
		f[x] = f[fa] + 1;
		dep[x] = N;
	}
	for (int i = 0; i < e[x].size(); i++) {
		int v = e[x][i];
		if (v != fa) {
			dfs1(v, x);
			dep[x] = min(dep[x], dep[v] + 1);
		}
	}
}

void dfs(int x, int kk) {
	if (x == n + 1 || kk < 0) {
		if (kk == 0 && x == n + 1) {
			ok = 2;
			f[0] = N;
			dfs1(1, 0);
			if (ok >= 0) {
				int maxx = 0;
				for (int i = 1; i <= n; i++) {
					maxx = max(maxx, min(dep[i], f[i]));
				}
				minn = min(maxx, minn);
			}
		}
		return ;
	} else {
		a[x] = 1;
		dfs(x + 1, kk - 1);
		a[x] = 0;
		dfs(x + 1, kk);
	}
}

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		minn = N;
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			e[i].clear();
		}
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs(1, k);
		cout << minn << '\n';
	}
	return 0;
}
/*
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9

*/