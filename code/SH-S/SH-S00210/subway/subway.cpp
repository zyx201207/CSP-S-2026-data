//迪杰斯特拉 地铁路线步行时长=0 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 5e5+5;
const ll INF = 0x3f3f3f3f3f3f3f3f;

struct Node {
	int u, dist;
	bool operator > (const Node &a) const {return dist>a.dist;}
};

struct Edge {
	int w, v;
};

//dijkstra所用变量 
ll dis[MAXN*2];  //需清空 
bool vis[MAXN*2];  //需清空 
vector<Edge> g[MAXN*2];  //无向图  链式前向星
priority_queue<Node, vector<Node>, greater<Node>> q;
//其他全局变量 
int w[MAXN];  //站厅到地铁口用时 
int n, m, d, T, c;  //对应原题n, m, d, q, c 
int ind[MAXN];  //第i个地铁站站厅编号 

void link (int u, int v, int w) {
	g[u].push_back(Edge{w, v});
	g[v].push_back(Edge{w, u});
	return;
}

void init() {
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	while (!q.empty()) {
		q.pop();
	}
	return;
}

ll Dijkstra (int srt, int dst) {  //起点 终点 
	init();
	dis[srt] = 0;
	q.push(Node{srt, 0});
	while (!q.empty()) {
		Node now = q.top();
		q.pop();
		vis[now.u] = 1;
		for (auto e : g[now.u]) {
			if (vis[e.v]) continue;
			if (dis[e.v] > dis[now.u] + e.w) {
				dis[e.v] = dis[now.u] + e.w;
				q.push(Node{e.v, dis[e.v]});
			} 
		}
	}
	return dis[dst];
}

int main () {
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c;
	cin >> n >> m >> d >> T;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	int idx = 1; //站台和站厅需要进行编号 
	for (int i = 1; i <= n; i++) {
		int k; cin >> k;
		int lst = 0;
		int station = idx++;  //为站台编号 同一个路线上的站台本质上是同一个站台 
		for (int j = 1; j <= k; j++) {
			int a, t; cin >> a >> t; 
			if(ind[a] == 0) ind[a] = idx++;  //为站厅编号(如果没有) 
			link(ind[a], station, t);  //链接站台与站厅 
		}
	}
	while (T--) {
		int x, y; cin >> x >> y; 
		ll ans = w[x] + w[y];
		ans += Dijkstra(ind[x], ind[y]);
		cout << ans << "\n";
	}
	return 0;
}
