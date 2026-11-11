#include <bits/stdc++.h>
using namespace std;
const long long N = 500005;
long long n, m, ans = 1;
long long a[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	long long q = 1;
	for (long long i = n - 1; i >= 1; i--) {
		if (m >= (a[i + q] - a[i])) {
			m -= (a[i + q] - a[i]);
			q++;
		} else if (q > 1) {
			while (q > 1) {
				long long sum;
				sum = (q - 1) * (a[i + q] - a[i + q - 1]);
				m += sum;
				q--;
				if (m >= (a[i + q] - a[i])) {
					m -= (a[i + q] - a[i]);
					q++;
					break;
				}
			}
		}
		ans = max(ans, q);
	}
	cout << ans;
	return 0;
}
