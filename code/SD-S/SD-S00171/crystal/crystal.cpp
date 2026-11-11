#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6 + 11;
int n, m, a[N], s[N], ans;

signed main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf ("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf ("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++)
		s[i] = s[i - 1] + (i - 1) * (a[i] - a[i - 1]);
	for (int i = 2; i <= n; i++) {
		int l = 1, r = i - 1, res = i;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (s[i] - s[mid] - (a[i] - a[mid]) * (mid - 1) <= m)
				r = mid - 1, res = mid;
			else
				l = mid + 1;
		}
		ans = max(ans, i - res + 1);
	}
	printf ("%lld\n", ans);
	return 0;
}

