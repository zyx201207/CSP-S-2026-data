#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 10, INF = 1e18;
ll ID, n, m, d, p, ans, a[N], v[N], w[N], vis[N], dis[N];
ll valg[30][N];

struct node {
	ll id, v, w;
};
vector<node> e[N];

struct nodee {
	ll dis, id;
	friend bool operator<(nodee a, nodee b) {
		return a.dis < b.dis;
	}
};
priority_queue<nodee> q;

ll dij(ll st, ll en) {
	for (int i = 1; i <= m; i++)
		dis[i] = INF;
	q.push({0, st});
	dis[st] = 0;
	while (!q.empty()) {
		nodee now = q.top();
		q.pop();
		ll u = now.id;
		if (vis[u])
			continue;
		ll last = -1;
		for (auto it : e[u]) {
			ll id = it.id, to = it.v, val = it.w;
			if (id != last) {
				val += valg[id][u];
				last = id;
			}
			if (dis[to] > dis[u] + val) {
				dis[to] = dis[u] + val;
				q.push({dis[to], to});
			}
		}
	}
	return dis[en];
}

int main() {
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> ID >> n >> m >> d >> p;
	for (int i = 1; i <= m; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> v[j] >> w[j];
			valg[i][v[j]] = w[j];
		}
		for (int j = 1; j <= k; j++) {
			for (int l = 1; l <= k; l++)
				if (j != l)
					e[v[j]].push_back({i, v[l], w[l]});
		}
	}
	for (int i = 1; i <= p; i++) {
		ll st, en;
		cin >> st >> en;
		ans = dij(st, en);
		ans = ans + a[st] + a[en];
		cout << ans << '\n';
	}
	return 0;
}
//0 3 7 20 2
//8 3 6 1 7 2 9
//3 1 4 2 5 5 100
//3 2 6 3 1 7 2
//4 3 2 5 100 4 6 6 7
//1 6
//2 3

//8+