#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505;
int k[N];
const int M = 5e5 + 5;
const int INF = 1e18;
vector<pair<int, int>> g[M + N];
int  w[M];
int vis[M + N];
int c, n, m, d, Q;
int dis[M + N];
void dijk(int u){
	for(int i = 1; i <= n + m; i++){
		vis[i] = 0;
		dis[i] = INF;
	}
		
	dis[u] = 0;
	queue<pair<int, int>> q;
	q.push({u, 0});
	for(auto cur : g[u]){
		int v = cur.first;
		int w = cur.second;
		q.pop();
		if(vis[v]) continue;
		vis[v] = 1;
		if(dis[u] + w < dis[v]){
			dis[v] = dis[u] + w;
			q.push({v, dis[v]});
		}
	}
	return ;
}
signed main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	cin >> c >> n >> m >> d >> Q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++){
			int a, t;
			cin >> a >> t;
			g[m + i].push_back({a, t});
			g[a].push_back({i + m, t});
		}
	}
	while(Q--){
		int x, y;
		cin >> x >> y;
		int ans = w[x] + w[y];
		dijk(x);
		cout << ans + dis[y] << "\n";
	}
	return 0;
}