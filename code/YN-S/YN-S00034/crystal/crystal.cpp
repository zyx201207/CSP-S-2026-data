#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[500005];
long long sum;
long long m1;
long long maxn = 0;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	m1 = m;

	for (long long i = 1; i <= n; i++) {

		cin >> a[i];
	}

	sort(a + 1, a + n + 1);

	for (long long i = 2; i <= n; i++) {

		long long sum = 0;

		for (long long j = 1; j <= i - 1; j++) {

			sum += a[i] - a[j];
		}

		if (m1 >= sum) {
			for (long long j = 1; j <= i - 1; j++) {

				a[j] = a[i];
			}

			maxn = max(maxn, i);
			m1 -= sum;
		} else {
			break;
		}
	}

	cout << maxn << endl;
	return 0;
}