#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	vector<long long>a(n);
	vector<char>c(n);
	for (int i = 0; i < n; i++)
		cin >> a[i] >> c[i];
	long long ans = 0;
	int l = 0, r = n - 1;
	long long x = a[l], y = a[r];
	while (l < r) {
		long long z = min(x, y);
		if (c[l] != c[r])
			ans += z;
		x -= z;
		y -= z;
		if (x == 0) {
			l++;
			if (l <= r)
				x = a[l];
		}
		if (y == 0) {
			r--;
			if (r >= l)
				y = a[r];
		}
	}
	cout << ans << "\n";
	return 0;
}