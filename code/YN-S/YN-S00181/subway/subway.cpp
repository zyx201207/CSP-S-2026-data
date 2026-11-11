#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long c, n, m, bh[20005][505], de[1005][1005], k[505], q, cnt[N], w[N], a[505][20005], t[505][20005], id[N], d;
long long tot, sda[N], s;
queue<pair<long long, long long> >pq;

//a:每个线路经过的站点,t[i][j]从i线到j厅
struct yyy {
	long long w, v;
};
vector<yyy>e[N];

void spfa() {
	pq.push({s, 0});
	while (!pq.empty()) {
		long long u = pq.front().first;
		long long ww = pq.front().second;
		pq.pop();
		for (auto [v, q] : e[u]) {
			if (ww + q < de[u][v]) {
				de[u][v] = ww + q;
				de[s][v] = min(de[s][v], de[s][u] + de[u][v]);
				pq.push({v, ww + q});
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (long long i = 1; i <= m; i++) {
		cin >> w[i];
		sda[i] += w[i];
	}
	tot = m;
	for (long long i = 1; i <= 1005; i++) {
		for (long long j = 1; j <= 1005; j++) {
			de[i][j] = 1e18 + 5;
		}
	}
	for (long long i = 1; i <= n; i++) {
		cin >> k[i];
		for (long long j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
			tot++;
			cnt[a[i][j]]++;
			e[tot].push_back({a[i][j], t[i][j]});
			e[a[i][j]].push_back({tot, t[i][j]});
			de[a[i][j]][tot] = t[i][j];
			de[tot][a[i][j]] = t[i][j];
			id[tot] = a[i][j];
			bh[a[i][j]][cnt[a[i][j]]] = tot;
			a[i][j] = tot;
			if (j > 1) {
				e[a[i][j - 1]].push_back({a[i][j], 0});
				e[a[i][j]].push_back({a[i][j - 1], 0});
				de[a[i][j - 1]][a[i][j]] = 0;
				de[a[i][j]][a[i][j - 1]] = 0;
			}
		}
	}
	for (long long i = 1; i <= m; i++) {
		s = i;
		spfa();
	}
	while (q--) {
		long long x, y;
		cin >> x >> y;
		cout << de[x][y] + w[x] + w[y] << endl;
	}
	return 0;
}
