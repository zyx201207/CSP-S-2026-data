#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf = 0x3f3f3f3f3f3f3f3f;
int C, n, m, d, q, w[1000005], dis[1005][1005];
vector<pair<int, int> > g[1000005];
void Solve(int Case){
	cin >> n >> m >> d >> q; memset(dis, 0x3f, sizeof(dis)); for(int i = 1; i <= n; i ++) dis[i][i] = 0;
	for(int i = 1; i <= m; i ++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i ++){
		int len; cin >> len;
		for(int j = 1; j <= len; j ++){
			int x, y; cin >> x >> y;
			g[x].push_back({m + i, y});
			g[m + i].push_back({x, y});
		}
	}
	for(int i = 1; i <= m; i ++){
		for(int j = 0; j < g[i].size(); j ++){
			for(int k = j + 1; k < g[i].size(); k ++){
				dis[g[i][j].first - m][g[i][k].first - m] = dis[g[i][k].first - m][g[i][j].first - m] = min(dis[g[i][j].first - m][g[i][k].first - m], g[i][j].second + g[i][k].second);
			}
		}
	}
	for(int k = m + 1; k <= m + n; k ++){
		for(int i = m + 1; i <= m + n; i ++){
			for(int j = m + 1; j <= m + n; j ++){
				dis[i - m][j - m] = min(dis[i - m][j - m], dis[i - m][k - m] + dis[k - m][j - m]);
			}
		}
	}
	while(q --){
		int u, v; cin >> u >> v; int ans = inf;
		for(int i = 0; i < g[u].size(); i ++){
			for(int j = 0; j < g[v].size(); j ++){
				ans = min(ans, dis[g[u][i].first - m][g[v][j].first - m] + g[u][i].second + g[v][j].second + w[u] + w[v]);
			}
		}
		cout << ans << "\n";
	}
}
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> C;
	for(int i = 1; i <= t; i ++){
		Solve(i);
	}
	return 0;
}
