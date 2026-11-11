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
int kk[500005];
vector<int> aa[500005];
vector<int> tt[500005];
int dis[10000005], vis[10000005];
int w[10000005]; // 每个地铁站的口到厅的时间
vector<edg> e[10000005];
void dij(int ss) {
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
			aa[i].push_back(a1);
			tt[i].push_back(t1);
			aa[i].push_back(a2);
			tt[i].push_back(t2);
		} else {
			for (int j = 1; j <= k; j++) {
				int a, t;
				cin >> a >> t;
				aa[i].push_back(a);
				tt[i].push_back(t);
				if (f == 0) f = t;
				else if (t != -1 && t != f) f = -1;
			}
		}
	}
	if (f != -1) {
		for (int i = 1; i <= n; i++) {
			int lst = 0;
			for (int j = 0; j < kk[i]; j++) {
				if (lst) {
					e[lst].push_back({aa[i][j], tt[i][j] + tt[i][j - 1]});	
					e[aa[i][j]].push_back({lst, tt[i][j] + tt[i][j - 1]});	
				}
				lst = aa[i][j];
			}
		}
	} else {
		for (int i = 1; i <= n; i++) {
			int k = kk[i];
			int lst = 0;
			if (k == 1) {
				
			} else if (k == 2) {
				int a1 = aa[i][0], t1 = tt[i][0], a2 = aa[i][1], t2 = tt[i][1];
				e[a1].push_back({a2, t1 + t2});
				e[a2].push_back({a1, t1 + t2});
			} else {
				s++;
				for (int j = 0; j < k; j++) {
					int a = aa[i][j], t = tt[i][j];
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
	}
	while (q--) {
		int u, v;
		cin >> u >> v;
		dij(u);
		cout << w[u] + dis[v] + w[v] << "\n";
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway5.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int T = 1;
	while (T--) solve();
	return 0;
}
