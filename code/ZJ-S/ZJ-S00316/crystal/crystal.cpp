#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
unsigned long long d[500005];
signed main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m, ans = 1, l = 1;
	unsigned long long su = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) d[i] = a[i] - a[i - 1];
	for (int i = 1; i <= n; i++) {
		su += d[i] * (i - l);
		while (su > m) {
			su -= a[i] - a[l++];
		}
		ans = max(ans, i - l + 1);
	}
	cout << ans;
	return 0;
}