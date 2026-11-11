#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
int c, n, m, d, q;
int w[maxn], rsize[maxn];
vector<vector<int> > r;
vector<vector<int> > e;

struct x {
	int k, p = -1;
	vector<int> t;
	vector<vector<int> > a;
} y[maxn];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];

	for (int i = 1; i <= n; i++) {
		cin >> y[i].k;
		for (int j = 1, b, pp; j <= y[i].k; j++) {
			cin >> b >> pp;
			y[i].a.resize(maxn);
			r[b].emplace_back(i);
			rsize[i]++;
			y[b].a[j].emplace_back(b), y[b].t.emplace_back(pp);
		}
		for (int j = 1; j <= y[i].k; j++) {
			e[i].resize(maxn);
			for (auto l : y[i].a[j])
				if (j != l)
					e[i].emplace_back(l);

		}
	}

	while (q--) {
		int u, l;
		cin >> u >> l;
		priority_queue<pair<pair<int, int>, int> > qu;
		for (int i = 1; i <= rsize[1]; i++)
			qu.push({{0, u}, r[1][i]});
		for (int i = 1; i <= n; i++) {
			pair<pair<int, int>, int> f = qu.top();
			qu.pop();
			if (y[f.first.second].p == -1) {
				y[f.first.second].p = f.first.first;
				for (auto v : e[f.second]) {
					qu.push({{f.first.first, v}, f.second});
				}
				for (int j = 1; j <= rsize[f.first.second]; j++) {
					if (j == f.second)
						continue;
					for (auto v : e[j]) {
						qu.push({{f.first.first + y[f.first.second].t[r[v][j]] + y[v].t[r[f.first.second][j]], v}, r[v][j]});

					}
				}

			}
		}
		cout << y[l].p + w[u] + w[l];
	}
	return 0;
}