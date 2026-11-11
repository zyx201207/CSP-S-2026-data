#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, c, T = -1, a[500005], DIS[1145][1145], S[500005], Cnt[500005], vis[500005], dist[500005], FL[500005][2],
             t[505][1030];
vector<int>b[500005];
vector<pair<int, int>>e[5000005];

void dijkstra(int s) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
	for (int i = 1; i <= m * n; i++)
		vis[i] = 0, dist[i] = 1e18;
	for (int i = 1; i <= n; i++) {
		dist[s + (i - 1)*m] = (c < 12 ? t[i][s] : T);
		q.push({dist[s + (i - 1)*m], s + (i - 1)*m});
	}
	while (!q.empty()) {
		int u = q.top().second;
		q.pop();
		if (vis[u])
			continue;
		vis[u] = 1;
		for (auto X : e[u]) {
			int v = X.first, w = X.second;
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				//if (c > 8)
				//	DIS[s][v % m] = min(DIS[s][v % m], dist[v]);
				q.push({dist[v], v});
			}
		}
	}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	int d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> a[i];
	if (c == 20 || c == 21) {
		for (int i = 1; i <= n; i++) {
			int x, y, k, lst = -1;
			cin >> k;
			while (k--) {
				cin >> x >> y;
				S[x] += y;
				Cnt[x]++;
				FL[x][i - 1] = 1;
			}
		}
		int minn = 1e18, id = -1;
		for (int i = 1; i <= m; i++)
			if (Cnt[i] == 2 && minn > S[i])
				minn = S[i];
		while (q--) {
			int u, v;
			cin >> u >> v;
			if (FL[u][0] && FL[v][0])
				cout << a[u] + a[v] << '\n';
			else if (FL[u][1] && FL[v][1])
				cout << a[u] + a[v] << '\n';
			else
				cout << a[u] + a[v] + minn << '\n';
		}
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		int x, k, y, lst = -1;
		cin >> k;
		while (k--) {
			cin >> x >> y;
			if (c < 12)
				t[i][x] = y;
			else
				T = y;
			b[x].push_back(i);
			if (lst != -1)
				e[x + (i - 1)*m].push_back({lst + (i - 1)*m, 0}), e[lst + (i - 1)*m].push_back({x + (i - 1)*m, 0});
			lst = x;
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j < b[i].size(); j++) {
			int x = b[i][j - 1], y = b[i][j];
			if (c < 12) {
				e[i + (x - 1)*m].push_back({i + (y - 1)*m, t[x][i] + t[y][i]});
				e[i + (y - 1)*m].push_back({i + (x - 1)*m, t[x][i] + t[y][i]});
			} else {
				e[i + (x - 1)*m].push_back({i + (y - 1)*m, T * 2});
				e[i + (y - 1)*m].push_back({i + (x - 1)*m, T * 2});
			}
		}
	}
	if (c > 8) {
		/*for (int i = 1; i <= m; i++)
			for (int j = 1; j <= m; j++)
				DIS[i][j] = 1e18;*/
		for (int i = 1; i <= m; i++) {
			dijkstra(i);
			for (int j = 1; j <= m; j++) {
				int ans = 1e18;
				for (int o = 1; o <= n; o++)
					ans = min(ans, dist[j + (o - 1) * m] + t[o][j]);
				DIS[i][j] = DIS[j][i] = a[i] + a[j] + ans;
			}
		}
		while (q--) {
			int u, v;
			cin >> u >> v;
			cout << DIS[u][v] << '\n';
		}
	} else {
		while (q--) {
			int u, v;
			cin >> u >> v;
			dijkstra(u);
			int ans = 1e18, id = -1;
			for (int i = 1; i <= n; i++)
				ans = min(ans, dist[v + (i - 1) * m] + t[i][v]);
			cout << a[u] + a[v] + ans << '\n';
		}
	}
	return 0;
}