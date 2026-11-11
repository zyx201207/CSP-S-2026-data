#include <bits/stdc++.h>
#define ll long long
const int N = 5e5 + 5;
int n;
ll m, a[N], pre[N];
int main() {
	std::cin.tie(0)->sync_with_stdio(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		std::cin >> a[i];
	std::sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i)
		pre[i] = pre[i - 1] + a[i];
	int ans = 0;
	// sum a[i] - a[j] <= m
	for (int i = 1; i <= n; ++i) {
		int l = 1, r = i, pos = i;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (1ll * (i - mid + 1) * a[i] - pre[i] + pre[mid - 1] <= m)
				r = (pos = mid) - 1;
			else l = mid + 1;
		}
		ans = std::max(ans, i - pos + 1);
	}
	std::cout << ans << "\n";
}