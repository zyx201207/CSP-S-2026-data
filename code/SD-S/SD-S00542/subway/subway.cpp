#include<bits/stdc++.h>
#define ll long long
#define For(i, j, k) for(int i=j;i<=k;i++)
using namespace std;

int c, n, m, d, q;
ll w[500005];
int k[505];
ll dis[505][505];//线与线的路程 

struct edge{
	int ii;
	ll t;
};
vector<edge>e[500005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	For(i, 1, m) cin >> w[i];
	For(i, 1, n){
		cin >> k[i];//一条线经过站
		For(j, 1, k[i]){
			int a;
			ll t;
			cin >> a >> t;
			e[a].push_back({i,t});//站a有i线 
		} 
	}
	memset(dis, 0x3f, sizeof dis);
	For(i, 1, n) dis[i][i] = 0;
	For(i, 1, m){
		int mm = e[i].size();
//		cout << i << " " << mm << "\n";
//		for(auto kk : e[i])cout << kk.ii << " ";
//		cout << "\n";
		For(j, 0, mm-1){
			For(k, j+1, mm-1){
				int u = e[i][j].ii;
				int v = e[i][k].ii;
				ll tu = e[i][j].t;
				ll tv = e[i][k].t;
				dis[u][v] = min(dis[u][v], tu+tv);
				dis[v][u] = min(dis[u][v], tu+tv);
			}
		}
	}
	For(k, 1, n){
		For(i, 1, n){
			For(j, 1, n){
				dis[i][j] = min(dis[i][k]+dis[k][j], dis[i][j]);
			}
		}
	}
	For(i, 1, q){
		int u, v;
		cin >> u >> v;
		ll ans = 0x3f3f3f3f3f3f3f3f;
		for(auto j : e[u]){
			for(auto k : e[v]){
				ans = min(ans, w[u]+w[v]+j.t+k.t+dis[j.ii][k.ii]);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7

*/ 
