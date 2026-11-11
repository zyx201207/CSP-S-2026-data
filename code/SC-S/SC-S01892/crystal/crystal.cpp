#include<bits/stdc++.h>
#define file "crystal"
#define int long long
using namespace std;
int n, m, a[1000000 + 5], s[1000000 + 5];
int32_t main() {
	freopen(file ".in", "r", stdin);
	freopen(file ".out", "w", stdout);
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i)
		s[i] = s[i - 1] + a[i];
	int ans = 1;
	for (int i = 1; i <= n; ++i) {
//		for (int j = 1; j <= n; ++j)
//			cerr << s[j] << ' ';
//		cerr << endl;
//		for (int j = 1; j <= i; ++j)
//			cerr << "calc " << i << ' ' << j << " is " << a[i] * (i - j + 1) - (s[i] - s[j - 1]) << endl;
		int l = 1, r = i, mid;
		while (l < r - 1) {
			mid = (l + r) >> 1;
			if (a[i] * (i - mid + 1) - (s[i] - s[mid - 1]) > m)
				l = mid;
			else r = mid;
		}
		int p = 0;
		for (int j = max<int>(l - 10, 1); j <= min<int>(l + 10, n); ++j)
			if (a[i] * (i - j + 1) - (s[i] - s[j - 1]) <= m) {
				p = j; break;
			}
		ans = max(ans, i - p + 1);
//		cerr << i << ' ' << p << endl;
	}
	cout << ans << endl;
    return 0;
}