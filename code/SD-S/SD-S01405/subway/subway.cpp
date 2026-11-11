#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using i64 = long long;
using pii = pair<int, int>;

const int N = 505, M = 5E5 + 10;

int c, n, m, d, q;
int w[M];
i64 dist[N][N];
vector<pii> g[M];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	
	memset(dist, 0x3f, sizeof dist);
	for (int i = 1; i <= n; i ++) dist[i][i] = 0;
	for (int i = 1; i <= m; i ++)
		cin >> w[i];
		
	for (int i = 1; i <= n; i ++) {
		int len;
		cin >> len;
		for (int j = 1; j <= len; j ++) {
			int u, t;
			cin >> u >> t;
			g[u].emplace_back(i, t);
		}
	}
	
	for (int i = 1; i <= m; i ++)
		for (auto j : g[i]) {
			int x = j.fi, y = j.se;
			for (auto k : g[i]) {
				int p = k.fi, q = k.se;
				dist[p][x] = dist[x][p] = min(dist[x][p], (i64)y + q);
			}
		}
	
	for (int k = 1; k <= n; k ++)
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				
	while (q -- ) {
		int s, t;
		cin >> s >> t;
		
		i64 res = 1ll << 60;
		for (auto i : g[s]) {
			int x = i.fi, y = i.se;
			for (auto j : g[t]) {
				int p = j.fi, q = j.se;
				res = min(res, dist[x][p] + y + q + w[s] + w[t]);
			}
		}
		
		cout << res << '\n';
	}
	
	return 0;
}

