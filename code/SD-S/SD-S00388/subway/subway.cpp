#include <bits/stdc++.h>
using namespace std;
/*
#define DBGMODE false
#define dbg if(DBGMODE)cout
#define dnl if(DBGMODE)cout<<'\n'
#define ifd if(DBGMODE)
*/
#define INF 2147483647
const int N = 5e5 + 3;
int c, m, n, d, q, w[N], k[N];
struct edg {
	int to, w;
};
vector <edg> g[N];
struct mys {
	int id, w;
	bool operator > (const mys &other) const {
		return w > other.w;
	}
};
int dist[N];
int maxid;
void djs (int s) {
	priority_queue <mys, vector <mys>, greater <mys>> pq;
	for (int i = 1; i <= maxid; ++ i) {
		dist[i] = INF;
	}
	dist[s] = 0;
	pq.push({s, 0});
	while (pq.size()) {
		mys cur = pq.top();
		pq.pop();
		int id = cur.id;
//		dbg << "======== cur id: " << id << " ========\n";
//		dbg << "dist of this node: " << dist[id] << '\n';
		for (auto x : g[id]) {
//			dbg << "try to update: " << x.to << '\n';
//			dbg << "dist of the target node: " << dist[x.to] << '\n';
			if (dist[x.to] > dist[id] + x.w) {
//				dbg << "new dist: " << dist[id] + x.w << '\n';
				dist[x.to] = dist[id] + x.w;
				pq.push({x.to, dist[x.to]});
			}
		}
	}
	return;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(NULL);
//	freopen ("C:\\Users\\Administrator\\Desktop\\subway\\subway4.in", "r", stdin);
  	freopen ("subway.in", "r", stdin);
  	freopen ("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++ i) {
		cin >> w[i];
		g[i].push_back({i + m, w[i]});
		g[i + m].push_back({i, w[i]});
//		dbg << "station id: " << i << ", virtual hall id: " << i + m << '\n';
	}
	int vnid = 2 * m;
	for (int i = 1; i <= n; ++ i) {
//		dbg << "======== subway id: " << i << " ========\n";
		cin >> k[i];
		vector <int> vnids;
		for (int j = 1; j <= k[i]; ++ j) {
			int a, t;
			cin >> a >> t;
			g[a + m].push_back({++ vnid, t});
			g[vnid].push_back({a + m, t});
			vnids.push_back(vnid);
//			dbg << "virtual subway connect id: " << vnid << '\n';
		}
		for (int j = 1; j < vnids.size(); ++ j) {
			g[vnids[j - 1]].push_back({vnids[j], 0});
		}
		g[vnids[vnids.size() - 1]].push_back({vnids[0], 0});
	}
	maxid = vnid;
	for (int i = 1; i <= q; ++ i) {
		int x, y;
		cin >> x >> y;
		djs (x);
		cout << dist[y] << '\n';		
	}
	return 0;
}
