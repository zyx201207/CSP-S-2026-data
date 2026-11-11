#include <bits/stdc++.h>
using namespace std;

int n;
long long a[200010];
char c[200010];
string s;

int main () {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	long long ans = 0;
	for (int l = 1, r = n; l < r;) {
		if (c[l] != c[r]) {
			ans += min(a[l], a[r]);
		}
		if (a[l] < a[r]) {
			a[r] -= a[l];
			l++;
		} else if (a[l] > a[r]) {
			a[l] -= a[r];
			r--;
		} else {
			l++, r--;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
