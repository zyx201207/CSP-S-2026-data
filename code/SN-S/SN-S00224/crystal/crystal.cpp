#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n, m;
int a[500005], sum[500005];
bool check(int k) {
	for (int l = 1; l + k - 1 <= n; l++) {
		int r = l + k - 1;
		int cs = a[r] * k - (sum[r] - sum[l - 1]);
		if (cs <= m) return 1; 
	}
	return 0;
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	int l = 1, r = n, mid, ans;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		}else {
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
} 
