#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 509;
const ll inf = 1e18;
ll c, n, m, d, qq;
vector<pair<ll, ll>>e[N];
ll w[N];
ll vis[N];
ll diss[N][N];

void bfs(ll s) {
	queue<ll>q;
	for (ll i = 1; i <= n; i++) {
		diss[s][i] = inf;
	}
	diss[s][s] = 0;
	q.push(s);
	while (!q.empty()) {
		auto it = q.front();
		q.pop();
		ll u = it;
		for (auto [v, val] : e[u]) {
			if (diss[s][v] == inf) {
			} else {

				q.push(v);
				diss[s][v] = min(diss[s][v], diss[s][u] + val - w[v] + w[u]);
			}
		}
	}


}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> qq;
	for (ll i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (ll i = 1; i <= n; i++) {
		ll k;
		cin >> k;
		for (ll j = 1; j <= k; j++) {
			ll t;
			cin >> t;
			e[i].push_back({j, t + w[t]});
		}
	}
	for (ll i = 1; i <=  n; i++) {
		bfs(i);
	}
	while (qq--) {
		ll u, v;
		cin >> u >> v;
		cout << diss[u][v] + w[u];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
