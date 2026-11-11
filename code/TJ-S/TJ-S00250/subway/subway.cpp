#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct e {
	int u, v, num;
	ll ut, vt;
};
vector <e> G[500005];
ll dis[500005], w[500005];

void spfa(int s) {
	memset(dis, 0x3f, sizeof(dis));
	queue <e> q;
	q.push({0, s, 0, 0, 0});
	dis[s] = 0;
	while (!q.empty()) {
		e pre = q.front();
		q.pop();
		for (int i = 0; i < G[pre.v].size(); i++) {
			e now = G[pre.v][i];
			//if (now.v == pre.u) continue;
			if (dis[pre.v] + (pre.num == now.num ? -pre.vt + now.vt : now.ut + now.vt) < dis[now.v]) {
				dis[now.v] = dis[pre.v] + (pre.num == now.num ? -now.ut + now.vt : now.ut + now.vt);
				q.push(now);
			}
		}
	}
}


int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int k, prea = 0;
		cin >> k;
		ll pret;
		while (k--) {
			int a;
			ll t;
			cin >> a >> t;
			if (prea) {
				G[prea].push_back({prea, a, i, pret, t});
				G[a].push_back({a, prea, i, t, pret});
			}
			prea = a; pret = t;
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		spfa(x);
		cout << (dis[y] + w[x] + w[y]) << endl;
	}
	return 0;
}
