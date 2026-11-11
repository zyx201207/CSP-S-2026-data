#include <iostream>
#include <algorithm>
#include <cmath>

using ll = long long;

constexpr ll MAXN = 5e5+114ll, MAXM = 1e18+114ll;

ll n, m; ///< Crystal Count and Operation Count
ll A[MAXN]; ///< Crystals' power

///< Qu Jian's Length
inline ll length(ll l, ll r) {
	return r - l + 1;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w+", stdout);
	std::cin >> n >> m; // Input N and M(Crystal Count, Operation Count)
	for(ll i = 1; i <= n; ++i) {
		std::cin >> A[i];
	}
	std::sort(A, A + n); // Sort the crystals' power
	ll result = 0; ///< Max crystal count (Max Qu Jian Chang Du QwQ)
	ll diff = 0; ///< Current max element's diff than every elements, must <= m
	ll l = 1; ///< Qu Jian's beginning
	for(int r = 1; r <= n; ++r) {
		diff += (length(l, r) - 1) * (A[r] - A[r - 1]); // Update diff
		while(diff > m) {
//			std::cout << "REMOVING: l=" << l << ", r=" << r << ", A[l]=" << A[l] << ", A[r]=" << A[r] << ", diff -=" << (A[r] - A[l]) << ", diff_before=" << diff << std::endl;
			diff -= (A[r] - A[l]);
			++l;
		}
		result = std::max(result, length(l , r));
//		std::cout << "Current: " << l << ", " << r << ", L=" << length(l, r) << ", diff=" << diff << ", M=" << m << ", A[r]=" << A[r] << std::endl;
	}
	std::cout << result << std::endl;
	return 0;
}
