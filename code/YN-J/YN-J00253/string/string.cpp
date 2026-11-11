//2026.10.31  zyb  string
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int n, a[N], ans;
char c[N];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	int l = 1, lc = a[1], r = n, rc = a[n];
	while (l < r) {
		ans += min(lc, rc) * (c[l] != c[r]);
		if (lc == rc) {
			l++, lc = a[l];
			r--, rc = a[r];
		} else if (rc > lc) {
			rc -= lc;
			l++, lc = a[l];
		} else if (lc > rc) {
			lc -= rc;
			r--, rc = a[r];
		}
	}
	cout << ans << '\n';
	return 0;
}