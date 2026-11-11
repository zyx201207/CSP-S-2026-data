#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using PII = pair<int,i64>;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c , n , m , d , q;
	cin >> c >> n >> m >> d >> q;
	vector<int> w(m + 1);
	for(int i = 1; i <= m; i++) cin >> w[i];
	vector<vector<PII>> con(m + 1);
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++){
			int a , t;
			cin >> a >> t;
			con[a].push_back({i,t});
		}
	}
	vector<vector<i64>> mp(n + 1 , vector<i64>(n + 1 , 1e18));
	for(int i = 1; i <= n; i++){
		mp[i][i] = 0;
	}
	for(int i = 1; i <= m; i++){
		for(int l = 0; l < con[i].size(); l++){
			for(int r = 0; r < con[i].size(); r++){
				if(l == r) continue ;
				int u = con[i][l].first , v = con[i][r].first;
				i64 ut = con[i][l].second , vt = con[i][r].second;
				mp[u][v] = mp[v][u] = min(ut+vt,mp[u][v]);
			}
		}
	}
	auto dis = mp;
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				dis[i][j] = min(dis[i][j] , dis[i][k]+dis[k][j]);
			}
		}
	}
//	for(int i = 1; i <= n; i++){
//		for(int j = 1; j <= n; j++){
//			cout << dis[i][j] << ' ';
//		}
//		cout << endl;
//	}
	while(q--){
		int x , y;
		cin >> x >> y;
		i64 mx = 1e18;
		for(int i = 0; i < con[x].size(); i++){
			for(int j = 0; j < con[y].size(); j++){
				int u = con[x][i].first , v = con[y][j].first;
				i64 ut = con[x][i].second , vt = con[y][j].second;
				mx = min(mx , ut + vt + w[x] + w[y] + dis[u][v]);
			}
		}
		cout << mx << '\n';
	}
}
/*
1、把地铁线作为点，站台作为边建图
2、n^3 floyd 求出全源最短路
3、对于每个q，O(d^2) check 最终最短路 
*/
