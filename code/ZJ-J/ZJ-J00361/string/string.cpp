#include <bits/stdc++.h>
using namespace std;
struct node {
	long long x;
	char c;
}a[200010];
int main () {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n;
	cin >> n;
	for (long long i = 1; i <= n; i++) cin >> a[i].x >> a[i].c;
	long long l = 1, r = n, ans = 0;
	while (l != r) {
		if (a[l].x < a[r].x) {
			if (a[l].c != a[r].c) ans += a[l].x;
			a[r].x -= a[l].x, a[l].x = 0;
			l++;
		} else {
			if (a[l].c != a[r].c) ans += a[r].x;
			a[l].x -= a[r].x, a[r].x = 0;
			r--;
		}
	}
	cout << ans;
	return 0;
}