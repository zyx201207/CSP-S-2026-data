#include <bits/stdc++.h>
#define int long long
using namespace std;
int c, n, m, d, q, t[500010], dis[510][510];
vector<pair<int, int > > v[510], g[500010];
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i=1; i<=m; i++)
		cin >> t[i];
	for (int i=1, k; i<=n; i++){
		cin >> k;
		v[i].resize(k+1);
		for (int j=1; j<=k; j++){
			cin >> v[i][j].first >> v[i][j].second;
			g[v[i][j].first].push_back({i, v[i][j].second});
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	for (int i=1; i<=n; i++)
		dis[i][i] = 0;
	for (int i=1; i<=m; i++)
		for (int u=0; u<g[i].size(); u++)
			for (int v=0; v<g[i].size(); v++)
				dis[g[i][u].first][g[i][v].first] = min(dis[g[i][u].first][g[i][v].first], g[i][u].second+g[i][v].second);
	for (int k=1; k<=n; k++)
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
	while (q--){
		int u, v;
		cin >> u >> v;
		int ans=1e18;
		for (int i=0; i<g[u].size(); i++)
			for (int j=0; j<g[v].size(); j++)
				ans = min(ans, dis[g[u][i].first][g[v][j].first]+g[u][i].second+g[v][j].second);
		cout << ans + t[u] + t[v] << '\n';
	}
}