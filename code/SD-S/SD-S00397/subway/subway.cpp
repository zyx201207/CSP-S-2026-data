#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef __int128 i128;

const ll inf = 0x3f3f3f3f3f3f3f3f;
int ___, n, m, d, q;
ll w[500005], dis[505][505];
vector <pair <int, ll>> to[500005];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> ___ >> m >> n >> d >> q;
	for (int i = 1; i <= n; ++ i) cin >> w[i];
	for (int i = 1, k, a, t; i <= m; ++ i) {
		cin >> k;
		for (int j = 1; j <= k; ++ j) {
			cin >> a >> t;
			to[a].emplace_back(i, t);
		}
	}
	for (int i = 1; i <= m; ++ i)
		for (int j = 1; j <= m; ++ j) dis[i][j] = (i != j) * inf;
	for (int i = 1; i <= n; ++ i) {
		for (auto e1 : to[i]) {
			for (auto e2 : to[i]) {
				if (e1 == e2) continue ;
				dis[e1.fi][e2.fi] = dis[e2.fi][e1.fi] = min(dis[e1.fi][e2.fi], e1.se + e2.se);
			}
		}
	}
	for (int k = 1; k <= m; ++ k) {
		for (int i = 1; i <= m; ++ i)
			for (int j = 1; j <= m; ++ j) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	}
	for (int x, y; q; -- q) {
		cin >> x >> y;
		ll ans = inf;
		for (auto e1 : to[x])
			for (auto e2 : to[y]) ans = min(ans, w[x] + w[y] + dis[e1.fi][e2.fi] + e1.se + e2.se);
		cout << ans << '\n';
	}
	return 0;
}
