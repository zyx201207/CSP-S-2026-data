#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[500010];
long long b[500010];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];

	}
	sort(a + 1, a + n + 1);
	long long maxx = 0;
	for (long long i = 1; i <= n; i++) {
		b[i] = a[i] + b[i - 1];
//		cout << "     " << b[i] << endl;
		long long l = 1, r = n, re = n;
		while (l <= r) {
			long long mid = ((l + r) >> 1);
			if ((i - mid + 1) * a[i] - (b[i] - b[mid - 1]) <= m) {
				r = mid - 1;
				re = mid;
			} else {
				l = mid + 1;
			}
		}
		maxx = max(maxx, i - re + 1);
	}
	cout << maxx;
	return 0;
}