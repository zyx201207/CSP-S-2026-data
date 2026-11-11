#include <bits/stdc++.h>
using namespace std;

const long long N = 2e5 + 10;
long long n, a[N], l, r, ans;
char c[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> c[i];
	l = 1;
	r = n;
	while (l < r) {
		if (c[l] != c[r]) {
			if (a[l] > a[r]) {
				ans += a[r];
				a[l] -= a[r];
				r--;
			}	
			else {
				if (a[r] > a[l]) {
					ans += a[l];
					a[r] -= a[l];
					l++;
				}
				else {
					ans += a[l];
					l++;
					r--;
				}
			}
		}
		else {
			if (a[l] != a[r]) {
				if (a[l] > a[r]) {
					a[l] -= a[r];
					r--;
				}
				else {
					a[r] -= a[l];
					l++;
				}
			}
			else {
				l++;
				r--;
			}
		}
	}
	cout << ans;
	return 0;
}
