#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 2;
long long a[MAXN], b[MAXN];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m, sum, ans = 0, c, s = 0, d;
	int A = 0, B = 0;
	cin >> n >> m;
	sum = m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == i)
			A = 1;
		else
			A = 0;
	}
	if (!A) {
		for (int i = 3; i <= n; i++) {
			if (a[i] - a[i - 1] == a[i - 1] - a[i - 2])
				B = 1;
			else
				B = 0;
		}
	}
	sort(a + 1, a + n + 1);
	if (B) {
		d = a[2] - a[1];
		ans = 1;
		if (m % d == 0 ) {
			//cout << "?";
			c = a[n];
			for (int i = 1; i <= n ; i++) {
				a[n - i] += i * d;
				if (sum <= 0)
					break;
				sum -= i * d;
				if (a[n - i] == c) {
					ans++;
				}
			}
		} else {
			//cout << '!!!';
			long long ch = m / d;
			for (int i = 1; i <= ch; i++) {
				ch -= i;
				if (ch < 0) {
					break;
				}

				ans++;
			}
		}
	} else {


		if (/*A && */(n >= m)) {
			ans = 1;
			c = a[m];
			for (int i = m - 1; i >= 1; i--) {
				while (a[i] != c && sum > 0) {
					a[i] += 1;
					sum--;
				}
				if (a[i] == c)
					ans++;
				if (sum <= 0)
					break;
			}
		} else if (/*A &&*/ (n < m)) {
			s = (a[1] + a[n - 1]) * (n - 1) / 2;
			if (m > s && (m % s == 0))
				ans = n;
			else if (m > s && (m % s != 0)) {
				ans = n - 1;
			}

			else {
				c = a[n];
				ans = 1;
				for (int i = n - 1; i >= 1; i--) {
					while (a[i] != c && sum > 0) {
						a[i] += 1;
						sum--;
					}
					if (a[i] == c)
						ans++;
					if (sum <= 0)
						break;
				}
			}
		}

	}
	cout << ans;

	return 0;
}