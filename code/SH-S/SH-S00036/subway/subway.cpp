#include<bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const int MAXN = 505;
const int MAXM = 5e5 + 5;
vector<pair<int, long long> > res[MAXM];
vector<pair<int, long long> > path[MAXN];
long long w[MAXM], dist[MAXN][MAXN];

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i)
		cin >> w[i];
	for (int i = 1; i <= n; ++i){
		int k;
		cin >> k;
		for (int j = 1; j <= k; ++j){
			int a;
			long long t;
			cin >> a >> t;
			res[a].push_back({i, t});
			path[i].push_back({a, t});
		}
	}
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= n; ++j){
			if (i == j)
				continue;
			dist[i][j] = INF;
		}
	}
	for (int i = 1; i <= n; ++i){
		for (auto e_u : path[i]){
			int u = e_u.first;
			long long w_u = e_u.second;
			for (auto e_v : res[u]){
				int v = e_v.first;
				long long w_v = e_v.second;
				if (i == v)
					continue;
				dist[i][v] = min(dist[i][v], w_u + w_v);
			}
		}
	}
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); 
	while (q--){
		int x, y;
		cin >> x >> y;
		long long ans = INF;
		for (auto e_u : res[x]){
			int u = e_u.first;
			long long w_u = e_u.second;
			for (auto e_v : res[y]){
				int v = e_v.first;
				long long w_v = e_v.second;
				ans = min(ans, dist[u][v] + w_u + w_v);
			}	
		}
		ans += w[x] + w[y];
		cout << ans << '\n';
	}
}
