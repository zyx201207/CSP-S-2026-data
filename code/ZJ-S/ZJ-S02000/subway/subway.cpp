#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 5e2 + 10, M = 5e5 + 10;
template<typename T>
void debug(const T &x) { cout << x << '\n'; }
template<typename Type, typename ...Types>
void debug(const Type &arg, const Types &...args) { cout << arg << ' '; debug(args...); }
#ifdef LOCAL
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]: ", debug(__VA_ARGS__)
#else
#define dbg(...) 42
#endif

namespace Loop1st {
const ll inf = 1ll << 60;
int n, m, D, Q;
ll f[N][N], w[M];
vector<int>c[M], t[M];
void Main() {
	cin >> n >> m >> D >> Q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int k; cin >> k;
		for (int j = 1, x, y; j <= k; j++) {
			cin >> x >> y;
			c[x].push_back(i);
			t[x].push_back(y);
		}
	}
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
		if (i == j) f[i][j] = 0;
		else f[i][j] = inf;
	}
	for (int u = 1; u <= m; u++) {
		int sz = (int)c[u].size();
		for (int p = 0; p < sz; p++) {
			for (int q = p + 1; q < sz; q++) {
				int i = c[u][p], j = c[u][q];
				if (i > j) swap(i, j);
				f[i][j] = min(f[i][j], (ll)t[u][p] + t[u][q]);
			}
		}
	}
	for (int i = 1; i <= n; i++) for (int j = 1; j < i; j++) f[i][j] = f[j][i];
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) if (f[i][k] < inf) {
			for (int j = 1; j <= n; j++) {
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	while (Q--) {
		int x, y; cin >> x >> y;
		ll ans = inf;
		for (int p = 0; p < (int)c[x].size(); p++) for (int q = 0; q < (int)c[y].size(); q++) {
			ans = min(ans, f[c[x][p]][c[y][q]] + t[x][p] + t[y][q]);
		}
		cout << ans + w[x] + w[y] << '\n';
	}
}

}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	auto st = clock();
	int C = 0, T = 1;
	cin >> C;
	while (T--) Loop1st::Main();
	cerr << fixed << setprecision(10) << "Time = " << 1. * (clock() - st) / CLOCKS_PER_SEC << '\n';
	return 0;
}
