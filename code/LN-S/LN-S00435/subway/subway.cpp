#include <bits/stdc++.h>
#define ll long long
#define pii pair <int, int>
#define pll pair <ll, ll>
#define fi first
#define se second
#define y1 csps300
#define stp(x) fixed << setprecision(x)

using namespace std;

const int N = 5e5 + 50, p = 998244353, inf = 1 << 29;

int n, m, d, q;
ll a[N], f[505][505];
vector <pll> b[N];

void init() {
	
}

void solve() {
	int id;
	cin >> id >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		while (k--) {
			int x, t;
			cin >> x >> t;
			b[x].push_back({i, t});
		}
	}
	memset(f, 0x3f, sizeof(f));
	for (int i = 1; i <= n; i++) 
		f[i][i] = 0;
	for (int i = 1; i <= m; i++) {
		int sz = b[i].size();
		for (int j = 0; j < sz; j++) 
			for (int k = 0; k < sz; k++) {
				int u = b[i][j].fi, v = b[i][k].fi;
				ll ut = b[i][j].se, vt = b[i][k].se;
				f[u][v] = min(f[u][v], ut + vt);
				f[v][u] = min(f[v][u], ut + vt);
			}
	}
	for (int k = 1; k <= n; k++) 
		for (int i = 1; i <= n; i++) 
			for (int j = 1; j <= n; j++) 
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	while (q--) {
		int x, y;
		cin >> x >> y;
		ll ans = 1LL << 60;
		for (int j = 0; j < b[x].size(); j++) 
			for (int k = 0; k < b[y].size(); k++) 
				ans = min(ans, a[x] + a[y] + b[x][j].se + b[y][k].se + f[b[x][j].fi][b[y][k].fi]);
		cout << ans << '\n';
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	init();
	int t = 1;
	// cin >> t;
	while (t--) solve();
	return 0;
}