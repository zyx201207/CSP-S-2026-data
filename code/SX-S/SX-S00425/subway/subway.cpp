#include <bits/stdc++.h>
using namespace std;
int w[200010];

struct dt {
	long long k;
	int a[1010], t[1010];
} p[510];
map<int, queue<int> > ma;
long long c, n, m, d, q, x, y, minx;

void dfs(int k, int zhan, long long s) {
	if (k == y) {
		minx = min(minx, s);
		return;
	}
	for (auto it = ma.begin(); it != ma.end(); it++) {
		queue<int> q = it->second;
		while (!q.empty()) {
			if (zhan == q.front()) {
				for (int i = 1; i <= p[zhan].k; i++) {
					if (p[zhan].a[i] == k)
						continue;
					dfs(p[zhan].a[i], zhan, abs(s - p[zhan].a[i]));
				}
			} else {
				for (int i = 1; i <= p[zhan].k; i++) {
					if (p[zhan].a[i] == k)
						continue;
					dfs(p[zhan].a[i], q.front(), p[zhan].t[i] + p[q.front()].t[i] + abs(s - p[zhan].a[i]));
				}
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> p[i].k;
		for (int j = 1; j <= p[i].k; j++) {
			cin >> p[i].a[j] >> p[i].t[j];
			ma[p[i].a[j]].push(i);
		}
	}
	while (q--) {
		minx = LLONG_MAX;
		cin >> x >> y;
		for (auto it = ma.begin(); it != ma.end(); it++) {
			queue<int> q = it->second;
			while (!q.empty()) {
				dfs(x, q.front(), w[x]);
				q.pop();
			}
		}
	}
	return 0;
}
