#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int n, m, a[N], ans, mx = 1, cnt;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + 1 + n);
	for (int l = 1, r = 1; r < n;) {
		if (cnt + (a[r + 1] - a[r]) * (r - l + 1) <= m) {
			cnt += (a[r + 1] - a[r]) * (r - l + 1);
			r++, mx++, ans = max(ans, mx);
		} else {
			cnt -= (a[r] - a[l]), mx--;
			if (l < r)
				l++;
			else
				break;
		}
	}
	printf("%lld", ans);
}