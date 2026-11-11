#include <bits/stdc++.h>
using namespace std;
long long c, t, rt[5010], ct[5010];
long long x[5010];

void solve() {
	long long n, d;
	cin >> n >> d;
	for (long long i = 1; i <= n; i++) {
		cin >> x[i];
	}
	long long ans = 0;
	for (long long i = 1; i <= n; i++) {
		long long k = i;
		ct[i] = 1;
		for (long long j = i + 1; j <= n; j++) {
			while (k < j && x[j] - x[k] > d)
				k++;
			if (k == j) {
				break;
			}
			int e = k + 1, C = ct[k];
			while (rt[e] == rt[k] && e < j) {
				C += ct[e];
				e++;
			}
			if (C == 2)
				ans++;
			rt[j] = rt[k] + 1;
			ct[j] = C;
		}
	}
	cout << ans << endl;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	if (c <= 10) {
		while (t--)
			solve();
	}
//	if (c == 13 || c == 14) {
//		long long n, d, x, y, z;
//		cin >> n >> d >> x >> y;
//		for (int i = 3; i <= n; i++)
//			cin >> z;
//		x = y - x;
//		cout << n - ((d - 2 * x) / x * 2 + 4) - 1 << endl;
//	}
	return 0;
}