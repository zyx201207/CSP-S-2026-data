#include <bits/stdc++.h>
using namespace std;
long long n, a[200005], ans;
char x[200005];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >>	x[i];
	}
	int l = 1, r = n;
	while (l < r) {
		if (x[l] == x[r]) {
			if (a[l] > a[r]) {
				a[l] -= a[r];
				r--;
			} else if (a[l] < a[r]) {
				a[r] -= a[l];
				l++;
			} else {
				l++;
				r--;
			}
		} else {
			if (a[l] > a[r]) {
				ans += a[r];
				a[l] -= a[r];
				r--;
			} else if (a[l] < a[r]) {
				ans += a[l];
				a[r] -= a[l];
				l++;
			} else {
				ans += a[r];
				l++;
				r--;
			}
		}
	}
	cout << ans;
	return 0;
}