#include <bits/stdc++.h>
const int maxn = 5e5 + 10;
long long a[maxn], sum[maxn];
long long m;
int n;
bool check(int x) {
	long long need = 1e18 + 2;
	for (int i = x; i <= n; i++) {
		long long ans = 0;
		ans = a[i] * x;
		ans -= (sum[i] - sum[i - x]);
//		for (int j = i - x + 1; j <= i; j++) {
//			ans -= a[j];
//		}
		need = std::min(need, ans);
	}
	return need <= m;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	std::cin >> n >> m;
	sum[0] = 0;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	std::sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	int l = 1, r = n + 1;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	std::cout << l - 1;
	return 0;
}
