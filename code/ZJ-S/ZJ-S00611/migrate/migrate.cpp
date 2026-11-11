#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
int n, d;
int x[N];
void solve1() {
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (x[i] - x[1] > d) {
			printf("%lld\n", ans * (n / i));
			return ;
		}
		ans++;
	}
}
void solve() {
	scanf("%lld%lld", &n, &d);
	bool A = 1;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &x[i]);
		if (i != 1 && i != 2 && x[i] - x[i - 1] != x[i - 1] - x[i - 2]) {
			A = 0;
		}
	}
	if (A) {
		solve1();
		return ;
	}
	printf("1\n");
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int C, T;
	scanf("%lld%lld", &C, &T);
	while (T--) {
		solve();
	}
	return 0;
}