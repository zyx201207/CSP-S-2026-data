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
	int n, a[N]; mt19937 egn(time(0));
	int main() {
		n = 1e6;
		REP(i, 1, n) a[i] = i;
		shuffle(a + 1, a + 1 + n, egn);
		cout << "0 2\n";
		REP(te, 1, 2) {
			cout << n << ' ' << 2 << '\n';
			REP(i, 2, n) cout << a[i - 1] << ' ' << a[i] << '\n';
		}
		return 0;
	}
}
int main() {
	freopen("hub.in", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	int T = 1;
	while (T --) Milkcat::main();
	return 0;
}