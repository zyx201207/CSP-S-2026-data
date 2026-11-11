#include <bits/stdc++.h>
using namespace std;
long long a[1000005];
long long b[1000005];
long long n, m;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int boo = 1;
	int x = a[2] - a[1];
	for (int i = 2; i <= n; i++) {
		if (a[i] - a[i - 1] != x) {
			boo = 0;
		}
	}
	if (boo == 1) {
		b[1] = 1;
		for (long long i = 2; i <= 100000; i++) {
			b[i] = b[i - 1] + i;
		}
		m = m / x;
		for (long long i = 1; i <= 100000; i++) {
			if (m >= b[i] && m < b[i + 1]) {
				cout << min(i + 1, n);
				return 0;
			}
		}
		return 0;
	}
	sort(a + 1, a + 1 + n);
	long long maxn = 0;
	for (long long i = 1; i <= n; i++) {
		long long sum = 0;
		for (long long j = i + 1; j <= n; j++) {
			if (sum + (a[j] - a[j - 1]) * (j - i) <= m) {
				sum += (a[j] - a[j - 1]) * (j - i);
			} else {
				maxn = max(j - i, maxn);
				break;
			}

		}
	}
	cout << maxn;
	return 0;
}
