#include <bits/stdc++.h>

typedef long long ll;
const ll MAXN = 5000 + 5;

ll read() {
	ll x = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') {x = (x << 1) + (x << 3) + c - '0'; c = getchar();}
	return x * f;
}

ll n, m;
ll a[MAXN];
std::queue<std::pair<ll, ll> > q;
ll f[MAXN];
ll vis[MAXN];

std::vector<int> z[MAXN];

void add(ll s, ll e) {
	z[s].emplace_back(e);
}

void solve() {
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		z[i].clear();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			if(i != j && llabs(a[i] - a[j]) <= m)
				add(i, j);
	}
//	for (int i = 1; i <= n; i++)
//		for (auto to : z[i])
//			std::cout << i << ' ' << to << '\n';
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			f[j] = 0, vis[j] = 0;
		while(q.size())
			q.pop();
		q.push({i, 1});
		vis[i] = 1;
		while(q.size()) {
			ll now = q.front().first, x = q.front().second;
//			std::cout << now << ' ' << x << '\n';
			q.pop();
			for (auto to : z[now]) {
				if(vis[to]) {
					if(vis[to] == x + 1)
						f[to]++;
					continue;
				}
				vis[to] = x + 1;
//				f[to]
				q.push({to, x + 1});
			}
		}
		for (int j = 1; j <= n; j++) {
			if(f[j] == 1)
				++ans;
//			std::cout << f[j] << ' ';
		}
//		std::cout << '\n';
			
	}
	std::cout << ans / 2 << '\n';
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ll c = read(), T = read();
	while(T--)
		solve();

	return 0;
}

