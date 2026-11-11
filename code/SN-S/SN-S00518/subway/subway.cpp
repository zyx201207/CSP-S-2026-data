//SN-S00518 李承欢 西安市铁一中学
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1010;
int c, n, m, d, q, w[N], x, y;
int k[510], a[510][N], t[510][N];
int mn = 1e18, dis[N];
vector<pair<int, int>> edge[N];

void dfs(int ln, int now, int cos, int dep, int huan) {
	if (dep > m) {
		return;
	}
	if (cos > mn) {
		return;
	}
	if (now == y) {
		int c;
		for (int j = 1; j <= k[ln]; j++) {
			if (a[ln][j] == now) {
				c = t[ln][j];
				break;
			}
		}
		mn = min(mn, cos + w[y] + c);
		return;
	}
	int c;
	for (int j = 1; j <= k[ln]; j++) {
		if (a[ln][j] == now) {
			c = t[ln][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k[i]; j++) {
			if (a[i][j] == now) {
				if (ln == i) {
					if (j < k[i]) {
						dfs(ln, a[i][j + 1], cos, dep + 1, 0);
					}
				} else {
					if (!huan) {
						dfs(i, now, cos + c + t[i][j], dep + 1, 1);
					}
				}
			}
		}
	}
}

signed main () {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		int ww = t[i][1] + t[i][2];
		edge[a[i][1]].push_back({a[i][2], ww});
		edge[a[i][2]].push_back({a[i][1], ww});
	}
	while (q--) {
		cin >> x >> y;
		if (c <= 3) {
			mn = 1e18;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= k[i]; j++) {
					if (a[i][j] == x) {
						dfs(i, x, w[x] + t[i][j], 0, 0);
					}
				}
			}
			cout << mn << '\n';
		} else {
			queue<int> q;
			q.push(x);
			int minn = 1e18;
			while (!q.empty()) {
				int u = q.front();
				q.pop();
				for (auto pa : edge[u]) {
					int v = pa.first;
					int w = pa.second;
					if (!dis[v]) {
						dis[v] = dis[u] + w;
						q.push(v);
					} else {
						dis[v] = min(dis[v], dis[u] + w);
					}
				}
			}
			cout << dis[y] << '\n';
		}
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
