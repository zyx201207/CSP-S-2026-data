#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long a[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	srand(time(0));
	long long n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n >= 20000) {
		long long l = a[2] - a[1];
		bool fl = 1;
		for (int i = 1; i <= 1000; i++) {
			int k = rand() % n + 2;
			if (l != a[k] - a[k - 1]) {
				fl = 0;
				break;
			}
		}
		if (fl == 1) {
			long long i;
			for (i = 1; i <= n; i++) {
				long long tot = (1 + i) * i / 2 * l;
				if (m < tot) {
					break;
				}
			}
			i--;
			cout << i;
			return 0;
		}
	}
	sort(a + 1, a + n + 1);
	long long  res = 1;
	for (int i = 1; i <= n; i++) {
		long long t = m;
		long long tot = 1;
		long long j = i;
		for (j = i; j <= n && t >= (a[j] - a[j - 1]) * (j - i + 1); j++) {
			t -= (a[j] - a[j - 1]) * (j - i + 1);
			tot++;
		}
		res = max(res, min(tot, n));
	}
	cout << res;
	return 0;
}
