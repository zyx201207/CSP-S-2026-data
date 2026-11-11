#include <bits/stdc++.h>
using namespace std;
long long n, m, ans, cnt;
long long a[500006];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];	
	}
	sort(a + 1, a + n + 1);
	long long l = 1, r = 1;
	while (l <= r and r <= n) {
		if (cnt <= m) {
			ans = max(ans, r - l + 1);
			cnt += (a[r + 1] - a[r]) * (r - l + 1);
			r++;
			if (r > n) break; 
		} else {
			cnt -= (a[r] - a[l]);
			l++;
		}	
	}
	cout << ans;
	return 0;
} 
