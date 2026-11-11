#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	vector<int> a(n);
	vector<char> c(n);
	for (int i = 0; i < n; i++)
		cin >> a[i] >> c[i];
	ll ans = 0;
	int sum = 0;
	for (int i = 0; i < n / 2 + sum; i++) {
		int l = i;
		int r = n - l - 1;
		if (c[l] != c[r]) {
			if (a[l] > a[r]) {
				a.insert(a.begin() + l, a[l] - a[r]);
				c.insert(c.begin() + l, c[l]);
				ans += a[r];
				sum++;
			} else if (a[r] > a[l]) {
				a.insert(a.begin() + r, a[r] - a[l]);
				c.insert(c.begin() + r, c[r]);
				ans += a[l];
				sum++;
			} else
				ans += a[l];
		}
	}
	cout << ans;
	return 0;
}