#include<bits/stdc++.h>
#define int long long
using namespace std;
const int Max_m = 1100, Max_n = 510;
struct S{
	int v, w;
	operator <(const S& x)const{return x.w < w;}
};
vector<S> G[Max_m];
vector<S> in[Max_m];
int c, n, m, d, q;
int a[Max_n][Max_m], t[Max_n][Max_m];
int w[Max_m], vis[Max_m], dis[Max_m];
void dij(int s){
	priority_queue<S> q;
	for(int i = 1; i <= m*(n+1); i++) dis[i] = 1e18 + 10, vis[i] = 0;
	for(auto e : in[s]){
		int j = e.v * m + s;
		dis[j] = e.w;
		q.push(S{e.v * m + s, e.w});
	}
	
	while(q.size()){
		int u = q.top().v; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(auto e : G[u]){
			int v = e.v, w = e.w;
			if(dis[u] + w < dis[v]){
				//cout << u << " "  << v << endl;
				dis[v] = dis[u] + w;
				q.push(S{v, dis[v]});
			}
		}
	}
}
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		int k; cin >> k;
		for(int j = 1, x, y; j <= k; j++){
			cin >> x >> y; 
			a[i][j] = x, t[i][j] = y;
			in[x].push_back(S{i, t[i][j]});
			if(j != 1){
				G[a[i][j-1] + i * m].push_back(S{x + i * m, 0});
				G[x+i*m].push_back(S{a[i][j-1]+i*m, 0});
			//	cout << a[i][j-1] + i * m << " " << x + i * m << endl; 
			}
		}
	}
	for(int i = 1; i <= m; i++){
		for(auto e : in[i]){
			for(auto ee : in[i]){
				if(e.v == ee.v) continue ;
				int u = e.v * m + i, v = ee.v * m + i, w = e.w + ee.w;
				G[u].push_back(S{v, w});
				G[v].push_back(S{u, w});
			}
		}
	}
	for(int i = 1, u, v; i <= q; i++){
		cin >> u >> v;
		dij(u);
		int ans = 1e18 + 10;
		for(auto e : in[v]){
		//	cout << dis[e.v * m + v] << " ";
			ans = min(ans, dis[e.v * m + v]+t[e.v][v] + w[v]);
		}
		cout << ans + w[u] << "\n";
	}
	return 0;
}