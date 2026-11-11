#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	int n;
	ll m;
	scanf("%d %lld", &n, &m);

	vector<ll> a(n + 1);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", &a[i]);

	sort(a.begin() + 1, a.end());

	vector<ll> pre(n + 1, 0);
	for (int i = 1; i <= n; ++i)
		pre[i] = pre[i - 1] + a[i];

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int l = 1, r = i;
		while (l <= r) {
			int mid = (l + r) >> 1;
			int cnt = i - mid + 1;
			ll cost = 1LL * cnt * a[i] - (pre[i] - pre[mid - 1]);
			if (cost <= m) {
				ans = max(ans, cnt);
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}