#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 2e6;

vector<ll> g[N];
ll c, T, n, d, ans, cnt, tmp = LLONG_MAX;
ll a[N], sumn[N], dis[N];

void dfs(ll u, ll endv) {
	if (u == endv) {
		if (tmp == dis[u])
			cnt++;
		if (tmp > dis[u]) {
			cnt = 1;
			tmp = dis[u];
		}
		return ;
	}
	for (auto v : g[u]) {
		if (dis[u]  >= dis[v])
			continue;
		dis[v] = dis[u] + 1;
		dfs(v, endv);
	}
}



int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> c >> T;
	while (T--) {
		ans = 0;
		cin >> n >> d;
		if (n <= 5000) {
			for (ll i = 1; i <= n; i++) {
				cin >> a[i];
				sumn[i] = sumn[i - 1] + a[i] - a[i - 1];
				sumn[1] = 0;
			}

			for (ll i = 1; i <= n; i++) {
				for (ll j = i + 1; j <= n; j++) {
					if (sumn[j] - sumn[i] <= d) {
						g[i].push_back(j);
					}

					else
						break;
				}
			}

			for (ll i = 1; i <= n; i++) {
				for (ll j = i + 3; j <= n; j++) {
					for (ll k = 1; k <= n; k++) {
						dis[k] = LLONG_MAX;
					}
					dis[i] = 0;
					cnt = 0, tmp = LLONG_MAX;
					dfs(i, j);
					if (cnt == 2)
						ans++;
				}
			}
		}
		cout << ans << "\n";
	}

	return 0;
}