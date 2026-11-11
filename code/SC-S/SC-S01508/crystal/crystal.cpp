#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+5;
int n, m, a[N], l, r, ans, tmp, s[N];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++)s[i] = s[i - 1] + a[i];
	l = r = 1;
	while (r <= n) {
		if (tmp <= m) {
			ans = max(ans, r - l + 1);
			r++;
			tmp = a[r] * (r - l + 1) - (s[r] - s[l - 1]);
		} else {
			tmp -= (a[r] - a[l]);
			l++;
		}
	}
	cout << ans;
	return 0;
}