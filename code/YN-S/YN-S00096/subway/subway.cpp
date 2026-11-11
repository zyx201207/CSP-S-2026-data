#include <bits/stdc++.h>
#define int long long
using namespace std;

struct node {
	int v, w, bh;
};

struct node2 {
	int u, bh, cnt, jl;
	friend bool operator<(node2 x, node2 y) {
		return x.cnt > y.cnt;
	}
};
int c, n, m, d, q, w[500005], k[505], a[500005], t[500005], u, v, dis[500005], ans;
vector<node>g[500005], g2[500005];

int bfs(int st, int sq) {
	priority_queue<node2>q;
	fill(dis, dis + m + 1, 1e9);
	ans = 2e9;
	dis[st] = w[st];
	q.push({st, -1, w[st]});
	while (q.size() != 0) {
		int u = q.top().u, bh = q.top().bh, cnt = q.top().cnt, jl = q.top().jl;
		q.pop();
		if (u == sq) {
			ans = min(cnt + w[sq], ans);
			continue;
		}
		int bj = -1;
		for (auto a : g[u]) {
			bj++;
			int v = a.v, w = a.w, nw = a.bh, lc;
			lc = cnt;
			int k = 0;
			if (nw != bh) {
				lc = cnt + g2[u][bj].w + jl;
				k = g[u][bj].w;
			}
			if (v == sq) {
				lc += w;
			}
			if (dis[v] > lc) {
				dis[v] = lc;
				q.push({v, nw, lc, k});
			}
		}
	}
	return ans ;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[j] >> t[j];
			if (j >= 2) {
				g[a[j]].push_back({a[j - 1], t[j - 1], i});
				g2[a[j]].push_back({a[j - 1], t[j], i});
				g[a[j - 1]].push_back({a[j], t[j], i});
				g2[a[j - 1]].push_back({a[j], t[j - 1], i});
			}
		}
	}
	while (q--) {
		cin >> u >> v;
		int sum = bfs(u, v);
		cout << sum << '\n';
	}
	return 0;
}
