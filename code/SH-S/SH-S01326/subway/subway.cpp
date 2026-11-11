#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int M = 5e5+7;
const int INF = 0x3f;

int c, n, m, d, q;
ll t[M], dis[M];
bool in_queue[M];

vector <pair<int, int> > adj, edgs[M];

void build() {
	for(auto p1 : adj) {
		int u = p1.first, w1 = p1.second;
		for(auto p2 : adj) {
			int v = p2.first, w2 = p2.second;
			if(u == v)
				continue;
			edgs[u].emplace_back(v, w1+w2);
			edgs[v].emplace_back(u, w1+w2);
		}
	}
	return;
}

void dijkstra(int s) {
	priority_queue <pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	
	dis[s] = 0;
	pq.push(make_pair(dis[s], s));
	in_queue[s] = true;
	while(!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		in_queue[u] = false;
		for(auto p : edgs[u]) {
			int v = p.first, w = p.second;
			if(dis[v] > dis[u]+w) {
				dis[v] = dis[u]+w;
				if(!in_queue[v]) {
					in_queue[v] = true;
					pq.push(make_pair(dis[v], v));
				}
			}
		}
	}
	return;
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	//ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)
		cin >> t[i];
	for(int i = 1, k; i <= n; i++) {
		cin >> k;
		adj.clear();
		for(int j = 1, u, w; j <= k; j++) {
			cin >> u >> w;
			adj.emplace_back(u, w);
		}
		build();
	}
	int lx = -1;
	for(int i = 1, x, y; i <= q; i++) {
		cin >> x >> y;
		if(lx != x) {
			memset(dis, INF, sizeof(dis));
			dijkstra(x);
		}
		cout << dis[y]+t[x]+t[y] << '\n';
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
