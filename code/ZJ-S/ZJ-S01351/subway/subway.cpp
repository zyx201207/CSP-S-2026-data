#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int w[20050], f[20050], y[20050][510];
struct node{
	int k;
	int a[5010], t[5010];
}p[510];
vector<int> cn[20050];
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++ i) {
		cin >> w[i];
		f[i] = 1e9;
	}
	for (int i = 1; i <= n; ++ i) {
		cin >> p[i].k;
		for (int j = 1; j <= p[i].k; ++ j) {
			cin >> p[i].a[j] >> p[i].t[j];
			cn[p[i].a[j]].push_back(i);
			y[p[i].a[j]][i] = j;
		}
	}
	for (int i = 1; i <= q; ++ i) {
		int op, ed;
		cin >> op >> ed;
		queue <int> q;
		q.push(op);
		f[op] = 0;
		while (!q.empty()) {
			int t = q.front(); q.pop();
			for (int o : cn[t]) {
				for (int r = 1; r <= p[o].k; ++ r) {
					int l = p[o].a[r];
					if (l == t) continue ;
					if (f[l] > f[t] + p[o].t[y[l][o]] + p[o].t[y[t][o]]) {
						f[l] = f[t] + p[o].t[y[l][o]] + p[o].t[y[t][o]];
						q.push(l);
					}
				}
			}
		}
		cout << f[ed] + w[op] + w[ed] << '\n';
		for (int j = 1; j <= m; ++ j) {
			f[j] = 1e9;
		}
	}
	
	return 0;
}