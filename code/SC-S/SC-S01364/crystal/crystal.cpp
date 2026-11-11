#include <bits/stdc++.h> 
#define ll long long 
#define rep(i, j, k) for (int i = j; i <= k; i++) 
#define dow(i, j, k) for (int i = j; i >= k; i--) 

const int N = 5e5 + 5; 

int n; 
ll m, a[N], sum[N]; 

int bound(int i) {
	int l = 1, r = i - 1, mid, ans = i; 
	while (l <= r) {
		mid = (l + r) >> 1; 
		if (a[i] * (i - mid + 1) - (sum[i] - sum[mid - 1]) <= m) {
			r = mid - 1; ans = mid; 
		} else l = mid + 1; 
	}
	return ans; 
}

signed main() {
//	freopen("crystal5.in", "r", stdin); 
	freopen("crystal.in", "r", stdin); 
	freopen("crystal.out", "w", stdout); 
	
	scanf("%d%lld", &n, &m); 
	rep(i, 1, n) scanf("%lld", a + i); 
	std::sort(a + 1, a + n + 1); 
	rep(i, 1, n) sum[i] = sum[i - 1] + a[i]; 
	
	int ans = 0; 
	rep(i, 1, n) {
		int j = bound(i); 
		ans = std::max(ans, i - j + 1); 
	}
	printf("%d\n", ans); 
	
	return 0; 
}