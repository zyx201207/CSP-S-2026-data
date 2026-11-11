#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
const int N = 505;
const int M = 500005;
const ll inf = 1e16;

int c, n, m, d, q;
ll w[M];
vector<pair<int, ll> > path[M]; 
ll g[N][N], dis[N][N]; 

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)
		cin >> w[i];
	for(int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++) {
			int a;
			ll t;
			cin >> a >> t;
			path[a].push_back({i, t});
		}
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			dis[i][j] = g[i][j] = inf;
	for(int i = 1; i <= m; i++) {
		for(int a = 0; a < (int)path[i].size(); a++)
			for(int b = 0; b < a; b++) {
				int u = path[i][a].first;
				int v = path[i][b].first;
				ll du = path[i][a].second;
				ll dv = path[i][b].second;
				g[u][v] = min(g[u][v], du + dv);
				g[v][u] = min(g[v][u], du + dv);
			}
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(i == j) dis[i][j] = 0;
			else dis[i][j] = g[i][j];
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
	    			dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	while(q--) {
    	int x, y;
    	cin >> x >> y;
    	ll ans = inf;
    	for(pair<int, ll> u : path[x])
    		for(pair<int, ll> v : path[y]) {
    			ll cur = u.second + dis[u.first][v.first] + v.second;
    			ans = min(ans, cur);
			}
		ans += w[x] + w[y];
		cout << ans << endl;
	}
	return 0;
}
