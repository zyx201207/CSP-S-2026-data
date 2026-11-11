#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
ll a[1000010];
ll sum[1000010];

int find(int l, int r, ll num, int u) {
	int mid;
	int ret = u;
	while (l < r) {
		mid = (l + r) / 2;
		ll k = (u - mid) * a[u] - sum[u - 1] + sum[mid - 1];
		if (k <= num) {
			ret = mid;
			r = mid;
		} else
			l = mid + 1;
	}
	return ret;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	scanf("%d", &n);
	ll m;
	scanf("%lld", &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		int j = find(1, i, m, i);
		ans = max(ans, i - j + 1);
	}
	printf("%d\n", ans);
	return 0;
}