#include <bits/stdc++.h>
using namespace std;
using uns = unsigned;

uns a[200005], m, l, r, ans;

void can_do(uns w) {
	uns vl = 1u << w;
	uns t = upper_bound(a + l, a + r + 1, vl--, greater<>()) - a - 1;
	for (uns i = l; i <= r; ++i) a[i] &= vl;
	if (t - l + 1 >= m) {
		r = t;
		ans |= vl + 1;
	} else {
		sort(a + l, a + r + 1, greater<>());
	}
	return;
} 


uns btw(uns x) {
	uns cnt = 0;
	while (x) ++cnt, x >>= 1;
	return cnt;
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> r >> m; --r;
	for (uns i = 0; i <= r; ++i) cin >> a[i];
	sort(a, a + r + 1, greater<>());
	for (uns i = btw(a[0]); ~i; --i) can_do(i);
	cout << ans;
	return 0;
}
