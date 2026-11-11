#include <bits/stdc++.h>
#define re register
#define l long long
#define rl re l
using namespace std;
l n, m, a[500006], ans = 1;

void mian() {
	cin >> n >> m;
	for (l i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	l ll = n, rr = n, su = 0;
	while (ll >= rr && ll != 1 && rr != 0) {
		if (ll == rr) {
			rr--;
			continue;
		}
		su += a[ll] - a[rr];
//		printf("%lld %lld %lld\n", rr, ll, su);
		if (su <= m) {
			ans = max(ans, ll - rr + 1);
			rr--;
		} else {
			su -= a[ll] - a[rr];
			su -= (a[ll] - a[ll - 1]) * (ll - rr - 1);
			ll--;
		}
	}
	printf("%lld", ans);
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	mian();
	return 0;
}
