#include <bits/stdc++.h>
#define int long long
using  namespace std;
const int N = 5e5 + 10;
int n, m;
int a[N];
int diff[N];
int ans = LLONG_MIN;
int max1 = LLONG_MIN;
int t[N];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		max1 = min(a[i], max1);
	}
	for (int j = max1; j <= max1 + m; j++) {
		int max2 = LLONG_MIN;
		for (int i = 1; i <= n; i++) {
			diff[i] = (a[i] >= j ? 0 : j - a[i]);
		}
		for (int i = 1; i <= n; i++) {
			t[diff[i]]++;
		}
		for (int i = 1; i <= n; i++) {
			max2 = max(t[i], max2);
		}
		ans = max(max2, ans);
	}
	cout << ans;

	return 0;
}