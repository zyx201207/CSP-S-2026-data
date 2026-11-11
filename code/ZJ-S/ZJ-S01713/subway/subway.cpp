#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline ll read() {
	ll x = 0, f = 1;
	
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	
	return x * f;
}
inline void write(ll x) {
	if (x < 0) putchar('-'), x = -x;
	
	char s[70];
	ll n = 0;
	
	do {
		s[n ++] = x % 10 + '0';
		x /= 10;
	} while (x);
	
	while (n --) putchar(s[n]);
}
void solve () {
	ll c = read(), n = read(), m = read(), d = read(), q = read();
	
	ll w[m + 1];
	for (ll i = 1; i <= m; ++ i) {
		w[i] = read();
	}
	
	ll k[n + 1];
	ll a[n + 1][m + 1];
	ll t[n + 1][m + 1];
	vector<ll> ys[m + 1];
	for (ll i = 1; i <= n; ++ i)  {
		k[i] = read();
		
		for (ll j = 1; j <= k[i]; ++ j) {
			a[i][j] = read();
			t[i][a[i][j]] = read();
			ys[a[i][j]].push_back(i);
		}
	}
	
	while (q --) {
		ll x = read(), y = read();
		
		ll dis[m + 1];
		for (ll i = 1; i <= m; ++ i) {
			dis[i] = 1000000000000000000ll;
		}
		
		struct node {
			ll x, l, d;
		};
		queue<node>qu;
		qu.push({x, -1, 0});
		dis[x] = 0;
		
		while (qu.size()) {
			auto [x, l, d] = qu.front();
			qu.pop();
			
			if (d != dis[x]) continue;
			
			// first take a subway
			if (l == -1) {
				for (auto &e : ys[x]) {
					for (ll i = 1; i <= k[e]; ++ i) {
						if (a[e][i] == x) continue;
						ll y = a[e][i];
						
						if (dis[y] > d + t[e][x] + t[e][y]) {
							dis[y] = d + t[e][x] + t[e][y];
							qu.push({y, e, dis[y]});
						}
					}
				}
			} else {
				// still take the subway
				for (ll i = 1; i <= k[l]; ++ i) {
					if (a[l][i] == x) continue;
					ll y = a[l][i];
					
					if (dis[y] > d + t[l][y]) {
						dis[y] = d + t[l][y];
						qu.push({y, l, dis[y]});
					}
				}
				
				// take another subway
				for (auto &e : ys[x]) {
					if (e == l) continue;
					for (ll i = 1; i <= k[e]; ++ i) {
						if (a[e][i] == x) continue;
						ll y = a[e][i];
						
						if (dis[y] > d + t[e][x] + t[e][y]) {
							dis[y] = d + t[e][x] + t[e][y];
							qu.push({y, e, dis[y]});
						}
					}
				}
			}
		}
		
		write(dis[y] + w[x] + w[y]);
		putchar('\n');
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ll T = 1;
	while (T --) solve();
	return 0;
}