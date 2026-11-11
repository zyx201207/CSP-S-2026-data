#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 500,maxm = 5e5,maxd = 20;
const ll inf = 2e18;
namespace Elaina {
	struct edge { int to; ll w; };
	int c,n,m,d,q;
	ll w[maxm + 5];
	vector<pair<int,ll> > a[maxn + 5]; // a[i] (j,x) i 地铁线 i 与站点 j 的距离 x
	vector<pair<int,ll> > b[maxm + 5]; // 经过 地铁站 i 的线路 b[i]
	vector<edge> G[maxn + 5]; // 地铁线之间的最短怒
	ll tmp[maxm + 5];
	ll dis[maxn + 5][maxn + 5]; int vis[maxn + 5]; // 任意两地铁线距离
	priority_queue<pair<ll,int> > pq;
	void dij(int s) {
		while (!pq.empty()) pq.pop();
		for (int i = 1;i <= n;i ++) dis[s][i] = inf,vis[i] = 0;
		dis[s][s] = 0ll; pq.push({-dis[s][s],s});
		while (!pq.empty()) {
			int u = pq.top().second; pq.pop();
			if (vis[u]) continue;
			vis[u] = 1;
			for (edge e : G[u]) {
				int v = e.to; ll d = dis[s][u] + e.w;
				if (dis[s][v] > d) {
					dis[s][v] = d;
					pq.push({-dis[s][v],v});
				}
			}
		}
	}
	void main() {
		cin >> c >> n >> m >> d >> q;
		for (int i = 1;i <= m;i ++) cin >> w[i];
		for (int u = 1;u <= n;u ++) { // 地铁线 u
			int k; cin >> k;
			for (int i = 1;i <= k;i ++) { // 地铁站 v
				int v; ll w; cin >> v >> w;
				a[u].push_back({v,w});
				b[v].push_back({u,w});
			}
		}
		for (int i = 1;i <= m;i ++) tmp[i] = inf;
		for (int i = 1;i <= n;i ++) {
			for (pair<int,ll> k : a[i]) tmp[k.first] = k.second;
			for (int j = i + 1;j <= n;j ++) {
//				cout << "i/j: " << i << ", " << j << ": \n";
				ll mn = inf;
				for (pair<int,ll> k : a[j]) {
					ll d = tmp[k.first] + k.second;
					if (tmp[k.first] != inf) {
						mn = min(mn,d);
//						cout << " mn = " << mn << ", k=(" << k.first << "," << k.second << ")\n";
					}
				}
				if (mn != inf) {
					G[i].push_back(edge{j,mn});
					G[j].push_back(edge{i,mn});
//					cout << "edge i and j: " << mn << "\n";
				}
			}
			for (pair<int,ll> k : a[i]) tmp[k.first] = inf;
		}
		for (int i = 1;i <= n;i ++) dij(i);
//		cout << "dis: \n";
//		for (int i = 1;i <= n;i ++) {
//			for (int j = 1;j <= n;j ++) cout << dis[i][j] << " ";
//			cout << "\n";
//		}
		
		while (q --) {
			int s,t; cin >> s >> t;
			ll mn = inf;
			for (pair<int,ll> px : b[s]) {
				int x = px.first; ll tx = px.second;
				for (pair<int,ll> py : b[t]) {
					int y = py.first; ll ty = py.second;
					if (dis[x][y] >= inf) continue;
					ll d = dis[x][y] + tx + ty;
					mn = min(mn,d);
				}
			}
			cout << mn + w[s] + w[t] << "\n";
		}
	}
}
int main() {
	ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	Elaina::main();
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/