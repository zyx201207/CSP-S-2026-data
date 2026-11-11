#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500050], s[500050];
bool check(int x) {
	
	for (int i = 1; i + x - 1 <= n; ++ i) {
		int al = s[i + x - 1] - s[i - 1];
		int mx = a[i + x - 1] * x;
		int tt = mx - al;
		if (tt <= m) {
			return true;
		}
	}
	return false;
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) {
		cin >> a[i];
	}
	sort (a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++ i) {
		s[i] =  s[i - 1] + a[i];
	}
	int l = 1, r = n;
	while (l + 1 < r) {
		int mid = (l + r) / 2;
		if (check(mid) == true) l = mid;
		else r = mid;
	}
	if (check(r) == true) cout << r;
	else cout << l;
	
	return 0;
}