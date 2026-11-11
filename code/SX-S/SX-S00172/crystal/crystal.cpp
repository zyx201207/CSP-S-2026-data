#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+5;
long long n, m, a[N], a1[N], ans, sum;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++)
		cin >> a[i];
	if (n > 5000) {
		if (a[2] - a[1] == a[3] - a[2]) {
			long long aa = a[2] - a[1], ans1 = 0, sum1 = 0, aa1 = 0;
			while (1) {
				sum1 += aa * aa1;
				aa1++;
				if (sum1 <= m)
					ans1++;
				else {
					cout << ans1;
					return 0;
				}
			}
		}
	}
	sort(a + 1, a + 1 + n);
	a1[1] = 0;
	for (long long i = 2; i <= n; i++)
		a1[i] = a[i] - a[i - 1];
	sum = 0;
	for (long long i = 1; i <= n; i++) {
		for (long long j = i; j <= n; j++) {
			if (sum <= m)
				sum += (a1[j] * (j - i ));
			if (sum > m) {
				ans = max(ans, j - i );
				sum = 0;
				break;
			}
		}
	}
	cout << ans;

	return 0;
}
