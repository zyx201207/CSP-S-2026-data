#include <bits/stdc++.h>
using namespace std;
#define int long long
int const N = 5e5 + 5, M = 1e3 + 5;
int c, n, m, d, qus, k;
int a[N], t[N];
int w[N], dis[M][M], inq[M];
vector<pair<int, int> > G[N];
queue<int> q;

void spfa(int s) {
	for (int i = 1; i <= m; i++)
		dis[s][i] = 1e15;
	inq[s] = 1, dis[s][s] = 0;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		inq[u] = 0;
		for (auto xx : G[u]) {
			int v = xx.first, w = xx.second;
			if (dis[s][v] > dis[s][u] + w) {
				dis[s][v] = dis[s][u] + w;
				if (!inq[v]) {
					q.push(v);
					inq[v] = 1;
				}
			}
		}
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> qus;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	if (c <= 11) {
		for (int i = 1; i <= n; i++) {
			cin >> k;
			for (int j = 1; j <= k; j++)
				cin >> a[j] >> t[j];
			for (int j = 1; j <= k; j++)
				for (int l = j + 1; l <= k; l++) {
					int u = a[j], v = a[l], w = t[j] + t[l];
					G[u].push_back({v, w});
					G[v].push_back({u, w});
				}
		}
		for (int i = 1; i <= m; i++)
			spfa(i);
		for (int i = 1; i <= qus; i++) {
			int u, v;
			cin >> u >> v;
			cout << w[u] + w[v] + dis[u][v] << '\n';
		}
	}
	return 0;
}
