#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 2e5 + 10;

ll n, l, r, ans = 0;
ll a[N];
char c[N];

signed main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> c[i];
	l = 1, r = n;
	while (l < r) {
		if (a[l] == a[r]) {
			if (c[l] != c[r])
				ans += a[l];
			l++, r--;
		}
		else if (a[l] < a[r]) {
			if (c[l] != c[r])
				ans += a[l];
			a[r] -= a[l];
			l++;
		}
		else {
			if (c[l] != c[r])
				ans += a[r];
			a[l] -= a[r];
			r--;
		}
	}
	cout << ans;
	return 0;
}