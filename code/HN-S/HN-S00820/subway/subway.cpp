#include <bits/stdc++.h>
#define int long long

using namespace std;
using pii = pair<int, int>;

const int N = 505, M = 5e5 + 5, INF = 1e18;

struct Node {
	int v, w, op;
	bool operator <(const Node &i) const {
		return w > i.w;
	}
};

int c, n, m, d, q, k[N], w[M], dist[N][N];
vector<pii> G[M];
bool vis[N];

void Floyd () {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min (dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

signed main() {
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	ios::sync_with_stdio (false);
	cin.tie (0), cout.tie (0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dist[i][j] = INF;
		}
		dist[i][i] = 0;
	}
	for (int I = 1; I <= n; I++) {
		cin >> k[I];
		for (int i = 1, a, t; i <= k[I]; i++) {
			cin >> a >> t;
			G[a].push_back (make_pair(I, t));
		}
	}
	for (int i = 1; i <= m; i++) {
		if (G[i].size() > 1) {
			for (int j = 0; j < G[i].size(); j++) {
				int v = G[i][j].first, t = G[i][j].second;
				for (int k = j + 1; k < G[i].size(); k++) {
					int v2 = G[i][k].first, t2 = G[i][k].second;
					dist[v][v2] = dist[v2][v] = min (dist[v][v2], t + t2);
				}
			}
		}
	}
	Floyd ();
	while (q--) {
		int x, y; cin >> x >> y;
		int Ans = INF;
		for (int j = 0; j < G[x].size(); j++) {
			int v = G[x][j].first, t = G[x][j].second;
			for (int k = 0; k < G[y].size(); k++) {
				int v2 = G[y][k].first, t2 = G[y][k].second;
				Ans = min (Ans, dist[v][v2] + t + t2);
			}
		}
		cout << w[x] + w[y] + Ans << '\n';
	}
	return 0;
}
/*
2026.10.31 16:12
100 pts?
*/
