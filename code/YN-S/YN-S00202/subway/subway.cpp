#include <bits/stdc++.h>
using namespace std;
const int N = 500 + 5;
int c, n, m, a[N], dd, q, d[N][N];
bool aa[N];

struct no {
	int v, w;
};
vector<no>e[N];

void dij(int s) {
//	fill(d[s] + 1, d[s] + n + 1, INT_MAX);
	for (int i = 1; i <= n; i++) {
		d[i][s] = INT_MAX;
		aa[i] = 0;
	}
	//fill(aa + 1, aa + n + 1, 0);
	priority_queue<pair<int, int>>q;
	q.push({0, s});
	d[s][s] = 0;
	while (!q.empty()) {
		int u = q.top().second;
		q.pop();
		if (aa[u])
			continue;
		aa[u] = 1;
		for (int i = 0; i < e[u].size(); i++) {
			int v = e[u][i].v, w = e[u][i].w;
			if (d[u][s] + w < d[v][s]) {
				int cc = 0;
				d[v][s] = d[u][s] + w + c;
				q.push({-d[v][s], v});
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> m >> n >> dd >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int aa, tt;
			cin >> aa >> tt;
			e[i].push_back({aa, tt});
			e[aa].push_back({i, tt});
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		if (d[y][x] == 0) {
			dij(x);
		}
		cout << d[y][x] * 2 + a[x] + a[y] << endl;

	}

	return 0;
}
