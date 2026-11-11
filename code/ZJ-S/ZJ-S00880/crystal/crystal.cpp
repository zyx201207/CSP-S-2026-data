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
	const int N = 1e6 + 5;
	LL n, m, sm, p, rs, a[N];
	int main() {
		cin >> n >> m;
		REP(i, 1, n) cin >> a[i];
		sort(a + 1, a + 1 + n), p = 1;
		REP(i, 1, n) {
			sm += (i - p) * (a[i] - a[i - 1]);
			while (sm > m) sm -= a[i] - a[p ++];
			rs = max(rs, i - p + 1);
		}
		cout << rs << '\n';
		return 0;
	}
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	int T = 1;
	while (T --) Milkcat::main();
	return 0;
}