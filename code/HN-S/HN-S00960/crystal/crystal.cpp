#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n, m, a[N], sum[N], ans = 1;
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;	
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++) {
		sum[i] = sum[i - 1] + a[i];
		int l = 1, r = i;
		while (l <= r) {
			int mid = l + r >> 1;
			if (mid * a[i] - (sum[i] - sum[i - mid]) <= m) l = mid + 1;
			else r = mid - 1;
		}
		ans = max(ans, l - 1);
	}
	cout << ans;
	return 0;
}
