#include <bits/stdc++.h>
using namespace std;
long long n, m, a[5000005], c, q[5000005], qq[5000005], anss, yh, ans, f;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != i)
			f = 1;
	}
	if (f == 0) {
		cout << m + 1;
		return 0;
	}
	sort(a + 1, a + 1 + n);
	for (int i = n; i >= 2; i--) {
		c = a[i] - a[i - 1];
		q[i - 1] = q[i] + c;
		qq[i - 1] = qq[i] + q[i - 1];
	}
	anss = 1;
	for (int i = n; i >= 2; i--) {
		long long l = 1, r = i, mid;
		ans = i;
		while (l <= r) {
			mid = (l + r) / 2;
			if (qq[mid] <= m) {
				r = mid - 1;
				ans = mid;
			} else
				l = mid + 1;
		}
		for (int j = 1; j <= i; j++)
			qq[j] -= (i - j) * (a[i] - a[i - 1]);
		anss = max(anss, (i - ans + 1));
	}
	cout << anss;
	return 0;
}
//5 8
//-3 -1 2 2 7
//5 8
//2 -3 -1 2 2 7
//    2 3 0 5
//    10 8 5 5
//      28  18  10 5



//5 5
//1 2 4 8 9
