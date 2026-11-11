#include <bits/stdc++.h>
using namespace std;
long long cc, t, n, k, c[1000005], dis[1000005], mx, mi = 1e9;
vector<int>e[1000005];
bool vis[1000005], viss[1000005];

void bfs(int s) {
	queue<pair<int, int>>q;
	q.push({s, 0});
	while (!q.empty()) {
		int u = q.front().first;
		int vv = q.front().second;
		dis[u] = vv;
		q.pop();
		for (auto v : e[u]) {
			if (dis[v] != 0) {
				continue;
			}
			q.push({v, vv + 1});
		}
	}
}

void dfs1(int y) {
	vis[y] = 1;
	for (auto v : e[y]) {
		if (c[v] == 1) {
			dfs1(v);
		} else {
			return;
		}
	}
	return;
}

void dfs(long long x) {
	if (x == n + 1) {
		int cnt = 0, cntt = 0;
		for (int i = 1; i <= n; i++) {
			cntt += c[i];
			if (!vis[i] && c[i]) {
				cnt++;
				dfs1(i);
			}
		}
		if (cnt > 2 || cntt != k) {
			return;
		}
		mx = 0;
		for (int i = 1; i <= n; i++) {
			bfs(i);
			for (int j = 1; j <= n; j++) {
				if (c[j] == 1)
					mx = max(mx, dis[j]);
			}
		}
		mi = min(mi, mx);
	} else {
		for (int i = 0; i <= 1; i++) {
			c[x] = i;
			dfs(x + 1);
		}
	}
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> cc >> t;
	while (t--) {
		mi = 1e9;
		cin >> n >> k;
		for (int i = 1; i <= n - 1; i++) {
			int x, y;
			cin >> x >> y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		dfs(1);
		cout << mi << endl;
	}
	return 0;
}