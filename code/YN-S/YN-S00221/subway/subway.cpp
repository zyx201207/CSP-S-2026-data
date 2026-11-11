#include <bits/stdc++.h>
using namespace std;
#define int long long
map<int, int>d[500005];
int c, n, m, dd, Q, tot, head[500005], w[500005], a[500005], t[500005];

struct uv {
	int to, nt, val;
} e[4000005];

void add(int u, int v, int w) {
	e[++tot] = {v, head[u], w};
	head[u] = tot;
	return;
}
bool vis[500005];

void dij(int s, int t) {
	memset(vis, 0, sizeof(vis));
	priority_queue < pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >q;
	q.push({0, s});

	while (!q.empty()) {
		int u = q.top().second;
//		cout << u << " " << q.top().first << '\n';
		q.pop();

		if (vis[u]) {
			continue;
		}

		vis[u] = 1;

		for (int i = head[u]; i; i = e[i].nt) {

			int v = e[i].to;

			if (vis[v]) {
				continue;
			}

			if (d[s][v] == 0 || (d[s][v] > d[s][u] + e[i].val)) {
				d[s][v] = d[s][u] + e[i].val;
				q.push({d[s][v], v});
			}
		}
	}

	return;
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
//	freopen("111.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> dd >> Q;

	for (int i = 1; i <= m; i++) {

		cin >> w[i];
	}

	for (int i = 1; i <= n; i++) {

		int k;
		cin >> k;

		for (int j = 1; j <= k; j++) {

			cin >> a[j] >> t[j];
			add(a[j], i + m, t[j]);
			add(i + m, a[j], t[j]);
//			cout << a[j] << " " << i + m << '\n';
		}
	}

	while (Q--) {
		int s, t;
		cin >> s >> t;

		if (d[s][t]) {
			cout << d[s][t] + w[s] + w[t] << "\n";
		} else if (d[t][s]) {
			cout << d[t][s] + w[s] + w[t] << "\n";
		} else {
			dij(s, t);
			cout << d[s][t] + w[s] + w[t] << "\n";
		}

	}

	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/