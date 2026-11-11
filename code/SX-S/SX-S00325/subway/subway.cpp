#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 5e5+248;
ll c, n, m, d, q;
ll w[M];
ll a[510], dis[M];
bool vis[M];
vector<pair<ll, ll>> nxt[M];

ll solve(ll from, ll to) {
	ll ans = w[from] + w[to];
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x3f, sizeof(dis));
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> qu;
	qu.push({0, from});
	dis[from] = 0;
	while (!qu.empty()) {
		ll tp = qu.top().second;
		qu.pop();
		if (vis[tp])
			continue;
		int lenth = nxt[tp].size();
		for (int i = 0; i < lenth; i++) {
			ll too = nxt[tp][i].first, len = nxt[tp][i].second;
			if (dis[tp] + len < dis[too]) {
				dis[too] = dis[tp] + len;
				qu.push({dis[too], too});
			}
		}
	}
	ans += dis[to];
	return ans;
}

//太难了！！！先暴力吧
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		scanf("%lld", &w[i]);
	}
	ll ai, ti;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		vector<pair<ll, ll>> now;
		for (int j = 1; j <= a[i]; j++) {
			scanf("%lld%lld", &ai, &ti);
			now.push_back({ai, ti});
		}
		for (int j = 0; j <= a[i] - 1; j++) {
			for (int k = j + 1; k <= a[i] - 1; k++) {
				nxt[now[j].first].push_back({now[k].first, now[k].second + now[j].second});
				nxt[now[k].first].push_back({now[j].first, now[k].second + now[j].second});
			}
		}
	}
	ll u, v;
	while (q--) {
		scanf("%lld%lld", &u, &v);
		printf("%lld\n", solve(u, v));
	}
	return 0;
}