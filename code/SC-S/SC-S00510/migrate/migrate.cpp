/*
17:52 凑了老久性质终于调出来了喵~ 对拍了数万组应该没有问题了吧 awa
*/
#include <cassert>
#include <iostream>

using namespace std;

#define il inline
#define cstex constexpr
#define endl '\n'
#define frer(filename) assert(freopen(filename, "r", stdin))
#define frew(filename) assert(freopen(filename, "w", stdout))

using ll = int64_t;

cstex int N = 2e6, XN = N + 10;
int kase, T, n; ll d, a[XN];
int pe[XN], ne[XN], ap[XN], an[XN];
int f[XN], g[XN]; ll res;

int main() {
	frer("migrate.in"), frew("migrate.out");
	ios::sync_with_stdio(false), cin.tie(nullptr);
	for (cin >> kase >> T; T --> 0; ) {
		cin >> n >> d, res = 0;
		for (int i = 1; i <= n; i++) cin >> a[i], ap[i] = an[i] = 0;
		for (int i = 1, j = 1; i <= n; i++) { while (a[i] - a[j] > d) j++; ap[pe[i] = j]++; }
		for (int i = 1, j = 1; i <= n; i++) { while (j < n && a[j + 1] - a[i] <= d) j++; an[ne[i] = j]++; }
		for (int i = 1; i <= n; i++) if (pe[i] < i && ne[pe[i]] == i) f[i] = f[pe[i]] + an[i]; else f[i] = an[i];
		for (int i = n; i >= 1; i--) if (ne[i] > i && pe[ne[i]] == i) g[i] = g[ne[i]] + ap[i]; else g[i] = ap[i];
		for (int i = 2; i + 1 < n; i++) if (pe[i + 1] < i && ne[i] > i + 1) {
			int cl = 0, cr = 0;
			if (pe[i] == pe[i + 1]) cl = f[i + 1]; else cl = an[i + 1];
			if (ne[i] == ne[i + 1]) cr = g[i]; else cr = ap[i];
			res += ll(cl) * cr;
		}
		cout << res << endl;
	}
	return 0;
}
