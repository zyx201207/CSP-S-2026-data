#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6;
ll n, a[N];
char c[N];

int main() {
	cin.tie(0)->ios::sync_with_stdio(0);
	// be sure to delete any "//" on this line!!!!!!!!
	// be sure to change the file name
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> c[i];
	char u, v;
	ll x = a[1], y = a[n], ans = 0;
	for (int l = 1, r = n; l < r;) {
		u = c[l];
		v = c[r];
		if (x < y) {
			l++;
			if (u != v)
				ans += x;
			y -= x;
			x = a[l];

		} else if (x > y) {
			r--;
			if (u != v)
				ans += y;
			x -= y;
			y = a[r];
		} else {
			l++;
			r--;
			if (u != v)
				ans += x;
			x = a[l];
			y = a[r];
		}
	}
	cout << ans << "\n";
	return 0;
}