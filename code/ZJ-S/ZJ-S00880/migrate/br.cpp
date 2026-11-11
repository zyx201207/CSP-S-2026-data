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
	int n, rs, pr[N], nx[N]; LL d, a[N];
	int chk(int l, int r) {
		vector<int> p, q; int t = 0;
		for (int x = l; x != r; x = min(nx[x], r)) p.pb(x);
		for (int x = r; x != l; x = max(pr[x], l)) q.pb(x);
		p.pb(r), q.pb(l), reverse(ALL(q));
		REP(i, 0, SZ(p) - 1) t += p[i] - q[i];
		return (t == 1);
	}
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
		// REP(i, 1, n) cerr << nx[i] << ' '; cerr << '\n';
		// REP(i, 1, n) cerr << pr[i] << ' '; cerr << '\n';
		int p = 1;
		REP(i, 1, n) {
			if (a[i] - a[i - 1] > d) p = i;
			REP(j, p, i - 1) rs += chk(j, i);
		}
		cout << rs << '\n';
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