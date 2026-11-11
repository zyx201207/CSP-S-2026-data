#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int maxn = 5e2 + 10, maxm = 5e5 + 10, maxd = 25;
const ll INF = 1e17;

struct Node{
	ll v, t; //v经过的站台，表示所耗时间 
	bool operator< (const Node &x) const{
		return t > x.t;
	}
};

int c, n, m, d, q;
ll w[maxn];
vector<Node> adj[maxn * 2];
ll dist[maxn][maxn + maxd];

void dijkastr(int s){
	priority_queue<Node> pq;
	pq.push({s, 0});
	dist[s][s] = 0;
	while(!pq.empty()){
		int u = pq.top().v, t = pq.top().t;
		pq.pop();
		for(Node v : adj[u]){
			if(dist[s][v.v] != INF)continue;
			dist[s][v.v] = dist[s][u] + v.t;
			pq.push({v.v, dist[s][v.v]});
		}
	} 
}


int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= m + d; j++){
			dist[i][j] = INF;
		}
	}

	for(int i = 1, k; i <= n; i++){
		cin >> k;
		for(int j = 1, v, t1; j <= k; j++){
			cin >> v >> t1;
			adj[i + m].push_back({v, t1});
			adj[v].push_back({i + m, t1});
		}
	}
	
	for(int i = 1; i <= m; i++){
		dijkastr(i);
	}

	for(int i = 1, x, y; i <= q; i++){
		cin >> x >> y;
		cout << dist[x][y] + w[x] + w[y] << '\n';
	}
	
	return 0;
}
