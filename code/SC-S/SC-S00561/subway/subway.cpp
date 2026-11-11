#include <bits/stdc++.h>
using namespace std;
long long c, n, m, d, q, w[501005], k, a, t, idxu, strt, ed;
struct edge {
	long long v, w;
};
struct fw {
	long long s, ed, idx;
};
fw sr[100005];
long long ans[100005];
vector<edge> edges[501005];
long long dis[501005];
priority_queue <pair<long long, long long>> qu;
bool cmp(fw x, fw y) {
	return x.s < y.s;
}
void dijikstra(long long s) {
	long long cnt = 0;
	for (int i = 1; i <= idxu; i++)
		dis[i] = 0x3f3f3f3f;
	dis[s] = 0;
	qu.push({0, s});
	while (!qu.empty()) {
		long long u = qu.top().second;
		qu.pop();
		cnt++;
		if (cnt > idxu + 1) break;
		for (auto x : edges[u]) {
			long long v = x.v, w = x.w;
			if (dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				qu.push({-dis[v], v});
			}
		}
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	idxu = m;
	for (int i = 1; i <= n; i++) {
		cin >> k;
		idxu++;
		for (int j = 1; j <= k; j++) {
			cin >> a >> t;
			edges[idxu].push_back({a, t});
			edges[a].push_back({idxu, t});
		}
	}
	for (int i = 1; i <= q; i++) {
		cin >> sr[i].s >> sr[i].ed;
		sr[i].idx = i;
	}
	sort(sr + 1, sr + 1 + q, cmp);
	for (int i = 1; i <= q; i++) {
		dijikstra(sr[i].s);
		long long ls = sr[i].s;
		while (sr[i].s == ls) {
			ans[sr[i].idx] = w[sr[i].s] + dis[sr[i].ed] + w[sr[i].ed];
			i++;
		}
		i--;
	}
	for (int i = 1; i <= q; i++) {
		cout << ans[i] << endl;
	}
	return 0;
}