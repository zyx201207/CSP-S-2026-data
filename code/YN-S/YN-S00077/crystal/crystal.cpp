#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500001];
int n, m;

bool cheak(int x) {
	int s = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] < x) {
			s += x - a[i];
		}
		if (s > m) {
			return false;
		}
	}
	return s <= m;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	int l = a[1], r = a[n] + m, ans = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (cheak(mid)) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] <= ans) {
			cnt++;
		}
	}

	printf("%lld", cnt);
	return 0;
}