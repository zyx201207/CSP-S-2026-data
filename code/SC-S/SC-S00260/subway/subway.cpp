#include<bits/stdc++.h>
using namespace std;
#define int long long
int dis[510][510] , w[500010];
vector<pair<int , int>> p[500010];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	int c , n , m , d , q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++){
			int x , y;
			cin >> x >> y;
			p[x].push_back({i , y});
		}
	}
	memset(dis , 0x7f , sizeof dis);
	for(int i = 1; i <= m; i++){
		for(auto v : p[i]){
			for(auto u : p[i]){
				if(u == v) continue;
				dis[u.first][v.first] = min(dis[u.first][v.first] , u.second + v.second);
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i == j) dis[i][j] = 0;
			dis[i][j] = min(dis[i][j] , dis[j][i]);
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			for(int k = 1; k <= n; k++){
				if(dis[j][i] + dis[i][k] < 0) continue;
				dis[j][k] = min(dis[j][k] , dis[j][i] + dis[i][k]);
			}
		}
	}
	while(q--){
		int u , v , ans = 1e18;
		cin >> u >> v;
		for(auto uu : p[u]){
			for(auto vv : p[v]){
				ans = min(ans , dis[uu.first][vv.first] + uu.second + vv.second);
			}
		}
		cout << ans + w[u] + w[v] << "\n";
	}
	return 0;
}