#include <bits/stdc++.h>
using namespace std;
long long n, m;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	long long a[n + 5], b[n + 5];
	a[0] = 0;
	b[0] = 0;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	while (m > 0) {
		for (long long i = 1; i <= n; i++) {
			b[i] = b[i - 1] + a[i];
			while (b[i] != i * a[i + 1] && m > 0) {
				b[i] += i;
				m -= i;
			}

			if (m == 0) {
				while (a[i + 1] == a[i + 2])
					i++;
				cout << i + 1;
				break;
			}
			if (m < 0) {
				while (a[i] == a[i + 1])
					i++;
				cout << i;
				break;
			}

		}

	}
	return 0;
}