#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int w[N], k[N];
typedef long long ll;
struct st{
	int u; 
	ll w;
};
vector<st> g[N];
int c, n, m, d, q;
ll totol = 0;
ll dist[N];
bool vis[N];
bool cmp(st a, st b) { 
      return a.w < b.w; 
}
ll bfs(int u, int end){
	 priority_queue<st, vector<st>, cmp> pq;
	 memset(dist, 0x3f, sizeof(dist));
	 dist[u] = w[u];
	 pq.push({u, 0});
	 int root = 0;
	 while(!q.empty()){	 
	 for(auto [v, w] : g[u]){
	 	if(vis[v]) continue;
	 	vis[v] = true;
	 	if(dist[v] > dist[u] + w){
	 		dist[v] = dist[u] + w;
	 		pq.push({v, g[v].w});
		 }
	 }
}
	 return dist[end];
}
int main(){
	//freopen("subway.in", "r", stdin);
	//freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q; // 地铁线路数， 地铁站数，max, 出行计划数 
	for(int i = 1; i <= m; i++) cin >> w[i];
	vector<st> m;
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++){
			int x, w;
			cin >> x >> w;
		    m.push_back({x, w});
	}
	    for(int j = 0; j < m.size() - 1; j++){
	    	for(int i = j + 1; i < m.size(); i++){
	    		g[m[i].u].push_back({g[m[j].u], m[j]});
			}
		}
	}
	while(q--){
		int x, y; cin >> x >> y;
		int ans = 0
		ans = w[x] + w[y];
		cout << ans + bfs(x, y) << endl;
	}
	return 0;
}
