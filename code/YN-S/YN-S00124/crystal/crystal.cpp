#include <bits/stdc++.h>
using namespace std;
long long a[999999];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
// / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /
	long long n, m, c = 0;
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (long long i = 1; i <= n; i++) {
		cout << abs(a[i] + a[i + 1]);
		break;
		if (i >= n / 2 - 2 && i < n / 2) {
			if (a[i] < a[n / 2] && m != 0) {
				a[i]++;
				m--;
				c++;
			}
		}
	}
	return 0;
}