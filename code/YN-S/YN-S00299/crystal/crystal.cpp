#include <bits/stdc++.h>
using namespace std;
long long a[500005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	long long ans = 0, sum = 0;
	sort(a + 1, a + 1 + n);
	for (long long i = 1, j = 2; j <= n; j++) {
		sum += (a[j] - a[j - 1]) * (j - i);
		while (sum > m) {
			sum -= a[j] - a[i];
			i++;
		}
		ans = max(ans, j - i + 1);
	}
	cout << ans;

	return 0;
}