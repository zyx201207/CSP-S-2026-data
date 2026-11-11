#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
int a[500005], c[500005], q[500005], f, l = 1, qq[500005];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++) {
		c[i] = a[i] - a[i - 1];
	}
	for (int i = 2; i <= n; i++) {
		q[i] = q[i - 1] + c[i] * (i - 1);
		qq[i] = qq[i - 1] + c[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = l; j <= n - i + 1; j++) {
			//cout << i << ' ' << j << ' ' << q[i + j - 1] - q[j] - (qq[i + j - 1] - qq[j]) * (j - 1 ) << "         ";
			if (q[i + j - 1] - q[j] - (qq[i + j - 1] - qq[j]) * (j - 1) <= m) {
				f = 1;
				break;
			}
			l++;
		}
		//cout << '\n';
		if (f == 0) {
			cout << i - 1;
			return 0;
		}
		f = 0;
	}
	cout << n;
	return 0;
}
/*
4 2
1 4 7 8
*/
