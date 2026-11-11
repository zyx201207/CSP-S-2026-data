#include<bits/stdc++.h>
#define ll long long
#define inf 1e9
using namespace std;
struct P {
	int u, w;
	bool operator < (const P &a) const {
		return a.w < w;
	}
};
struct edg {
	int v, w;
};
int c, n, m, d, q, s, f;
int fff[1000005];
int kk[1000005];
vector<int> aa[1000005];
vector<int> tt[1000005];
int dis[5000005], vis[1000005];
int w[1000005]; 
vector<edg> e[1000005];
vector<int> ddis[20005];
void dij(int ss) {
	fff[ss] = 1;
	priority_queue<P> q;
	for (int i = 1; i <= (s + 1) * m; i++) {
		vis[i] = 0, dis[i] = inf;
	}
	dis[ss] = 0, q.push({ss, 0});
	while (!q.empty()) {
		int u = q.top().u;
		q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto nxt : e[u]) {
			int v = nxt.v, w = nxt.w;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				q.push({v, dis[v]});
			}
		}
	}
	for (int i = 1; i <= (s + 1) * m; i++) {
		ddis[ss][i] = dis[i];
	}
}
void solve() {
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		kk[i] = k;
		int lst = 0;
		if (k == 1) {
			int a, t;
			cin >> a >> t;
			aa[i].push_back(a);
			tt[i].push_back(t);
		} else if (k == 2) {
			int a1, t1, a2, t2;
			cin >> a1 >> t1 >> a2 >> t2;
			e[a1].push_back({a2, t1 + t2});
			e[a2].push_back({a1, t1 + t2});
			aa[i].push_back(a1);
			tt[i].push_back(t1);
			aa[i].push_back(a2);
			tt[i].push_back(t2);
		} else {
			s++;
			for (int j = 1; j <= k; j++) {
				int a, t;
				cin >> a >> t;
				aa[i].push_back(a);
				tt[i].push_back(t);
				if (!f) f = t;
				else if (t != f) f = -1;
				e[a].push_back({a + s * m, t});
				e[a + s * m].push_back({a, t});
				if (lst) {
					e[lst].push_back({a + s * m, 0});	
					e[a + s * m].push_back({lst, 0});	
				}
				lst = a + s * m;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		ddis[i].clear();
		ddis[i].resize((s + 1) * (m + 1));
	}
	while (q--) {
		int u, v;
		cin >> u >> v;
		if (!fff[u]) dij(u);
		cout << w[u] + ddis[u][v] + w[v] << "\n";
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int T = 1;
	while (T--) solve();
	return 0;
}

