#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, NN = 1e7 + N;
int c, n, m, d, q, cnt;
long long w[N], ans[NN];

struct xx {
	int v, val;
};

struct node {
	int bh;
	long long dis;
	friend bool operator<(node x, node y) {
		return x.dis > y.dis;
	}
};
vector <xx> g[NN];
priority_queue<node> qq;

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	cnt = m;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		int a, b, l;
		cin >> a >> b;
		cnt++, l = cnt;
		g[a].push_back({cnt, b});
		g[cnt].push_back({a, b});
		for (int j = 2; j <= k; j++) {
			cin >> a >> b;
			cnt++;
			g[a].push_back({cnt, b});
			g[cnt].push_back({a, b});
			g[cnt].push_back({l, 0});
			g[l].push_back({cnt, 0});
			l = cnt;
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		for (int i = 1; i <= cnt; i++)
			ans[i] = INT_MAX;
		qq.push({x, 0});
		ans[x] = 0;
		while (qq.empty() == 0) {
			node now = qq.top();
			qq.pop();
			int u = now.bh;
			long long dis = now.dis;
			if (dis > ans[u])
				continue;
			for (int i = 0; i < g[u].size(); i++) {
				int v = g[u][i].v;
				long long val = g[u][i].val;
				if (ans[v] > ans[u] + val) {
					ans[v] = ans[u] + val;
					qq.push({v, ans[v]});
				}
			}
		}
		cout << ans[y] + w[x] + w[y] << '\n';
	}
	return 0;
}
