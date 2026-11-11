#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MAX = 2e6 + 5;
ll res[MAX], n, d, c, t, nt, ans;

ll read() {
	ll x = 0;
	int f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + (ch - '0');
		ch = getchar();
	}
	return f * x;
}

void dfs(ll ep, ll cur, ll p, ll end) {	
	if (p == end) {
		if (cur == ep) ++nt;
		return;
	}
	if (cur >= ep) return;
	if (ep - cur < (res[end] - res[p]) / d) return;
	for (ll i = p + 1; i <= end; ++i) {
		if (res[i] - res[p] <= d) {
			dfs(ep, cur + 1, i, end);
		} else break;
	}
}

ll lower_bound(ll l, ll r) {
	ll o = l;
	ll a = l;
	while (l <= r) {
		ll mid = (l + r) >> 1;
		if (res[mid] - res[o] <= d) a = mid, l = mid + 1;
		else r = mid - 1;
	}
	return a;
}

void solve1() {
	ans = 0;
	for (ll i = 1; i <= n; ++i) {
		for (ll j = i + 1; j <= n; ++j) {
			nt = 0;
			ll cnt = 0, flag = true;
			for (ll k = i; k < j;) {
				ll kk = lower_bound(k, j);
				++cnt;
				if (kk == k) {
					flag = false;
					break;
				}
				k = kk;
			}
			if (!flag) continue;
			dfs(cnt, 0, i, j);
			if (nt == 2) {
				++ans;
			}
		}
	}
	printf("%lld\n", ans);
}

void solve2() {
	if (d % (res[2] - res[1]) == 0 && d / (res[2] - res[1]) == 1) printf("0\n");
	else if (d % (res[2] - res[1]) == 0) {
		printf("%d\n", n - (d / (res[2] - res[1]) * 2 - 1));
	} else printf("0\n");
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	c = read();
	t = read();
	while (t--) {
		n = read();
		d = read();
		for (ll i = 1; i <= n; ++i) {
			res[i] = read();
		}
		if (n <= 300) solve1();
		else solve2();
	}
}
