/*
by Zhangshujun 14:50
exp:100pts
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 5e5 + 5;
int a[MAXN], sum[MAXN];
signed main() {
#ifndef DEBUG
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
#else
	ios::sync_with_stdio(0), cin.tie(0);
//	freopen(".\\crystal\\crystal4.in", "r", stdin);
//	freopen(".\\crystal\\crystal1.out", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int l = 0, r = i, len = 0;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if  (a[i] * mid - (sum[i] - sum[i - mid]) <= m)
				len = mid, l = mid + 1;
			else
				r = mid - 1;
		}
		ans = max(len, ans);
	}
	cout << ans << '\n';
	return 0;
}