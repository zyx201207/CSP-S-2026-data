#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1100;
struct node {
	ll v, w;
};
struct node2 {
	ll id, d;
	bool operator < (const node2& x) const {
		return d > x.d;
	}
};
ll c, n, m, d, q, w[N], dis[N][N], vis[N][N];
vector <node> g[N]; 
void dij(ll s) {
	priority_queue <node2> pq;
	pq.push({s, 0});
	dis[s][s] = 0;
	while(!pq.empty()) {
		node2 cur = pq.top(); pq.pop();
		if(vis[s][cur.id]) continue;
		vis[s][cur.id] = 1;
		for(int i = 0; i < g[cur.id].size(); i++) {
			ll v = g[cur.id][i].v, w = g[cur.id][i].w;
			if(dis[s][v] > dis[s][cur.id]+w) {
				dis[s][v] = dis[s][cur.id]+w;
				pq.push({v, dis[s][v]});
			} 
		}
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(dis, 0x3f, sizeof(dis));
	cin >> c >> n >> m >> d >> q;
	int cnt = m;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1, k; i <= n; i++) {
		cin >> k; cnt++;
		for(int j = 1; j <= k; j++) { 
			ll a, p; cin >> a >> p;
			g[cnt].push_back({a, p}); g[a].push_back({cnt, p});
		} 
	}
	while(q--) {
		ll x, y; cin >> x >> y;
		dij(x);
		cout << w[x]+w[y]+dis[x][y] << "\n";
	}
	return 0;
}
