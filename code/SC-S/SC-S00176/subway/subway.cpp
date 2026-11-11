#include<bits/stdc++.h>
#define LoveCyrene ios :: sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define LoveAnastasya freopen("subway.in", "r", stdin)
#define LoveOdette freopen("subway.out", "w", stdout)
#define int long long int
using namespace std;;
constexpr int N = 1e6 + 9178;
constexpr int B = 22;
constexpr int INF = 1e18;
int w[N], k[N];
vector<int> a[N], t[N];
vector<int> nde[N];

struct E{
	int v, w;
	
	friend bool operator < (E x, E y){
		return x.w > y.w; 
	};
	
};
vector<E> graph[N * B];
int dis[N], vis[N];
int tot;

void add_edge(int u, int v, int w){
	graph[u].push_back({v, w});
	graph[v].push_back({u, w});
}

void dijkstra(int n, int s){
	for (int i = 1; i <= tot; ++i) dis[i] = INF, vis[i] = 0;
	priority_queue<E> pq;
	dis[s] = 0;
	pq.push({s, 0});
	
	while(pq.size()){
		int u = pq.top().v; pq.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		
		for (auto e : graph[u]){
			int v = e.v, w = e.w;
			if(!vis[v] && dis[v] > dis[u] + w){
				dis[v] = dis[u] + w;
				pq.push({v, dis[v]});
			}
		}
	}
}

void pre(int n, int m, int d){
	tot = m;
	map<int, int> id;
	for (int i = 1; i <= n; ++i){
//		cout << "I! " << i << '\n'; 
		for (int j = 0; j < t[i].size(); ++j){
//			cout << a[i][j] << " " << t[i][j] << '\n';
			int u = ++tot;
			nde[i].push_back(u);
//			cout << "U!" << u << "AIJ!" << a[i][j] << '\n'; 
			id[u] = i;
			add_edge(u, a[i][j], t[i][j]);//每条线路的站台到大厅 
		}
	}
	for (int i = 1; i <= n; ++i){
		for (int j = 0; j + 1 < nde[i].size(); ++j){//坐地铁
			add_edge(nde[i][j], nde[i][j + 1], 0);
		}
	}
	
}

int Anastasya(int n, int x, int y){
	dijkstra(n, x);
//	for (int i = 1; i <= tot; ++i) cout << dis[i] << '\n';
	return w[x] + dis[y] + w[y];
}

signed main(){
	LoveAnastasya;
	LoveOdette;
	LoveCyrene;
	int c, n, m, d, q; cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) cin >> w[i];
	for (int i = 1; i <= n; ++i){
		cin >> k[i];
		for (int j = 1; j <= k[i]; ++j){
			int x, y; cin >> x >> y;
			a[i].push_back(x);
			t[i].push_back(y);
		}
	}
	pre(n, m, d);
	for (int i = 1; i <= q; ++i){
		int x, y; cin >> x >> y;
		cout << Anastasya(n, x, y) << '\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 61
3 2 3 3 4 5 7
1 3
1 2

32
17


*/