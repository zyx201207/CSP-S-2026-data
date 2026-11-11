#include <bits/stdc++.h>
using namespace std;
using ll = long long; using ull = unsigned long long;

constexpr int MAXN = 500 + 10;
int n, m, d, q;
ll w[MAXN];

namespace Sub1 {

constexpr int MAXC = 5000 + 10;
struct Edge {
	int v; ll w;
	Edge() {}
	Edge(int _v, ll _w): v(_v), w(_w) {}
};
ll dis[MAXC][MAXC];
bool vis[MAXC];
void Dijstra(vector<vector<Edge> > &G, int s) {
	using Node = pair<ll, int>;
	
	priority_queue<Node, vector<Node>, greater<> > q;
	dis[s][s] = 0;
	vis[s] = 1;
	q.emplace(0, s);
	while(!q.empty()) {
		Node tu = q.top(); q.pop();
		int u = tu.second;
		for(Edge tv : G[u]) {
			ll vw = tv.w; int v = tv.v;
			if(vis[v]) continue;
			vis[v] = 1;
			if(dis[s][u] + vw < dis[s][v]) {
				dis[s][v] = dis[s][u] + vw;
				q.emplace(dis[s][v], v);
			}
		}
	}
}
void solve() {
	int cnt = n + m;
	vector<vector<Edge> > G(cnt + 1); // 邻接表 
	for(int i = 1, k; i <= n; ++i) {
		cin >> k;
		G[m + i].reserve(k + 1);
		for(int j = 1, a, t; j <= k; ++j) {
			cin >> a >> t;
			G[m + i].emplace_back(a, t);
			G[a].emplace_back(m + i, t);
//			cerr << a << " " << m + i << " " << t << "\n";
		}
	}
	/*for(int i = 1; i <= cnt; ++i) {
		for(auto v : G[i])
			cerr << i << " " << v.v << " " << v.w << "\n";
	}*/
	for(int i = 1; i <= q; ++i) {
		int x, y;
		cin >> x >> y;
		if(!dis[x][0]) {
			dis[x][0] = 1;
			fill(dis[x] + 1, dis[x] + 1 + cnt, 0x3f3f3f3f3f3f3f3f);
			fill(vis + 1, vis + 1 + cnt, 0);
			Dijstra(G, x);
		}
		cout << dis[x][y] + w[x] + w[y] << "\n";
	}
}

} // 点数较多时（Dijstra，m(n+m)log(sum k)） 

namespace Sub2 {

constexpr int MAX = 500000 + 10;
vector<int> st[MAXN]; // st[i][j]：i 号线下所有车站
vector<int> li[MAX]; // li[i][j]：i 车站所属的线路 
bool vis1[MAX], vis2[MAXN];
int dis[MAX];

int BFS(int s, int t) {
	queue<int> q;
	dis[s] = 0;
	vis1[s] = 1;
	q.push(s);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(int v : li[u]) {
			if(vis2[v]) continue;
			vis2[v] = 1;
			for(int x : st[v]) {
//				cerr << u << " " << v << " " << x << "\n";
				if(vis1[x]) continue;
				vis1[x] = 1;
				dis[x] = dis[u] + 1;
				if(x == t)
					return dis[x];
				q.push(x);
			}
		} 
	}
	return -1;
}

void solve() {
	ll W;
	for(int i = 1, k; i <= n; ++i) {
		cin >> k;
		st[i].reserve(k + 1);
		for(int j = 1, a; j <= k; ++j) {
			cin >> a >> W;
			st[i].emplace_back(a);
		}
	}
	for(int i = 1; i <= n; i++) {
		for(auto v : st[i]) li[v].emplace_back(i);
	}
	
	/*for(int i = 1; i <= n; i++) {
		for(auto v : st[i])
			cout << v << " ";
		cout << "\n";
	}
	cout << "\n";
	for(int i = 1; i <= m; i++) {
		for(auto v : li[i])
			cout << v << " ";
		cout << "\n";
	}*/
	for(int i = 1; i <= q; ++i) {
		fill(dis + 1, dis + 1 + m, 0);
		fill(vis1 + 1, vis1 + 1 + m, 0);
		fill(vis2 + 1, vis2 + 1 + m, 0);
		int x, y;
		cin >> x >> y;
		cout << W * BFS(x, y) * 2 + w[x] + w[y] << "\n";
	}
}

} // 特殊性质 B 

int main() {
	freopen("subway.in", "r", stdin), freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int c;
	cin >> c >> n >> m >> d >> q; // n 地铁线路数，m 地铁站数 
	for(int i = 1; i <= m; ++i) cin >> w[i];
	
	if(12 <= c && c <= 19)
		Sub2::solve();
	else
		Sub1::solve();
	return 0;
}

