#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 5;

int ans = INT_MAX, vis[maxn], n, vis2[maxn];
vector<int> graph[maxn], v;

void dis(int x, int y, int &D, int td = 0) {
	if (vis2[x]) return;
	vis2[x] = 1;
	if (x == y) {
		D = td;
		return;
	}
	for (int i : graph[x]) {
		dis(i, y, D, td + 1);
		if (D) return;
	}
}

void dfs(int x) {
	if (vis[x] == 0) return;
	vis[x] = 0;
	for (int i : graph[x]) dfs(i);
}

void calc(int x, int k) {
	if (x > n) {
//		cout << "!!!" << endl;
		if (k) return;
		for (int i : v) vis[i] = 1;
		int cnt = 0;
		for (int i : v) {
			if (vis[i]) {
				dfs(i);
				cnt++;
			}
		}
		if (cnt > 2) return;
		int res = 0;
		for (int i = 1; i <= n; ++i) {
			int tot = INT_MAX;
			for (int j : v) {
				int D = 0; dis(i, j, D);
				tot = min(D, tot);
				memset(vis2, 0, sizeof vis2);
			}
			res = max(res, tot);
		}
		ans = min(ans, res);
		return;
	}
	if (k == 0) {
		calc(n + 1, k);
		return;
	}
	if (k < 0) return;
	calc(x + 1, k);
	v.push_back(x);
	calc(x + 1, k - 1);
	v.pop_back();
} 

void solve() {
	int k; cin >> n >> k;
	for (int i = 1; i <= n; ++i) graph[i].clear();
	for (int i = 1; i < n; ++i) {
		int u, v; cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u); 
	}
	calc(1, k);
	cout << ans << endl;
	ans = INT_MAX;
}

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, T; cin >> c >> T;
	while (T--) solve(); 
	return 0; 
}
/*
0 3
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8
6 5
1 2
2 5
4 5
5 3
3 6
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