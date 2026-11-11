#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[500005];
long long ans = 1;
bool f1 = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	long long d;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i == 2)
			d = a[i] - a[i - 1];
		if (i > 2 && a[i] - a[i - 1] != d)
			f1 = 1;
	}
	sort(a + 1, a + n + 1);
	if (!f1) {
		for (int i = 1; i <= n; i++) {
			if (1ll * i * (i - 1)*d > 1ll * 2 * m) {
				cout << i - 1;
				return 0;
			}
		}
	}
	long long b = 1;
	for (int i = 1; i <= n; i++) {
		while (a[i + 1] == a[i] && i != n)
			b++, i++;
		ans = max(ans, b);
		b = 1;
	}
	long long cnt = m, sum = 1;
	for (int i = 1; i <= n; i++) {
		if (i == n) {
			ans = cnt - m;
			break;
		}
		if (m <= 0)
			break;
		while (a[i + 1] == a[i] && i != n)
			sum++, i++;
		long long ne = sum * (a[i + 1] - a[i]);
		if (m < ne) {
			if (i != n) {
				int j = i + 1;
				long long su = 1;
				while (a[j + 1] == a[j] && j != n)
					su++, j++;
				ans = max(max(ans, sum), su + m / (a[i + 1] - a[i]));
				break;
			} else
				ans = n;
		} else {
			m -= ne;
			if (i != n) {
				int j = i + 1;
				long long su = 1;
				while (a[j + 1] == a[j] && j != n)
					su++, j++, i++;
				ans = su + sum;
				sum = ans;
			} else
				ans = n;
		}
	}
	cout << ans;
	return 0;
}