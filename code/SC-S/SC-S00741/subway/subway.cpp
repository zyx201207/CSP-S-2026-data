#include<bits/stdc++.h>
//#define int ll
#define ll long long
#define el cout<<"\n"
#define pii pair<int,int>
#define fi first
#define se second
#define itn int
using namespace std;
const int N = 510, M = 500010;
int T = 1, c, n, m, d, q, w[M], k[M], x, y;
ll e[N][N];
vector<pair<int, ll>>rv[M];
void solve() {
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> x >> y;
			rv[x].push_back({i, y});
		}
	}
	memset(e, 0x3f, sizeof(e));
	for (int i = 1; i <= n; i++)e[i][i] = 0;
	for (int i = 1; i <= m; i++)
		for (int u = 0; u < rv[i].size(); u++)
			for (int v = u + 1; v < rv[i].size(); v++) {
				e[rv[i][u].fi][rv[i][v].fi] = min(e[rv[i][u].fi][rv[i][v].fi], rv[i][u].se + rv[i][v].se);
				e[rv[i][v].fi][rv[i][u].fi] = min(e[rv[i][v].fi][rv[i][u].fi], rv[i][u].se + rv[i][v].se);
			}
	for (itn k = 1; k <= n; k++)
		for (itn i = 1; i <= n; i++)
			for (itn j = 1; j <= n; j++)
				e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
	while (q--) {
		int x, y;
		cin >> x >> y;
		ll ans = 1e17;
		for (auto u : rv[x])
			for (auto v : rv[y])
				ans = min(ans, u.se + e[u.fi][v.fi] + v.se);
		cout << w[x] + ans + w[y];
		el;
	}
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
//	cin >> T;
	while (T--)solve();
	return 0;
}