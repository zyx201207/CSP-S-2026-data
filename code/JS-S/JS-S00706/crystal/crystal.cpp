#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll a[500005], pre[500005];

ll check(int l, int r) {
	return a[r] * (r - l + 1) - (pre[r] - pre[l - 1]);
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	ll m;
	scanf("%d %lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + a[i];
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i;
		while (l < r) {
			int mid = (l + r) / 2;
			if (check(mid, i) <= m) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		ans = max(ans, i - l + 1);
	}
	printf("%d", ans);
}