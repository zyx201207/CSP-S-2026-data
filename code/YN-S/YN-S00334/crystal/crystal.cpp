#include <bits/stdc++.h>
using namespace std;

long long const MAXN = 1E6 + 2;
long long a[MAXN];
long long b[MAXN];
long long e[MAXN];
long long f[MAXN];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m,  sum = 0, c = 0, d = 0 ;
	cin >> n >> m;
	for (long long  i = 1; i <= n; i++ ) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int same1 = 0, same2 = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i + 1] - a[i] == 0) {
			same1++;
			c = a[i];
		}
		if (a[i + 1] - a[i] >= 1 && a[i + 2] - a[i + 1] == 0) {
			same2++;
			if (same2 > same1) {
				same1 = 0;
				same1 += same2;
				same2 = 0;
				c = a[i + 1];
			}
		}
		for (int i = 1; i <= c; i++) {
			e[i] += a[i];
			d++;
		}
		sort(e + 1, e + n + 1);
		for (int i = d; i >= 1; i--) {
			f[i] += e[i];

		}

	}
	int ans1 = 0, ans2 = 0;
	sort(f + 1, f + n + 1);
	for (int j = 1; j <= d; j++) {
		if (same1 > 1 && m - c + f[j] > 0) {
			ans1 += 1;
			m = m - c + f[j];
			cout << same1 + ans1 - 1 ;

		}

	}

	return 0;


}






