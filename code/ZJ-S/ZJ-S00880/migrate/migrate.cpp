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
	const int N = 2e6 + 5;
	int n, pr[N], nx[N], h[N], b[N], c[N], l[N], r[N]; LL rs, d, a[N], s[N];
	int main() {
		cin >> n >> d, rs = 0;
		REP(i, 1, n) cin >> a[i];
		nx[0] = 0, pr[n + 1] = n + 1;
		REP(i, 1, n) {
			int &p = nx[i]; p = nx[i - 1];
			while (p < n && a[p + 1] <= a[i] + d) p ++;
		}
		DEP(i, n, 1) {
			int &p = pr[i]; p = pr[i + 1];
			while (p > 1 && a[p - 1] >= a[i] - d) p --;
		}

		fill_n(h + 1, n, 0);
		REP(i, 1, n) h[nx[i]] = i;
		REP(i, 2, n) {
			int x = pr[i];
			b[i] = (nx[x] == i ? b[x] + 1 : 0);
			if (h[i] >= x) b[i] += h[i] - x;
		}

		fill_n(h + 1, n, n + 1);
		DEP(i, n, 1) h[pr[i]] = i;
		DEP(i, n - 1, 1) {
			int x = nx[i];
			c[i] = (pr[x] == i ? c[x] + 1 : 0);
			if (h[i] <= x) c[i] += x - h[i];
		}

		REP(i, 1, n) {
			l[i] = r[i - 1] + 1, r[i] = l[i] - 1;
			while (r[i] < n && nx[r[i] + 1] == i) r[i] ++;
		}
		REP(i, 1, n - 1) REP(x, l[i + 1], r[i + 1]) 
			if (x < i) s[i] += (pr[i] <= x) + (pr[i] == x ? b[x] : 0);

		REP(i, 1, n) {
			l[i] = r[i - 1] + 1, r[i] = l[i] - 1;
			while (r[i] < n && pr[r[i] + 1] == i) r[i] ++;
		}
		REP(i, 1, n - 1) {
			LL sm = 0;
			REP(y, l[i], r[i]) 
				if (y > i + 1) sm += (nx[i + 1] >= y) + (nx[i + 1] == y ? c[y] : 0);
			rs += s[i] * sm;
		}
		cout << rs << '\n';
		REP(i, 1, n) b[i] = c[i] = s[i] = 0;
		return 0;
	}
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	int O, T = 1; cin >> O >> T;
	while (T --) Milkcat::main();
	return 0;
}