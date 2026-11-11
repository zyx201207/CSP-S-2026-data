#include <iostream>
#include <algorithm>
#include <cstring>

using ll = long long;
constexpr int MAXN = 5e5 + 10;

ll val[MAXN], pref[MAXN];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	int n;
	ll m;
	std::cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		std::cin >> val[i];
	}
	
	std::sort(val + 1, val + 1 + n);
	
	for (int i = 1; i <= n; i++) {
		pref[i] = pref[i - 1] + val[i];
	}
	
	ll diff = 0;
	int res = 0;
	
	for (int l = 1, r = 1; r <= n; r++) {
		diff = val[r] * (r - l + 1) - (pref[r] - pref[l - 1]);
		while (diff > m) { diff -= val[r] - val[l]; l++; }
		res = std::max(res, r - l + 1);
	}
	
	std::cout << res << std::endl;
	
	return 0;
}