#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
ll n, ans = 0, a[N], l, r;
char c[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	l = 1, r = n;
	while (l < r) {
		if (c[l] != c[r]) {
			ans += min(a[l], a[r]);
		}
		if (a[l] > a[r]) {
			a[l] -= a[r];
			r--;
		} else {
			a[r] -= a[l];
			l++;
		}
	}
	cout << ans << endl;
	return 0;
}