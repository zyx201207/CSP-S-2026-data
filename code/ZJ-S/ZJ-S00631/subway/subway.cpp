#include <bits/stdc++.h>

using namespace std;

const int N = 510, M = 5e5 + 10;
#define int long long
using ll = long long;
using pii = pair<int, int>;
#define fi first
#define se second

int Typ, n, m, d, q, L[N];
vector<int> a[N], t[N];
int w[M]; vector<pii> c[M];
ll f[N][N];

signed main() {
	freopen("subway.in", "r", stdin); freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> Typ >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++ ) cin >> w[i];
	for (int i = 1; i <= n; i ++ ) {
		cin >> L[i]; a[i].resize(L[i] + 1), t[i].resize(L[i] + 1);
		for (int j = 1; j <= L[i]; j ++ ) cin >> a[i][j] >> t[i][j], c[a[i][j]].push_back({i, j});
	} memset(f, 0x3f, sizeof f);
	for (int i = 1; i <= n; i ++ ) f[i][i] = 0;
	for (int i = 1; i <= m; i ++ ) {
		for (int j = 0; j < (int)c[i].size(); j ++ ) for (int k = j + 1; k < (int)c[i].size(); k ++ ) {
			int x = c[i][j].fi, y = c[i][k].fi;
			f[x][y] = min(f[x][y], (ll)t[x][c[i][j].se] + t[y][c[i][k].se]);
			f[y][x] = min(f[y][x], (ll)t[x][c[i][j].se] + t[y][c[i][k].se]);
		}
	}
	for (int k = 1; k <= n; k ++ ) for (int i = 1; i <= n; i ++ ) for (int j = 1; j <= n; j ++ )
		if (i != k && k != j && j != i) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	while (q -- ) {
		int x, y; cin >> x >> y; 
		ll res = 1e18;
		for (int i = 0; i < (int)c[x].size(); i ++ ) for (int j = 0; j < (int)c[y].size(); j ++ ) {
			res = min(res, (ll)w[x] + w[y] + t[c[x][i].fi][c[x][i].se] + t[c[y][j].fi][c[y][j].se] + f[c[x][i].fi][c[y][j].fi]);
		} cout << res << '\n';
	} return 0;
}
