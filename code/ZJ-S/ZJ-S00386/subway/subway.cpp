#include <bits/stdc++.h>
using namespace std;
struct node {
	long long v, t;//v => 该号线有哪几个站　t => 从该号线的v站的站台到展厅的时间
};
struct fun {
	long long u, v;//几号线的从u->v
};
struct f{
	long long x, id, z;
	friend bool operator < (f x, f y) {
		return x.id > y.id;
	}
};
long long w[500010], dis[500010];//厅口时间
vector<vector<node> > ttt(500010);//台厅时间
vector<vector<fun> > v(500010);//存图
vector<vector<long long> > g(500010);//一个点能在几条线上
bool vis[500010];
void dijkstra (long long s) {
	memset(vis, false, sizeof(vis));
	memset(dis, 0x3f, sizeof(dis));
	priority_queue<f> pq;
	pq.push((f){s, w[s], 0});
	dis[s] = w[s];
	while (!pq.empty()) {
		f t = pq.top();
		pq.pop();
		long long u = t.x;
		if (vis[u]) continue;
		vis[u] = true;
		for (long long i = 0; i < g[u].size(); i++) {
			long long p = t.id, d = 0;
			if (g[u][i] != t.z) {
				for (long long j = 0; j < ttt[t.z].size(); j++) {
					if (ttt[t.z][j].v == u) {d = ttt[t.z][j].t;break;}
				}
				if (t.z == 0) p += d;
				for (long long j = 0; j < ttt[g[u][i]].size(); j++) {
					if (ttt[g[u][i]][j].v == u) {d = ttt[g[u][i]][j].t;break;}
				}
				p += d;
			} else {
				for (long long j = 0; j < ttt[t.z].size(); j++) {
					if (ttt[t.z][j].v == u) {d = ttt[t.z][j].t;break;}
				}
				p -= d;
			}
			vector<long long> ygg;
			for (long long j = 0; j < v[g[u][i]].size(); j++) {
				if (v[g[u][i]][j].u == u) ygg.push_back(j);
			}
			for (long long j = 0; j < ygg.size(); j++) {
				long long t = v[g[u][i]][ygg[j]].v, b;
				for (long long j = 0; j < ttt[g[u][i]].size(); j++) {
					if (ttt[g[u][i]][j].v == t) {b = ttt[g[u][i]][j].t;break;}
				}
				if (dis[t] > p + b) {
					dis[t] = p + b;
					pq.push((f){t, dis[t], g[u][i]});	
				}
			}
		}
	}
}
int main () {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	long long c, n, m, d, q;//c无用,n有几路地铁,m有几个点,d无用,q询问
	cin >> c >> n >> m >> d >> q;
	for (long long i = 1; i <= m; i++) cin >> w[i];
	for (long long i = 1; i <= n; i++) {
		long long k;
		cin >> k;
		for (long long j = 1; j <= k; j++) {
			long long v, t;
			cin >> v >> t;
			ttt[i].push_back((node){v, t});
			g[v].push_back(i);
		}
		for (long long j = 1; j < k; j++) {
			v[i].push_back((fun){ttt[i][j - 1].v, ttt[i][j].v});
			v[i].push_back((fun){ttt[i][j].v, ttt[i][j - 1].v});
		}
	}
	while (q--) {
		long long x, y;
		cin >> x >> y;
		dijkstra(x);
		cout << dis[y] + w[y] << endl;
	}
	return 0;
}