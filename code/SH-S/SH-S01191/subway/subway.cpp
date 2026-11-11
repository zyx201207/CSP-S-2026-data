#include <bits/stdc++.h>
using namespace std;

struct node{
	int x, w;
};

bool operator<(node u, node v){
	return u.w > v.w;
}

int c, n, m, d, q;
int a[1000010];
bool vis[1000010];
int dis[1000010];
vector<node> g[1000010];

void bfs(int x){
	memset(dis, 0x3f, sizeof dis);
	queue<int> q;
	q.push(x);
	dis[x] = 0;
	
	while (!q.empty()){
		int u = q.front();
		q.pop();
		
		for (auto v : g[u]){
			if (dis[v.x] > dis[u] + v.w){
				dis[v.x] = dis[u] + v.w;
				q.push(v.x);
			}
		}
	}
}

void dijkstra(int x){
	memset(vis, false, sizeof vis);
	memset(dis, 0x3f, sizeof dis);
	priority_queue<node> q;
	q.push({x, 0});
	dis[x] = 0;
	
	while (!q.empty()){
		int u = q.top().x;
		q.pop();
		
		if (vis[u]) continue;
		vis[u] = true;
		
		for (auto v : g[u]){
			if (dis[v.x] > dis[u] + v.w){
				dis[v.x] = dis[u] + v.w;
				q.push({v.x, dis[v.x]});
			}
		}
	}
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> a[i];
	for (int i = 1; i <= n; i++){
		int k;
		cin >> k;
		vector<node> t;
		while (k--){
			int x, w;
			cin >> x >> w;
			//g[m+i].push_back({x, w});
			//g[x].push_back({m+i, w});
			t.push_back({x, w});
		}
		for (int u = 0; u < t.size(); u++){
			for (int v = u+1; v < t.size(); v++){
				g[t[u].x].push_back({t[v].x, t[u].w+t[v].w});
				g[t[v].x].push_back({t[u].x, t[u].w+t[v].w});
			}
		}
	}
	
	while (q--){
		int x, y;
		cin >> x >> y;
		if (c < 12){
			dijkstra(x);
			cout << dis[y] + a[x] + a[y] << endl;
		}else{
			bfs(x);
			cout << dis[y] + a[x] + a[y] << endl;
		}
	}
	return 0;
}
