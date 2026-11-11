#include <bits/stdc++.h>
using namespace std;
long long a[1000005];

int main() {
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	long long n;
	long long m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	long long sum = a[n - 1];
	m--;
	for (int i = n - 2; i >= 0; i--) {
		if (m == 0) {
			break;
		}
		sum = sum & a[i];

		m--;
	}

	cout << sum;
	return 0;
}