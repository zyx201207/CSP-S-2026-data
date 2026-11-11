#include <bits/stdc++.h>
using namespace std;

//#define DEBUG
using ll = long long;
const int N = 5e5 + 5;
int n;
ll m, a[N], s[N];

int main() {
#ifndef DEBUG
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
#endif
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; ++i)scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i)s[i] = s[i - 1] + a[i];
	// (i - ed) * a[i] - (s[i] - s[ed]) <= m
	// i a[i] - s[i] <= m + ed * a[i] - s[ed]
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int l = 0, r = i;
		ll lhs = i * a[i] - s[i] - m;
		while(l < r) {
			int mid = l + r >> 1;
			ll rhs = mid * a[i] - s[mid];
			if(lhs <= rhs)r = mid;
			else l = mid + 1;
		}
		ans = max(ans, i - l);
	}
	printf("%d", ans);
	return 0;
}