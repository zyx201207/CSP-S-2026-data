#include <bits/stdc++.h>

using ll = long long;
const int N = 5e5 + 5;

int n, ans;
ll m, a[N], sum;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	
	std::cin >> n >> m;
	for (int i = 1; i <= n; i ++) std::cin >> a[i];
	std::sort(a + 1, a + n + 1);
	
	for (int i = 1, j = 1; i <= n; i ++) {
		sum += a[i];
		while (j <= i && a[i] * (i - j + 1) - sum > m) sum -= a[j ++];
		ans = std::max(ans, i - j + 1);
	}
	
	std::cout << ans << '\n';
	return 0;
}