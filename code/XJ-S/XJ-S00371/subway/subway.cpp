#include <bits/stdc++.h>
using namespace std;
const int MAXN = 501;
int c, n, m, d, q;
//先权值后节点 
struct vec2 {
	int x, y;
	bool operator> (const vec2& other) const {
		if (x != other.x) return x > other.x;
		return y > other.y;
	}
	bool operator< (const vec2& other) const {
		if (x != other.x) return x < other.x;
		return y < other.y;
	}
};

struct Node {
	vector<vec2> next;
}a[MAXN];

int w[MAXN];

int dijkstra(int s, int e) {
	bool st[MAXN];
	int dis[MAXN];
	for (int i = 1;i <= m;i++) {
		st[i] = false, dis[i] = 1e9;
	}
	priority_queue<vec2, vector<vec2>, greater<vec2> > pq;
	pq.push({0, s});
	while(pq.empty()) {
		vec2 t = pq.top();
		int d = t.x;
		int u = t.y;
		if (st[u]) continue;
		st[u] = true;
		pq.pop();
		for (int ni = 0; ni < a[u].next.size();ni++) {
			vec2 nv = a[u].next[ni];
			int nu = nv.y;
			int nd = nv.x;
			if (st[nu]) continue;
			if (nd + d < dis[nu]) {
				dis[nu] = nd + d;
				pq.push({dis[nu], nu});
			}
		}
	}
	return dis[e];
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++) {
		cin >> w[i];
	}
	for (int i = 1;i <= n;i++) {
		int k;
		cin >> k;
		vector<vec2> way;
		for (int j = 0;j < k;j++) {
			int id, t;
			cin >> id >> t;	
			way.push_back({t, id});	
		}
		for (int j = 1;j < k;j++) { 
			a[way[j].y].next.push_back({way[j - 1].x + way[j].x, way[j - 1].y});
			a[way[j - 1].y].next.push_back({way[j - 1].x + way[j].x, way[j].y});
		}
	}
	while(q--) {
		int s, e;
		cin >> s >> e;
		cout << dijkstra(s, e) + w[s] + w[e] << '\n';
	}
	return 0;
}
