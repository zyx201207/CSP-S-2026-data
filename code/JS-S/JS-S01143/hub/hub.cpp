#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll N = 1e6 + 5, inf = 1e18;
ll tc = 1, c, n, k;
vector<ll> g[N];


void input() {
	scanf("%lld %lld", &n, &k);
	for (ll i = 1; i <= n; i++) {
		g[i].clear();
	}
	for (ll i = 1; i < n; i++) {
		ll u, v;
		scanf("%lld %lld", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
}

ll col[N], f[N], dis[N];
queue<ll> q;

void dfscol(ll u, ll fa = 0) {
	col[u] = 1;
	for (ll o = 0; o < (ll)g[u].size(); o++) {
		ll v = g[u][o];
		if (v == fa || !f[v] || col[v]) {
			continue;
		}
		dfscol(v, u);
	}
}

ll calccur() {
	ll tot = 0;
	for (ll i = 1; i <= n; i++) {
		if (f[i] && !col[i]) {
			dfscol(i);
			tot++;
		}
	}
	if (tot > 2) {
		return inf;
	}
	while (!q.empty()) {
		q.pop();
	}
	for (ll i = 1; i <= n; i++) {
		if (f[i]) {
			dis[i] = 0;
			q.push(i);
		}
	}
	ll mx = 0;
	while (!q.empty()) {
		ll u = q.front();
		q.pop();
		for (ll o = 0; o < (ll)g[u].size(); o++) {
			ll v = g[u][o];
			if (dis[v] > dis[u] + 1) {
				dis[v] = dis[u] + 1;
				mx = max(mx, dis[v]);
				q.push(v);
			}
		}
	}
	return mx;
}

void solve1() {
	ll ans = inf;
	for (ll s = 0; s < (1ll << n); s++) {
		if (__builtin_popcount(s) != k) {
			continue;
		}
		for (ll i = 1; i <= n; i++) { f[i] = col[i] = 0, dis[i] = inf; }
		for (ll i = 1; i <= n; i++) {
			if ((s >> (i - 1)) & 1) {
				f[i] = 1;
			}
		}
		ll cur = calccur();
		ans = min(ans, cur);
	}
	printf("%lld\n", ans);
}

void solve2() {
	ll e = n / 2 + 3;
	if (k == 1) {
		printf("%lld\n", (e - 2) / 2);
	} else if (k == n) {
		printf("0\n");
	} else if (e - k <= 0) {
		printf("1\n");
	} else {
		printf("%lld\n", (e - k) / 4 + 1);
	}
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%lld %lld", &c, &tc);
	while (tc--) {
		input();
		if (c <= 3) { solve1(); }
		if (c == 13 || c == 14) { solve2(); }
	}
	return 0;
}