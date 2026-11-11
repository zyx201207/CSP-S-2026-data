#include <bits/stdc++.h>
#define REP(i, l, r) for (int i = (l); i <= (r); i ++)
#define DEP(i, r, l) for (int i = (r); i >= (l); i --)
#define fi first
#define se second
#define pb emplace_back
#define mems(a, v) memset((a), (v), sizeof(a))
#define memc(a, b) memset((a), (b), sizeof(a))
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)((x).size())
using namespace std;
namespace Milkcat {
	typedef long long LL;
	typedef pair<LL, LL> pii;
	const int N = 1e6 + 5;
	int n, k, x, y, rs, fa[N], vs[N], d[N], l[N], r[N], h[N], L[N], R[N];
	vector<int> G[N], vl[N];
	void dfs1(int x) {
		for (int y : G[x])
			if (y != fa[x]) fa[y] = x, d[y] = d[x] + 1, dfs1(y);
	}
	int dfs2(int x, int fa, vector<int> &s) {
		int d = 0;
		for (int y : G[x])
			if (y != fa && !vs[y]) d = max(d, dfs2(y, x, s) + 1);
		if (SZ(s) <= d) s.pb(0);
		return s[d] += !vs[x], d;
	}
	void init() {
		int m = n, p = 0, q = 0; n = 0;
		d[1] = 0, dfs1(1), p = max_element(d + 1, d + 1 + m) - d, fa[p] = 0;
		d[p] = 0, dfs1(p), q = max_element(d + 1, d + 1 + m) - d;
		while (q > 0) vs[q] = ++ n, q = fa[q];
		REP(i, 1, m)
			if (vs[i]) d[vs[i]] = dfs2(i, 0, vl[vs[i]]);
		REP(i, 1, m) fa[i] = vs[i] = 0, G[i].clear();
	}
	int chk(int m) {
		int sm = 0, mn = 0, t = 0;
		REP(i, 1, n) {
			int x = max(m - d[i], 0);
			l[i] = max(i - x, 1), r[i] = min(i + x, n), h[r[i]] = max(h[r[i]], l[i]);
			if (m <= d[i]) sm += vl[i][m];
		}
		REP(i, 2, n) h[i] = max(h[i], h[i - 1]);
		REP(i, 1, n)
			if (h[r[i]] == l[i]) L[++ t] = l[i], R[t] = r[i];
		mn = max(L[t] - R[1] + 1, 1);
		REP(i, 1, t - 1) {
			int p = max(L[i] - R[1] + 1, 1);
			int q = max(L[t] - R[i + 1] + 1, 1);
			mn = min(mn, p + q);
		}
		REP(i, 1, n) h[i] = 0;
		return (sm + mn <= k);
	}
	int main() {
		cin >> n >> k;
		REP(i, 2, n) cin >> x >> y, G[x].pb(y), G[y].pb(x);
		init();
		REP(i, 1, n) DEP(j, d[i], 1)
			vl[i][j - 1] += vl[i][j];
		DEP(i, __lg(n), 0)
			if (!chk(rs | 1 << i)) rs |= 1 << i;
		cout << rs + 1 << '\n', rs = 0;
		REP(i, 1, n) vl[i].clear();
		return 0;
	}
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	int O, T = 1; cin >> O >> T;
	while (T --) Milkcat::main();
	return 0;
}