//SN-S00518 李承欢 西安市铁一中学
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 4010;
int c, T, n, k, a[N];
vector<int> edge[N];
int dis[N][N], vis[N], b[N], mn = 1e18;

void dfs(int pos) {
	if (pos <= n) {
		b[pos] = 1;
		dfs(pos + 1);
		b[pos] = 0;
		dfs(pos + 1);
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += b[i];
	}
	if (sum != k) {
		return;
	}
	int c[12], tot = 0, vis[12];
	for (int i = 1; i <= n; i++) {
		vis[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		if (b[i]) {
			c[++tot] = i;
		} else {
			vis[i] = 1;
		}
	}
	int ans = 0;
	for (int i = 1; i <= tot; i++) {
		if (vis[c[i]]) {
			continue;
		}
		ans++;
		queue<int> q;
		q.push(c[i]);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			vis[u] = 1;
			for (auto v : edge[u]) {
				if (vis[v]) {
					continue;
				}
				q.push(v);
			}
		}
	}
	if (ans > 2) {
		return;
	}
	int maxn = 0;
	for (int i = 1; i <= n; i++) {
		int minn = 1e18;
		for (int j = 1; j <= tot; j++) {
			minn = min(minn, dis[i][c[j]]);
		}
		maxn = max(maxn, minn);
	}
//	if (maxn == 1) {
//		for (int i = 1; i <= tot; i++) {
//			cout << c[i] << " ";
//		}
//		cout << '\n';
//	}
	mn = min(mn, maxn);
	return;
}

signed main () {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> T;
	while (T--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			edge[i].clear();
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = 0;
			}
		}
		mn = 1e18;
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			edge[u].push_back(v);
			edge[v].push_back(u);
			dis[u][v] = 1;
			dis[v][u] = 1;
		}
		for (int i = 1; i <= n; i++) {
			queue<int> q;
			for (int j = 1; j <= n; j++) {
				vis[j] = 0;
				if (dis[i][j]) {
					q.push(j);
				}
			}
			while (!q.empty()) {
				int u = q.front();
				q.pop();
				vis[u] = 1;
				for (auto v : edge[u]) {
					if (vis[v]) {
						continue;
					}
					dis[i][v] = dis[i][u] + 1;
					q.push(v);
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			dis[i][i] = 0;
		}
		if (k == n) {
			cout << 0 << '\n';
			continue;
		}
		dfs(1);
		cout << mn << '\n';
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
*/
