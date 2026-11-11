#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 500010;

LL n, m, ans;
LL a[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= n; ++ i)
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	LL now = 0, l = 1, r = 1;
	while(r <= n) {
		while(now > m) {
			now -= (a[r] - a[l]);
			++ l;
		}
		ans = max(ans, r - l + 1);
		LL t = a[r + 1] - a[r];
		now += (r - l + 1) * t;
		++ r;
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
