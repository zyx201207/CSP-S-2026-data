#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	long long a[n + 1];
	for (long long i = 0; i < n; i++) {
		cin >> a[i];
	}
	long long max = 0;
	for (long long i = 0; i < n; i++) {
		for (long long j = i; j < n; j += n) {
			int b = a[i];
			for (long long k = 1; k <= m; k++) {
				b &= a[j + k];
				cout << b << " ";
			}
			if (b >= max) {
				max = b;
			}
			cout << max << endl;
		}
	}
	cout << max;
	return 0;
}

