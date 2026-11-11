#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m, ans = 1, a[500005], sum[500005];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++i) {
		sum[i] = sum[i - 1] + a[i];
		int ld = 0, rd = i - 1, mid, tmpa = 0;
		while (ld <= rd) {
			mid = (ld + rd) >> 1;
			if (mid * a[i] - (sum[i - 1] - sum[i - mid - 1]) <= m) {
				ld = mid + 1;
				tmpa = mid;
			} else {
				rd = mid - 1;
			}
		}
		ans = max(ans, tmpa + 1);
	}
	printf("%lld\n", ans);
	return 0;
}
