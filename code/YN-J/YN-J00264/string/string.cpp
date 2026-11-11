#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int t, ans, sum, st;
string s;
int a[N];
char c[N];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> a[i] >> c[i];
		sum += a[i];
	}
	st = (sum + 1) / 2;
	int l = 1, r = t, now = 0, tmp = 0, f = 0;
	for (; now < st && l <= r;) {
//		cout << l << " " << r << " " << a[l] << " " << a[r] << " " << now << " " << ans << "\n";
		if (c[l] != c[r])
			f = 1;
		if (now + min(a[l], a[r]) > st) {
			if (a[l] < a[r])
				a[l] = st - now;
			if (a[l] > a[r])
				a[r] = st - now;
			if (a[l] == a[r])
				a[l] = a[r] = st - now;
		}
		if (a[l] < a[r]) {
			tmp += a[l];
			a[r] -= a[l];
			l++;
		} else if (a[l] > a[r]) {
			tmp += a[r];
			a[l] -= a[r];
			r--;
		} else if (a[l] == a[r]) {
			tmp += a[l];
			l++, r--;
		}
		now += tmp;
		if (f)
			ans += tmp;
		tmp = 0, f = 0;
//		cout << l << " " << r << " " << a[l] << " " << a[r] << " " << now << " " << ans << "\n";
	}
	cout << ans;
	return 0;
}
//ToonoHanna