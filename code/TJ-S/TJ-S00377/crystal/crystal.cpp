#include <bits/stdc++.h>

int n, ans;
long long m, a[500005], A[500005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
	}
	std::sort(a + 1, a + n + 1);
	int l = 1;
	for (int i = 1; i <= n; ++i) {
		A[i] = A[i - 1] + a[i];
		while (1ll * (i - l + 1) * a[i] - (A[i] - A[l - 1]) > m) {
			++l;
		}
		ans = std::max(ans, i - l + 1);
	}
	printf("%d\n", ans);
	return 0;
}

