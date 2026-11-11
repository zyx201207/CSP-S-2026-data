#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
using namespace std;
const int N = 505, M = 5e5+5;

struct nb {
	ll a, t;
} qa[M];

struct mnb {
	ll v, ww;
};

ll c, n, m, d, Q, w[M], k[N], ans;
ll dis[M], vis[M];
vector<mnb> vec[M];

void hanshu2(ll x) {
	for (int i = 1; i <= M; i++) {
		dis[i] = 0;
	}

	priority_queue<pll, vector<pll>, greater<pll> > pq;
	pq.push({0, x});
	dis[x] = 0;
	while (!pq.empty()) {

		ll ed = pq.top().second, val = pq.top().first;
		pq.pop();
//		if (vis[ed])
//			continue;
//		vis[ed] = 1;
		dis[ed] = min(dis[ed], dis[ed] + val);
		int tyt = vec[ed].size();
		for (int i = 0; i < tyt; i++) {
//			cout << 1 << '\n';
			pq.push({vec[ed][i].ww, vec[ed][i].v});
		}
	}
}

void hanshu(ll x, ll y) {
	ans = w[x] + w[y];
	hanshu2(x);
	ans += dis[y];
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> Q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> qa[i].a >> qa[i].t;
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= k[i]; j++) {
			vec[qa[j - 1].a].push_back({qa[j].a, qa[j - 1].t + qa[j].t});
			vec[qa[j].a].push_back({qa[j - 1].a, qa[j - 1].t + qa[j].t});
		}
	while (Q--) {
		ans = 0;
		ll x, y;
		cin >> x >> y;
		hanshu(x, y);
		cout << ans << '\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/