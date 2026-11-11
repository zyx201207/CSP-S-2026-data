#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
long long n, m, ans, w, t, cz;
long long a[N], b[N], c[N];
bool flag1;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 1) {
		cout << "1";
		return 0;
	}
	long long k = a[2] - a[1];
	for (int i = 3; i <= n; i++) {
		if (a[i] - a[i - 1] != k) {
			flag1 = 1;
		}
	}
	if (flag1 == 0) {
		long long l = 1;
		for (int i = 1; i < n; i++) {
			m -= i * k;
			if (m == 0) {
				l++;
				break;
			}
			if (m < 0) {
				break;
			}
			l++;
		}
		cout << l;
		return 0;
	}
	sort(a + 1, a + 1 + n);
	for (int i = 2; i <= n; i++) {
		b[i] = b[i - 1] + (a[i] - a[i - 1]);
	}
	for (int i = 2; i <= n; i++) {
		c[i] = a[i] - a[i - 1];
	}
	ans = 1;
	w = 1, t = 2;
	long long op = 1;
	for (int i = 2; i <= n; i++) {
		cz += c[i] * (t - w);
		if (cz <= m) {
			op++;
			t++;
		} else {
			while (cz > m) {
				cz -= (b[t] - b[w]);
				w++;
			}
			op = (t - w) + 1;
			t++;
		}
		ans = max(ans, op);
	}
	cout << ans;
	return 0;
}