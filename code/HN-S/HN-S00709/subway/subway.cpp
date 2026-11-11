#include <iostream>
#include <vector>
#include <queue>
#undef _
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

// subway.cpp

// WA!!!!!!!!!!!!
// AFO is not bad

const int N = 2e4 + 3;
const int M = 20 + 3;
const int INF = 1e9;

int n, m, d, q;
int W[N];
int tot[N];
bool vis[N];
ll dist[N];

struct edge {
	int to, w;
};
vector <edge> g[N]; 

// -1: Di Tie Kou
// 0: Zhan Ting
// 1 ~ d: Zhan Tai

inline int trans(int a, int b) {
	return (a - 1) * d + b;
}

inline void add(int a, int b, int c) {
	g[a].push_back({b, c});
	g[b].push_back({a, c});
}

int dijkstra(int s, int t) {
	priority_queue <pii> pq;
	
	for (int i = 1; i <= n; ++i) {
		vis[i] = false; dist[i] = INF;
	}
	
	dist[s] = 0;
	pq.push(make_pair(0, s));
	while (!pq.empty()) {
		int u = pq.top().second; pq.pop();
		if (u == t) break;
		if (vis[u]) continue;
		vis[u] = true;
		
		int len = g[u].size();
		for (int i = 0; i < len; ++i) {
			int v = g[u][i].to, w = g[u][i].w;
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				pq.push(make_pair(-dist[v], v));
			}
		}
	}
	
	return dist[t];
}

int main() {
	ios::sync_with_stdio(false);
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	int c;	// I'm too vegetable to use var c
	cin >> c >> n >> m >> d >> q;
	++d;
	
	for (int i = 1; i <= m; ++i) 
		cin >> W[i];
	
	for (int i = 1; i <= n; ++i) {
		int k;
		cin >> k;
		
		int last = -1;
		for (int j = 1; j <= k; ++j) {
			int a, t;
			cin >> a >> t;
			++tot[a];
			if (last != -1) add(trans(last, tot[last]), trans(a, tot[a]), 0);
			add(trans(a, tot[a]), trans(a, 0), t);
		}
	}
	
	for (int i = 1; i <= q; ++i) {
		int x, y;
		cin >> x >> y;
		cout << W[x] + W[y] + dijkstra(trans(x, 0), trans(y, 0)) << endl;
	}
	
	return 0;
} 
