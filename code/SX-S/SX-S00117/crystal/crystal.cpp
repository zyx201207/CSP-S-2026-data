#include <bits/stdc++.h>

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	long long n, m;
	std::cin >> n >> m;

	std::vector<long long> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::sort(a.begin() + 1, a.end());
	long long ans = 1;
	for (long long i = 1; i <= n; i++) {
		long long m2 = m;
		long long j = i;
		for (; j < n && m2 >= 0; j++) {
			m2 -= (a[j + 1] - a[j]) * j;
		}
		ans = std::max(ans, j - i);
		if (m2 >= 0)
			break;
	}
	std::cout << ans;
	return 0;
}
