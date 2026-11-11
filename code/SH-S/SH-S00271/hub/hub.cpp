#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

ll c, T, n, k;
vector<ll> to[1000009];
ll d[1000009], f[1000009];

void dfs(ll u, ll fa) {
	d[u] = d[fa] + 1;
	f[u] = fa;
	for (auto v : to[u]) {
		if (v != fa)
			dfs(v, u);
	}
}
ll lt(ll u, ll fa, ll mask, ll sz) {
	ll msz = sz;
	for (auto v : to[u]) {
		if (v != fa) {
			ll ans = lt(v, u, mask, msz + ((mask & (1 << (v - 1))) && (!(mask & (1 << (u - 1))))));
			msz = max(msz, ans);
		}
	}
	return msz;
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> T;
	while (T--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
			to[i].clear();
		for (int i = 1; i < n; i++) {
			ll a, b;
			cin >> a >> b;
			to[a].emplace_back(b);
			to[b].emplace_back(a);
		}
		dfs(1, 0);
		ll mn = 0x3f3f3f3f;
		for (ll mask = 0; mask < (1ll << n); mask++) {
			if (__builtin_popcount(mask) != k || lt(1, 0, mask, mask & 1) > 2) {
				continue;
			}
			ll mx = 0;
			for (int i = 1; i <= n; i++) {
				ll mans = 0x3f3f3f3f;
				for (int j = 1; j <= n; j++) {
					if ((1 << (j - 1)) & mask) {
						ll ans = 0, u = i, v = j;
						while (d[u] > d[v])
							ans++, u = f[u];
						while (d[v] > d[u])
							ans++, v = f[v];
						while (v != u)
							ans++, u = f[u], ans++, v = f[v];
						mans = min(mans, ans);
						// if (i == 7 && mask == 0b0100000110)
						// 	cerr << ans << " " << j << endl;
					}
				}
				mx = max(mx, mans);
			}
			mn = min(mn, mx);
		}
		cout << mn << endl;
	}
	return 0;
}
// 100+100+48+15=263pts
// okay