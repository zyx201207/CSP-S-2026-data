#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace migrate {
	int c, t, n, d;
	const int MAXN = 2e6 + 5;
	int x[MAXN];
	namespace specialA {
		void solve() {
			while (t--) {
				scanf("%lld%lld", &n, &d);
				for (int i = 1; i <= n; i++) {
					scanf("%lld", &x[i]);
				}
				if (x[n] - x[n - 1] == 0) printf("0");
				else {
					d /= x[n] - x[n - 1];
				printf("%lld\n", n - (d + d - 1));
				}
			}
		}
	}
	void solve() {
		scanf("%lld%lld", &c, &t);
//		if (c == 11 || c == 12)
			specialA::solve();
	}
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	migrate::solve();
	return 0;
}

