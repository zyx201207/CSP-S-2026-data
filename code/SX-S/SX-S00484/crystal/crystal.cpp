#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
long long a[N], b[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m, ans = 0, p, q = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	p = a[2] - a[1];
	b[n] = 0;
	long long summ = 0;
	for (int i = 1; i <= n; i++) {
		b[i - 1] = a[i] - a[i - 1];
		summ += (a[i] - a[1]);
		if (i > 1 && b[i - 1] != p)
			q = 1;
	}
	if (summ <= m) {
		cout << n;
		return 0;
	}
	if (q == 0) {
		long long l = 1, r = n - 1, mid = n  / 2;
		while (l <=  r) {

			if ((mid * mid) + mid <= 2 * m / p)
				l = mid + 1;
			else
				r = mid - 1 ;
			mid = (l + r) / 2;
		}
		cout << r + 1;
		return 0;
	}
	for (int i = 1; i < n - 1; i++) {
		long long  t = 0, j = i, sum = 1;
		while (t <= m) {
			if (t > m)
				break;
			t += (j - i + 1) * b[j];
			if (t <= m)
				sum++;
			if (j == n - 1 && t <= m) {
				ans = max(ans, sum);
				break;
			}
			j++;
		}
		ans = max(ans, sum);
	}
	cout << ans;
	return 0;
}