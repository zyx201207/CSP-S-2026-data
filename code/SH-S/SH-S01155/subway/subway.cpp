#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;
const int N = 5e2 + 10;
const int M = 5e5 + 10;
ll c, n, m, d, q;
ll w[M], mp[N][N], dis[N][N];
struct edge{
	int to;
	ll w;
};
vector<edge> ee[M];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++ i)
		cin >> w[i];
	for (int i = 1; i <= n; ++ i) {
		int k; cin >> k;
		for (int j = 1; j <= k; ++ j) {
			int a, t; cin >> a >> t;
			ee[a].push_back({i, t});
		}
	} 
	
	memset(mp, 0x3f3f3f, sizeof(mp));
	for (int i = 1; i <= n; ++ i)
		mp[i][i] = 0;
	for (int i = 1; i <= m; ++ i) {
		int len = ee[i].size();
		for (int s = 0; s < len; ++ s) {
			for (int t = s + 1; t < len; ++ t) {
				int u = ee[i][s].to;
				int v = ee[i][t].to;
				ll ww = ee[i][s].w + ee[i][t].w;
				mp[u][v] = min(mp[u][v], ww);
				mp[v][u] = min(mp[v][u], ww);
			}
		}
	}
	
	memset(dis, 0x3f3f3f, sizeof(dis));
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= n; ++ j)
			dis[i][j] = mp[i][j];
	}
	for (int k = 1; k <= n; ++ k) {
		for (int i = 1; i <= n; ++ i) {
			for (int j = 1; j <= n; ++ j) 
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
		}
	}
	
	while (q --) {
		int x, y;
		cin >> x >> y;
		ll ans = 1e18;
		for (int i = 0; i < ee[x].size(); ++ i) {
			for (int j = 0; j < ee[y].size(); ++ j) {
				ll ww = dis[ee[x][i].to][ee[y][j].to] + ee[x][i].w + ee[y][j].w;
				ans = min(ans, ww);
			}
		}
		ans = ans + w[x] + w[y];
		cout << ans << "\n";
	}
	return 0;
} 
