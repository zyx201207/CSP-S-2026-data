#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5, MN = INT_MIN, MX = INT_MAX;
int n, m, l = MX, r = MN, ans, a[N];
int p(int x) {
	int s = 0, s1 = 0, id = upper_bound(a, a + n, x) - a - 1;
	for (int i = id ; i >= 0 ; i--) {
		s += x - a[i];
		if (s > m) 
			break;
		s1++;
	}
	return s1;
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "l", stdout);
	cin >> n >> m;
	for (int i = 0 ; i < n ; i++) {
		cin >> a[i];
		l = min(a[i], l);
		r = max(a[i], r);
	}
	sort(a, a + n);
	for (int i = l ; i <= r ; i++)
		ans = max(ans, p(i));
	cout << ans;
	return 0;
}
