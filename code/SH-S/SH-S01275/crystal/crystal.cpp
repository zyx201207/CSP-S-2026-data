#include <cstdio>
#include <algorithm>

long long n, m;
long long a[500005], sum[500005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
	}
	std::sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i) {
		sum[i] = sum[i - 1] + a[i];
	}
	int ans = 1;
	for (int i = 2; i <= n; ++i) {
		int l = 1, r = i;
		bool flag = false;
		while (l < r) {
			int mid = l + r >> 1;
			if (a[i] * (i - mid + 1) - (sum[i] - sum[mid - 1]) <= m) {
				r = mid;
				flag = true;
			}
			else {
				l = mid + 1;
			}
		}
		if (i - r + 1 > ans && flag) ans = i - r + 1;
	}
	printf("%d", ans);
	return 0;
}
