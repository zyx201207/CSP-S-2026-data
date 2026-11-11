#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, l, r, ans;
char c[200005];
int a[200005];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	l = 1, r = n;
	while (l < r) {
		int cnt1 = a[l], cnt2 = a[r];
		if (c[l] != c[r]) {
			int mi = min(a[l], a[r]);
			ans += mi;
			a[l] -= mi;
			a[r] -= mi;
			if (a[l] == 0)
				l++;
			if (a[r] == 0)
				r--;
		} else {
			int mi = min(a[l], a[r]);
			a[l] -= mi, a[r] -= mi;
			if (a[l] == 0)
				l++;
			if (a[r] == 0)
				r--;
		}
	}
	cout << ans;
	return 0;
}