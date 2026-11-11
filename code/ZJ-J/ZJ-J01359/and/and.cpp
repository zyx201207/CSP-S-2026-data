#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m; cin >> n >> m;
	vector<int> b(31, 0);
	vector<pair<int, int> > a(n+1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].second;
		for (int j = 30; j >= 0; --j) {
			if (a[i].second >> j & 1) ++b[j];
		}
	}
	for (int i = 30; i >= 0; --i) {
		if (b[i] < m) continue;
		for (int j = 1; j <= n; ++j) {
			if (a[j].second >> i & 1) a[j].first |= 1<<i;
		}
	}
	sort(a.begin() + 1, a.end(), greater<pair<int, int> >());
	int ans = (1<<30)-1;
	for (int i = 1; i <= m; ++i) {
		ans &= a[i].second;
	}
	cout << ans << endl;
	return 0;
}
