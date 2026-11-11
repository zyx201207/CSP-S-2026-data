#include <bits/stdc++.h>
#define ll long long
using namespace std;
int c, n, m, d, q, k, a, t[21][500001], w[500001];
ll dis[501][501], e[501][501];
vector <int> xl[500001];
struct STR{
	int v;
	ll w;
	friend bool operator < (STR a, STR b) {
		return a.w > b.w;
	}
};
vector <STR> g[505];
priority_queue <STR> pq;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout); 
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) cin >> w[i];
	memset(e, 0x3f, sizeof(e));
	for (int i = 1; i <= n; ++i) {
		cin >> k;
		for (int j = 1; j <= k; ++j) {
			cin >> a;
			cin >> t[xl[a].size()][a];
			for (int o = 0; o < xl[a].size(); ++o) 
				e[i][xl[a][o]] = min(e[i][xl[a][o]], (ll)t[xl[a].size()][a] + (ll)t[o][a]);
			xl[a].push_back(i);
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1; i <= n; ++i) dis[i][i] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < i; ++j) {
			if (e[i][j] != 4557430888798830399) {
				g[i].push_back({j, e[i][j]});
				g[j].push_back({i, e[i][j]});
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		pq.push({i, 0});
		while (!pq.empty()) {
			STR tp = pq.top();
			pq.pop();
			int u = tp.v;
			for (int j = 0; j < g[u].size(); ++j) {
				int v = g[u][j].v;
				ll w = g[u][j].w;
				if (dis[i][u] + w < dis[i][v]) {
					dis[i][v] = dis[i][u] + w;
					pq.push({v, dis[i][v]});
				}
			}
		}
	}
	while (q--) {
		int u, v;
		ll ans = 4557430888798830399;
		cin >> u >> v;
		for (int i = 0; i < xl[u].size(); ++i) 
			for (int j = 0; j < xl[v].size(); ++j) 
				ans = min(ans, dis[xl[u][i]][xl[v][j]] + (ll)t[i][u] + (ll)t[j][v]);
		cout << ans + (ll)w[u] + (ll)w[v] << "\n";
	}
	return 0;
} 

