/*
坏了，这题我也不会了。。。

胡了个 60 分做法 
*/
#include<bits/stdc++.h>
#define Hahaha using
#define I namespace
#define AK std
#define IOI ;
#define ll long long
#define N (int)(5e5 + 10)
#define M (int)(2e3 + 10)
Hahaha I AK IOI
ll dis[M][M], w[N], k[N], x[N], y[N];
ll c, n, m, d, q, id;
bool vis[N];

struct Node{
	ll v, w;
	bool operator < (const Node &x) const{
		return w > x.w;
	}
};
vector<Node> g[N];

void dij(int idd){
	for(int i = 1; i <= id; i++){
		dis[idd][i] = 1e18;
	}
	priority_queue<Node> q;
	q.push({idd, 0});
	while(q.size()){
		int u = q.top().v;
		ll s = q.top().w;
		q.pop();
		if(s >= dis[idd][u]){
			continue;
		}
		dis[idd][u] = s;
		for(auto x : g[u]){
			int v = x.v;
			ll c = x.w;
			if(dis[idd][u] + c < dis[idd][v]){
//				cout << u << " " << v << " " << c << "\n"; 
				q.push({v, dis[idd][u] + c});
			}
		}
	}
}

int bfs(int x, int y){
	for(int i = 1; i <= id; i++){
		vis[i] = 0;
	}
	deque<Node> q;
	q.push_back({x, 0});
	while(q.size()){
		int u = q.front().v;
		ll s = q.front().w;
		q.pop_front();
		vis[u] = 1;
		if(u == y){
			return s;
		}
		for(auto x : g[u]){
			int v = x.v;
			ll c = x.w;
			if(!vis[v]){
				if(c){
					q.push_back({v, s + c});
				}else{
					q.push_front({v, s});
				}
			}
		}
	}
	return 114514;
}

void work(){
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	if(c <= 11){
		id = m;
		for(int i = 1; i <= n; i++){
			cin >> k[i];
			for(int j = 1; j <= k[i]; j++){
				cin >> x[j] >> y[j];
				g[x[j]].push_back({++id, y[j]});
				g[id].push_back({x[j], y[j]});
				if(j != 1){
					g[id - 1].push_back({id, 0});
					g[id].push_back({id - 1, 0});
				}
			}
		}
		for(int i = 1; i <= m; i++){
			dij(i);
//			for(int j = 1; j <= m; j++){
//				cout << dis[i][j] << " ";
//			}
//			cout << "\n";
		}
		while(q--){
			int x, y;
			cin >> x >> y;
			cout << w[x] + w[y] + dis[x][y] << "\n";
		}
	}else if(c <= 15){
		id = m;
		for(int i = 1; i <= n; i++){
			cin >> k[i];
			for(int j = 1; j <= k[i]; j++){
				cin >> x[j] >> y[j];
				g[x[j]].push_back({++id, y[j]});
				g[id].push_back({x[j], y[j]});
				if(j != 1){
					g[id - 1].push_back({id, 0});
					g[id].push_back({id - 1, 0});
				}
			}
		}
		while(q--){
			int x, y;
			cin >> x >> y;
			cout << w[x] + w[y] + bfs(x, y) << "\n";
		}
	}else{
		
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int oT_To = 1;
//	cin >> oT_To;
	while(oT_To--){
		work();
	}
	return 0;
}
