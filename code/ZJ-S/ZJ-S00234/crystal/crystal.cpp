#include<bits/stdc++.h>
using namespace std;
long long n, m, a[500010], sum[500010], t, l, r, mid, ans;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		sum[i] = a[i] + sum[i - 1];
	}
	for (int i = n; i >= 1; i--) {
		l = 1, r = i;
		while (l <= r) {
			mid = (l + r) / 2;
			if (a[i] * (i - mid + 1) - sum[i] + sum[mid - 1] <= m) {
				ans = max(ans, i - mid + 1);
				r = mid - 1;
			} else l = mid + 1;
		}
	}
	cout << ans;
	return 0;
}
