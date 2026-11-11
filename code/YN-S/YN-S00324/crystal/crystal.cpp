#include <bits/stdc++.h>
using namespace std;
long long n, m, z = 1;
long long a[100005];
long long sum[100005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;

	for (long long i = 1; i <= n; i++) {

		cin >> a[i];
	}

	sort(a + 1, a + 1 + n);
	sum[1] = a[1];

	for (long long i = 2; i <= n; i++) {

		sum[i] = sum[i - 1] + a[i];

		if (a[i]*i - sum[i] <= m) {
			z = i;
		} else {
			break;
		}
	}

	cout << z;
	return 0;
}
