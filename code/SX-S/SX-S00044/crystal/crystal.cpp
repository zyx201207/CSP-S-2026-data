#include <bits/stdc++.h>
using namespace std;
long long n, m, zs, sum, cz, l1;
int a[500005];
int b[500005];
int c[500005];
int d[500005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(a + 1, a + 1 + n);
	sort(b + 1, b + n + 1);
	if (m == 0) {
		for (int i = 1; i <= n; i++) {
			if (a[i] == a[i - 1]) {
				zs++;
			}
		}
		cout << zs + 1;
		return 0;
	}
	long long minn = 10000009;
	for (int i = 2; i <= n; i++) {
		l1++;
		zs = 0, sum = 0;
		for (int j = 1; j <= n; j++) {
			if (b[j] <= a[i]) {
				sum += a[i] - b[j];
				zs++;
			} else {
				break;
			}
		}
		cz = m - sum;
		c[i - 1] = cz;
		d[i - 1] = zs;
		if (cz < 0) {
			break;
		} else {
			minn = min(minn, cz);
		}
	}
	for (int i = 1; i <= l1; i++) {
		if (c[i] == minn) {
			cout << d[i];
			return 0;
		}
	}
	return 0;
}
