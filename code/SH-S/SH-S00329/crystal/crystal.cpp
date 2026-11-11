#include <bits/stdc++.h>
using namespace std; 

#define int long long 
int n, m, a[500005], s[500005], ans = 0; 
signed main() {
	freopen("crystal.in", "r", stdin); 
	freopen("crystal.out", "w", stdout); 
	cin >> n >> m; 
	for (int i = 1; i <= n; i ++) {
		cin >> a[i]; 
	} 
	sort(a + 1, a + n + 1); 
	for (int i = 1; i <= n; i ++) {
		s[i] = s[i-1] + a[i]; // 统计前缀和 
	}
	int l = 1; 
	for (int r = 1; r <= n; r ++) { // 将l-r所有的数都改成a[r] 
		int d = a[r] * (r-l+1) - (s[r] - s[l-1]);
		while (l <= r && d > m) {
			l ++; 
			d = a[r] * (r-l+1) - (s[r] - s[l-1]);
		}
		// d为需要操作的次数
		ans = max(ans, r - l + 1); 
	}
	cout << ans << endl; 
}
