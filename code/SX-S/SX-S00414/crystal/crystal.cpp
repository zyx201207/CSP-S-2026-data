#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500010];
long long l = 1, r, c = 0, ans = LLONG_MIN;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	r = 1;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	while (r < n) {
		if (l == r && a[r + 1] - a[r] > m && l < n) {
			l++, r++, c = 0;
		} else if (r < n && c + (a[r + 1] - a[r]) * (r - l + 1) <= m) {
			c += (a[r + 1] - a[r]) * (r - l + 1);
			r++;
		} else {
			c -= a[r] - a[l];
			l++;
		}
		//cout << l << " " << r << " " << c << endl;
		ans = max(ans, r - l + 1);
	}
	printf("%lld", ans);
	return 0;
}
