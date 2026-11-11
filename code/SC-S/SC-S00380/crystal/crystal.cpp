#include<bits/stdc++.h>
using String = std::string;
constexpr int N = 5e5 + 5;

int n;
int64_t a[N];
int64_t m;

int32_t main() {
//	freopen("crystal\\crystal4.in", "r", stdin);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	std::cin.tie(nullptr) -> sync_with_stdio(false);
	
	std::cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	std::sort(a + 1, a + 1 + n);
	
	int ans = 0;
	int64_t res = 0;
	for(int i = 1, j = 1; i <= n; i++) {
		res += (i - j) * (a[i] - a[i - 1]);
		while(res > m) { res -= a[i] - a[j++]; }
		ans = std::max(ans, i - j + 1);
	}
	
	std::cout << ans;
	return 0;
}