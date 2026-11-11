#include <bits/stdc++.h>

using namespace std;

#define int long long
const int maxn = 5e5 + 5;

int a[maxn], s[maxn];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + 1 + n);
	int ans = 1, l = 1;
	for (int i = 1; i <= n; ++i) {
		s[i] = s[i - 1] + a[i];
		while (a[i] * (i - l + 1) - (s[i] - s[l - 1]) > m) l++;
//		cout << l << endl; 
		ans = max(ans, i - l + 1);
	}
	cout << ans;
	return 0; 
} 