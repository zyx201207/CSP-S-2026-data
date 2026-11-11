#include <bits/stdc++.h>

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	
	int n; long long m;
	std::cin >> n >> m;
	
	std::vector <long long> a(n);
	for(long long& i : a) {
		std::cin >> i;
	}
	
	std::sort(a.begin(), a.end());
	
	std::vector <long long> sum(n + 1, 0);
	for(int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i - 1];
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int l = 1, r = i;
		int ok = 1;
		while(l <= r) {
			int mid = (l + r) >> 1;
			long long need = a[i - 1] * mid - (sum[i] - sum[i - mid]);
			if(need <= m) {
				l = mid + 1;
				ok = mid;
			} else {
				r = mid - 1;
			}
		}
		ans = std::max(ok, ans);
	}
	std::cout << ans;
	return 0;
}