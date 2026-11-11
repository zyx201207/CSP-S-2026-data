#include<bits/stdc++.h>
#define pi pair<int, int>
#define int long long
using namespace std;
const int N = 505;
const int M = 5e5 + 5;
int c, n, m, d, q, w[M], k[N], dis[N][N];

vector<pi> mp[M];

signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++){
			int v, w;
			cin >> v >> w;
			mp[v].push_back({i, w});
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	for(int i = 1; i <= n; i++) dis[i][i] = 0;
	for(int i = 1; i <= m; i++){
		for(int j = 0; j < mp[i].size(); j++){
			for(int k = 0; k < mp[i].size(); k++){
				int u = mp[i][j].first;
				int v = mp[i][k].first;
				int w = mp[i][j].second + mp[i][k].second;
				dis[u][v] = min(dis[u][v], w);
				dis[v][u] = min(dis[v][u], w);
			}
		}
	}
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	while(q--){
		int x, y;
		cin >> x >> y;
		int ans = 1e18;
		for(auto u : mp[x]){
			for(auto v : mp[y]){
				ans = min(ans, u.second + v.second + dis[u.first][v.first]);
			}
		}
		cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}

//15:32
//好像有点卡常
//@DanseSolo 姐姐可爱喵 