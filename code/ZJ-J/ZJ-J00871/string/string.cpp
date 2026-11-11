#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, a[201000], c[201000], l, r, lr, rr, ans;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		char ch;
		cin >> a[i] >> ch;
		c[i] = ch - 'a';
	}
	l = 1, lr = a[1], r = n, rr = a[n];
	while (l < r) {
		ll d = min(lr, rr);
		if (c[l] != c[r]) ans += d;
		lr -= d, rr -= d;
		if (lr == 0) l ++, lr = a[l];
		if (rr == 0) r --, rr = a[r];
	}
	cout << ans;
	return 0;
}
