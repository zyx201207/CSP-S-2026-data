#include <bits/stdc++.h>
#define int long long 
#define INF 100000000000000000

using namespace std;

int c, n, m, d, r;
int a[500001];
int dis[5001][5001];
vector<int> g_1[501];
vector<pair<int, int> > h[500001];
vector<pair<int, int> > g[500001];
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	memset(dis, 0x3f, sizeof(dis));
	cin >> c >> m >> n >> d >> r;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= m; i++) {
		int k, f_1, t_1;
		cin >> k;
		for(int i = 1; i <= k; i++) {
			cin >> f_1 >> t_1;
			g_1[i].push_back(f_1);
			h[f_1].push_back({i, t_1});
		}
	}
	for(int i = 1; i <= n; i++) {
		bool vis = 0;
		for(auto c : h[i]) {
			for(int x : g_1[c.first]) {
				if (x == i) vis = 1; 
				if (vis) g[i].push_back({x, c.second});
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		for(auto c : g[i]) {
			dis[i][c.first] = min(dis[i][c.first], c.second);
		}
	}
	
	for(int j = 1; j <= n; j++) {
		dis[j][j] = 0;
	}
	
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	
	while(r--) {
		int u, v;
		cin >> u >> v;
		cout << dis[u][v] + a[u] + a[v] + g[v][0].second<< "\n";
	}
	return 0;	
}