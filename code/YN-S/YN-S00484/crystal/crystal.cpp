#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e8 + 5;
const long long MAXNN = 1e18 + 5;
long long n, m, a[MAXN], flag, x, minn, mins, b[MAXN], c[MAXN];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i <= n - 1; i++) {
		cin >> a[i];
		b[i] += b[i - 1] + a[i];
		if (i > 1) {
			if (abs(a[i] - a[i - 1]) == x) {
				flag = 1;
			} else {
				flag = 0;
			}
		}
		if (i == 1) {
			x = abs(a[i] - a[i - 1]);
		}
	}
	for (int i = 0; i <= n - 1; i++) {
		b[i] += b[i - 1] + a[i];
	}
	for (int i = 0; i <= n - 1; i++) {
		c[i] = b[n - 1] - b[i];
	}
	if (flag == 1) {
		long long i = 0;
		while (m) {
			m -= x;
			x *= 2;
			i++;
			if (m <= 0) {
				m += x;
				i--;
				break;
			}
		}
		cout << i + 1;
	} else {
		sort(a, a + n - 1);
		for (int i = 0; i <= n - 1; i++) {
			long long cnt = 0;
			cnt += b[i] + c[i] - 2 * a[i];
			minn = min(cnt, minn);
			if (cnt < minn) {
				mins = i;
			}
		}
		int cnt = 0;
		for (int i = 0; i <= m - 1; i++) {
			if (a[mins + 1] - a[mins] < a[mins] - a[mins - 1] && m >= a[mins + 1] - a[mins]) {
				cnt++;
				m -= (a[mins + 1] - a[mins]);
			} else if (a[mins + 1] - a[mins] >= a[mins] - a[mins - 1] && m >= a[mins] - a[mins - 1]) {
				cnt++;
				m -= (a[mins] - a[mins - 1]);
			} else {
				break;
			}
		}
		cout << cnt;
	}
	return 0;
}