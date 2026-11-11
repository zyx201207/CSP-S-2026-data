#include <bits/stdc++.h>
#define REP(i, l, r) for (int i = (l); i <= (r); i ++)
#define DEP(i, r, l) for (int i = (r); i >= (l); i --)
#define fi first
#define se second
#define pb emplace_back
#define mems(a, v) memset((a), (v), sizeof(a))
#define memc(a, b) memset((a), (b), sizeof(a))
#define ALL(x) ((x).begin(), (x).end())
#define SZ(x) (int)((x).size())
using namespace std;
namespace Milkcat {
	typedef long long LL;
	typedef pair<LL, LL> pii;
	const int N = 1e6 + 5, M = 505;
	LL n, m, k, q, x, y, z, a[N], f[M][M];
	vector<pii> g[N];
	void ckmn(LL &x, LL y) { (x > y) && (x = y); }
	int main() {
		cin >> n >> m >> k >> q;
		REP(i, 1, m) cin >> a[i];
		REP(i, 1, n) {
			cin >> x;
			while (x --) cin >> y >> z, g[y].pb(i, z);
		}
		REP(i, 1, n) REP(j, 1, n)
			f[i][j] = (i == j ? 0 : 1e18);
		REP(i, 1, m) {
			for (auto [x, p] : g[i])
				for (auto [y, q] : g[i]) ckmn(f[x][y], p + q);
		}
		REP(k, 1, n) REP(i, 1, n) REP(j, 1, n)
			ckmn(f[i][j], f[i][k] + f[k][j]);
		REP(te, 1, q) {
			cin >> x >> y, z = 1e18;
			for (auto [i, p] : g[x])
				for (auto [j, q] : g[y]) ckmn(z, f[i][j] + p + q);
			cout << z + a[x] + a[y] << '\n';
		}
		return 0;
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	int O, T = 1; cin >> O;
	while (T --) Milkcat::main();
	return 0;
}