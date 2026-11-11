#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll N = 2e6 + 5, inf = 1e18, mod = 1145141919810114557;
ll c, tc, n, d, ans, a[N], dis[N], cnt[N];
vector<ll> g[N];

void init() {
	ans = 0;
	for (ll i = 1; i <= n; i++) {
		g[i].clear();
	}
}

void bfs(ll s) {
	for (ll i = 1; i <= n; i++) {
		dis[i] = inf;
		cnt[i] = 0;
	}
	dis[s] = 0;
	cnt[s] = 1;
	for (ll i = s + 1; i <= n; i++) {
		for (ll o = 0; o < (ll)g[i].size(); o++) {
			ll v = g[i][o];
			if (dis[v] + 1 < dis[i]) {
				dis[i] = dis[v] + 1;
				cnt[i] = cnt[v];
			} else if (dis[v] + 1 == dis[i]) {
				cnt[i] += cnt[v];
				cnt[i] %= mod;
			}
		}
	}
	for (ll i = 1; i <= n; i++) {
		if (cnt[i] == 2) {
			ans++;
		}
	}
}

void solve1() {
	scanf("%lld %lld", &n, &d);
	init();
	for (ll i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	for (ll i = 1, j = 1; i <= n; i++) {
		while (j + 1 <= n && a[j + 1] <= a[i] + d) {
			j++;
		}
		ll lim = 300;
		if (c > 6) {
			lim = 8;
		}
		for (ll k = 0; k <= lim; k++) {
			if (j - k > i) {
				g[j - k].push_back(i);
			} else {
				break;
			}
		}
	}
	for (ll i = 1; i <= n; i++) {
		bfs(i);
	}
	printf("%lld\n", ans);
}

void solve2() {
	scanf("%lld %lld", &n, &d);
	for (ll i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	if (n == 1) {
		printf("0\n");
		return;
	}
	d /= (a[2] - a[1]);
	if (d <= 1) {
		printf("0\n");
		return;
	}
	printf("%lld\n", max(0ll, n + 1 - d * 2));
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%lld %lld", &c, &tc);
	while (tc--) {
		if (c <= 10) { solve1(); }
		else if (c == 11 || c == 12) { solve2(); }
	}
	return 0;
}