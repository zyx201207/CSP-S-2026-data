#include <bits/stdc++.h>
using namespace std;
int c , n , m , d , q , w[500005] , t[505][500005];
long long dis[505][505];
vector<int> g[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1 ; i <= m ; i++) cin >> w[i];
	for (int i = 1 ; i <= n ; i++){
		int k;
		cin >> k;
		while (k--){
			int x , y;
			cin >> x >> y;
			g[x].push_back(i);
			t[i][x] = y;
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for (int i = 1 ; i <= m ; i++){
		for (auto x : g[i]){
			for (auto y : g[i]){
				if (x == y) continue;
				dis[x][y] = min(dis[x][y],1ll*(t[x][i]+t[y][i]));
			}
		}
	}
	for (int k = 1 ; k <= n ; k++){
		for (int i = 1 ; i <= n ; i++){
			for (int j = 1 ; j <= n ; j++){
				if (i == j) continue;
				dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while (q--){
		int u , v;
		cin >> u >> v;
		long long ans = 0x3f3f3f3f3f3f3f3f;
		for (auto x : g[u]){
			for (auto y : g[v]){
				if (x == y) ans = min(ans,1ll*(t[x][u]+t[y][v]));
				else ans = min(ans,1ll*t[x][u]+dis[x][y]+1ll*t[y][v]);
			}
		}
		cout << ans+w[u]+w[v] << '\n';
	}
	return 0;
}
