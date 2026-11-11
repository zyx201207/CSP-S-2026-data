#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5e2 + 5, M = 5e5 + 5, INF = 1e16;

struct P{
	int x, t;
};

struct Edge{
	int v, w;
};

struct Node{
	int u, d;
	
	bool operator < (const Node &i) const{
		return d > i.d;
	}
};

int c, n, m, d, q, s, w[M], vis[N], h[N][N], dis[N][N];
vector<P> st[M];
vector<Edge> g[N];

void Dij(){
	for(int i = 1; i <= n; ++i){
		vis[i] = 0;
		dis[s][i] = INF;
	}
	priority_queue<Node> pq;
	dis[s][s] = 0;
	pq.push({s, 0});
	while(!pq.empty()){
		int u = pq.top().u, d = pq.top().d;
		pq.pop();
		if(vis[u]){
			continue;
		}
		vis[u] = 1;
		for(Edge e : g[u]){
			int v = e.v, w = e.w;
			if(d + w < dis[s][v]){
				dis[s][v] = d + w;
				pq.push({v, dis[s][v]});
			}
		}
	}
}

signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; ++i){
		cin >> w[i];
	}
	for(int i = 1, k; i <= n; ++i){
		cin >> k;
		for(int j = 1, a, t; j <= k; ++j){
			cin >> a >> t;
			st[a].push_back({i, t});
		}
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			h[i][j] = INF;
		}
	}
	for(int i = 1; i <= m; ++i){
		for(int j = 0; j < st[i].size(); ++j){
			for(int k = j + 1; k < st[i].size(); ++k){
				int u = st[i][j].x, v = st[i][k].x;
				h[u][v] = min(h[u][v], st[i][j].t + st[i][k].t);
				h[v][u] = min(h[v][u], st[i][j].t + st[i][k].t);
			}
		}
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			if(h[i][j] == INF){
				continue;
			}
			g[i].push_back({j, h[i][j]});
		}
	}
	for(int i = 1; i <= n; ++i){
		s = i;
		Dij();
	}
	while(q--){
		int x, y;
		cin >> x >> y;
		int ans = INF;
		for(int i = 0; i < st[x].size(); ++i){
			for(int j = 0; j < st[y].size(); ++j){
				ans = min(ans, dis[st[x][i].x][st[y][j].x] + st[x][i].t + st[y][j].t);
			}
		}
		ans += w[x] + w[y];
		cout << ans << '\n';
	}
	return 0;
}
