#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 12;
int a[N], sum[N];
int n, m;
bool check(int mid) {
	for (int i = n; i >= mid; --i) {
		if(a[i] * (mid - 1) - (sum[i - 1] - sum[i - mid]) <= m) {
			return true;
		}
	}
	return false;
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
	cin >> n >> m;
	sum[0] = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i) {
		sum[i] = sum[i - 1] + a[i];
	}
	int l = 1, r = n, ans, mid;
	while(l <= r) {
		mid = (l + r) / 2;
		if(check(mid)) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << ans << endl;
	return 0;
}
