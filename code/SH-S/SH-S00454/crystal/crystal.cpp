#include <iostream>
#include <algorithm>
#include <limits.h>
using ll = __int128;
long long n, m;
long long a[500001];
ll sum[500001];
ll ans;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout); 
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	std::sort(a + 1, a + n + 1); 
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
		ll l = 0, r = i - 1;
		ll mid;
		while (l < r) {
			mid = (l + r) / 2;
			if ((a[i] * (i - mid)) - (sum[i - 1] - sum[mid - 1]) <= m) { 
				r = mid;
			}
			else {
				l = mid + 1;
			}
		}
		ans = std::max(ans, i - r + 1);
	}
	std::cout << static_cast <long long> (ans) << "\n";
	return 0;
}
