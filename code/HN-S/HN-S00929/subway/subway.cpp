#include<bits/stdc++.h>
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define __low lower_bound
#define __upp upper_bound
#define pii pair<int,int>
#define MP make_pair
#define fi first
#define se second
#define ls (p << 1)
#define rs (p << 1 | 1)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 505, M = 5e5+5;

int c, n, m, d, q;
ll w[M];

struct pp{
	ll x, w;
};
vector<pp> ve[M];

ll dis[N][N];

void init(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++) dis[i][j] = 1e18;
		dis[i][i] = 0;
	}
}

void jian(){
	for(int i = 1; i <= m; i++){
		int sz = ve[i].size();
		for(int j = 0; j < sz; j++){
			for(int k = j+1; k < sz; k++){
				int x = ve[i][j].x, y = ve[i][k].x;
				ll ww = ve[i][j].w + ve[i][k].w;
				dis[x][y] = dis[y][x] = min(dis[x][y], ww);
			}
		}
	}
}

void flo(){
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = i+1; j <= n; j++){
				dis[i][j] = dis[j][i] = min(dis[i][j], dis[i][k] + dis[j][k]);
			}
		}
	}
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		int k, x, w;
		cin >> k;
		for(int j = 1; j <= k; j++){
			cin >> x >> w;
			ve[x].pb({i, w});
		}
	}
	init();
	jian();
	flo();
	while(q--){
		int x, y;
		cin >> x >> y;
		ll ans = 1e18;
		for(auto sx : ve[x]){
			for(auto sy : ve[y]){
				ans = min(ans, sx.w + sy.w + dis[sx.x][sy.x]);
			}
		}
		cout << ans + w[x] + w[y] << "\n";
	}
	
	return 0;
} 
