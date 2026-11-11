#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n; cin >> n;
	vector<int> a(n+1, 0);
	vector<int> s(n+1, 0);
	vector<char> c(n+1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> c[i];
		s[i] = s[i-1] + a[i];
	}
	int ans = 0;
	int l = s[n] + 1 >> 1;
	int r = s[n] + 2 >> 1;
	int lt = lower_bound(s.begin(), s.end(), l) - s.begin();
	int rt = lower_bound(s.begin(), s.end(), r) - s.begin();
	while (lt >= 1 && rt <= n) {
		int dl = l - s[lt-1];
		int dr = s[rt] - r + 1;
		if (dl < dr) {
			ans += dl * (c[lt] != c[rt]);
			l -= dl;
			r += dl;
			--lt;
		}
		else {
			ans += dr * (c[lt] != c[rt]);
			r += dr;
			l -= dr;
			++rt;
		}
	}
	cout << ans << endl;
	return 0;
}
