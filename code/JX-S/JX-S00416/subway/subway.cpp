#include <bits/stdc++.h>
#define int long long
#define PII pair <int, int>
#define N 620231
using namespace std;
const int INF = 2e18;
const int mod = 998244353;

int c, n, m, d, q;
int w[N];
vector <PII> to[N];
int edg[521][521];

void solve(){
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++){
		int k; cin >> k;
		for(int j = 1; j <= k; j++){
			int a, t; cin >> a >> t;
			to[a].push_back({i, t}); // i is subway
		}
	}
	memset(edg, 63, sizeof edg);
	for(int i = 1; i <= n; i++) edg[i][i] = 0;
	for(int i = 1; i <= m; i++){
		int siz = to[i].size();
		for(int j = 0; j < siz; j++)
			for(int k = j + 1; k < siz; k++){
				int u = to[i][j].first;
				int v = to[i][k].first;
				int w = to[i][j].second + to[i][k].second;
				edg[u][v] = min(edg[u][v], w);
				edg[v][u] = min(edg[v][u], w);
			}
	}
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				edg[i][j] = min(edg[i][j], edg[i][k] + edg[k][j]);
	while(q--){
		int u, v; cin >> u >> v;
		int bas = w[u] + w[v];
		int res = INF;
		for(PII &pu : to[u])
			for(PII &pv : to[v]){
				int x = pu.first, y = pv.first;
				int z = pu.second + pv.second;
				res = min(res, z + edg[x][y]);
			}
		cout << bas + res << '\n';
	}			
}

signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T = 1;
	// cin >> T;
	while(T--)
		solve();
	return 0;
}
