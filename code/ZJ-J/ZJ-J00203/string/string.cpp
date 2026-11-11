#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int n, a[N], l = 1, r, ans, lp, rp;
char c[N];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
//	freopen("string.in", "r", stdin);
//	freopen("string.out", "w", stdout);
	cin >> n; r = n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		a[i] += a[i - 1];
	} rp = a[n];
	while (l < r) {
		int ll = a[l] - lp, rl = rp - a[r - 1];
		if (c[l] != c[r]) ans += min(ll, rl);
		if (ll == rl) l++, r--, lp = a[l - 1], rp = a[r];
		else if (ll < rl) l++, lp = a[l - 1], rp -= ll;
		else r--, lp += rl, rp = a[r];
	}
	cout << ans;
	return 0;
}