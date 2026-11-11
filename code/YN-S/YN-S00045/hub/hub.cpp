#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const ll maxn = 2e6 + 5;
const ll INF = 1e18;
ll n, k;
vector<ll> e[maxn];
ll c[maxn];
ll cnt;
ll ans = 0;
ll dis[maxn], vis[maxn];
ll res;

void qidong() {
	if (cnt != k)
		return ;
	res = 0;

	for (ll st = 1; st <= n; st++) {

		if (c[st])
			continue;
		queue<ll> q;
		q.push(st);

		for (ll i = 1; i <= n; i++) {

			dis[i] = INF;
			vis[i] = 0;
		}

		dis[st] = 0;
		vis[st] = 1;

		while (!q.empty()) {
			ll now = q.front();
			q.pop();

			for (ll nxt : e[now]) {
				if (vis[nxt] == 0) {
					vis[nxt] = 1;
					dis[nxt] = dis[now] + 1;
					q.push(nxt);
				}
			}
		}

		ll mn = INF;

		for (ll i = 1; i <= n; i++)

			if (c[i]) {
				mn = min(mn, dis[i]);
//				cout << dis[i] << " ";
			}

//		cout << "\n";
		res = max(res, mn);
	}

//	cout << res << "\n";
	ans = min(res, ans);
}

void dfs(ll now) {
	if (now == n + 1) {
		qidong();
		return ;
	}

	if (cnt + 1 <= k) {
		c[now] = 1;
		cnt++;
		dfs(now + 1);
		cnt--;
	}

	c[now] = 0;
	dfs(now + 1);
}

void solve() {
	cin >> n >> k;
	cnt = 0;
	ans = INF;

	for (ll i = 1; i <= n; i++) {

		e[i].clear();
	}

	for (ll i = 1; i < n; i++) {

		ll u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	dfs(1);
	cout << ans << "\n";
}

signed main() {
//	clock_t st = clock();
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll T = 1;
	ll c;
	cin >> c;
	cin >> T;

	for (ll t = 1; t <= T; t++) {

		solve();
//		return 0;
	}

//	clock_t ed = clock();
//	cout << (double)(ed - st) / CLOCKS_PER_SEC;
}