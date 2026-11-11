
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e5 + 10;
ll n, m, ans, a[N];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	ll sum = 0, l = 1, r = 2;
	ans = 1;
	for (; r <= n; ++r) {
		sum += (a[r] - a[r - 1]) * (r - l);
		while (l < r && sum > m) {
			sum -= (a[r] - a[l]);
			l++;
		}
		ans = max(ans, r - l + 1);
	}
	printf("%lld", ans);
	return 0;
}
/*
5 5 
1 2 4 8 9
5 8
-3 -1 2 2 7
*/