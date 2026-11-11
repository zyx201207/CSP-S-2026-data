#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, a[200005], l, r, len, ans;
char c[200005];
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	l = 1, r = n;
	while (l < r) {
		len = min(a[l], a[r]);
		if (c[l] != c[r]) ans += len;
		a[l] -= len;
		a[r] -= len;
		if (a[l] == 0) l++;
		if (a[r] == 0) r--;
	}
	cout << ans;
	return 0;
}