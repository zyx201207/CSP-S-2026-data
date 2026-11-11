#include <bits/stdc++.h>
#define int int64_t

const int maxn = 524288;

int n, m;
int a[maxn], s[maxn];

bool check(int x) {
	for (int i = x; i <= n; i++) {
		int sum = s[i] - s[i - x];
		if (sum + m >= a[i] * x) return true;
	} return false;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		std::cin >> a[i];
		
	std::sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
		
	int l = 1, r = n, ans = 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		} else 
			r = mid - 1;
	}
	
	std::cout << ans << std::endl;
	
	return 0;
} 
