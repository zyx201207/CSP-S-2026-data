#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	long long a[n];
	for (long long i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	int ans = 0;
	for (long long i = 1; i < n; i++) {
		long long h = m;
		long long e = 1;
		for (long long j = i - 1; j >= 0; j--) {
			if (a[j] == a[i]) {
				e++;
				continue;
			}
			if (a[i] - a[j] == h) {
				e++;
				break;
			}
			if (a[i] - a[j] > h)
				break;
			if (a[i] - a[j] < h) {
				e++;
				h = h - (a[i] - a[j]);
			}
		}
		if (e > ans)
			ans = e;
	}
	cout << ans;
	return 0;
}