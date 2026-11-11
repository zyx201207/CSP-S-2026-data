#include<bits/stdc++.h>
#define ll long long
#define maxn 500005
#define INFint (int)(1e9 + 5)
#define INFll (long long)(1e18 + 5)
#define ull unsigned long long
using namespace std;

int c,n,m,d,q;
ll w[maxn];
int k[505];
vector<pair<int,ll> > z[maxn];
ll dis[505][505];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;++ i) cin >> w[i];
	for(int i = 1;i <= n;++ i){
		cin >> k[i];
		for(int j = 1;j <= k[i];++ j){
			int a;
			ll t;
			cin >> a >> t;
			z[a].push_back({i,t});
		}
	}
	for(int i = 1;i <= n;++ i){
		for(int j = 1;j <= n;++ j){
			dis[i][j] = INFll;
			if(i == j) dis[i][j] = 0;
		}
	}
	for(int i = 1;i <= m;++ i){
		for(int o1 = 0;o1 < z[i].size();++ o1){
			for(int o2 = o1 + 1;o2 < z[i].size();++ o2){
				int p1 = z[i][o1].first;
				ll t1 = z[i][o1].second;
				int p2 = z[i][o2].first;
				ll t2 = z[i][o2].second;
				dis[p1][p2] = min(dis[p1][p2],t1 + t2);
				dis[p2][p1] = min(dis[p2][p1],t1 + t2);
			}
		}
	}
	for(int k = 1;k <= n;++ k){
		for(int i = 1;i <= n;++ i){
			if(dis[i][k] == INFll) continue;
			for(int j = 1;j <= n;++ j){
				if(dis[k][j] == INFll) continue;
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
			}
		}
	}
	while(q --){
		int xr,yr;
		cin >> xr >> yr;
		ll ans = INFll;
		for(int ix = 0;ix < z[xr].size();++ ix){
			for(int iy = 0;iy < z[yr].size();++ iy){
				int p1 = z[xr][ix].first;
				ll t1 = z[xr][ix].second;
				int p2 = z[yr][iy].first;
				ll t2 = z[yr][iy].second;
				ans = min(ans,t1 + t2 + dis[p1][p2]);
			}
		}
		cout << ans + w[xr] + w[yr] << "\n";
	}

	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
