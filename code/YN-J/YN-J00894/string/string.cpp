#include <bits/stdc++.h>
using namespace std;
string s;
char c[200005];
long long ans, sum;
long long n, mx = -1, a[200005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		sum = sum + a[i];
		mx = max(mx, a[i]);
	}
	long long l = 1, r = n;
	while (l <= r) {
		if (a[l] == a[r]) {
			ans += (c[l] != c[r]) * a[l];
			l++, r--;
		} else if (a[l] > a[r]) {
			ans += (c[l] != c[r]) * a[r];
			a[l] -= a[r];
			r--;
		} else if (a[r] > a[l]) {
			ans += (c[l] != c[r]) * a[l];
			a[r] -= a[l];
			l++;
		}
	}
	cout << ans;
	return 0;
}