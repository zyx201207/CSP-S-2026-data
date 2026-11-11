#include <bits/stdc++.h>
using namespace std;
int a[500005], b[300005], mm[300005], c[300005];
int main() {

	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	for (long long i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (long long i = 0; i < n; i++) {
		for (long long j = i; j < n; j++) {
			if ((b[a[j]] + 1) % 2 != 0) {
				b[a[j]]++;
				c[a[j]] = j;
			} else {
				for (long long k = c[a[j]]; k < j; k++) {
					b[a[k]] = 0;
				}
				b[a[j]]++;
			}
		}
		for (long long j = 1; j <= m; j++) {
			mm[j] += b[j];
		}
		for (long long k = 1; k <= m; k++) {
			b[k] = 0;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << mm[i] << " ";
	}

	return 0;
}
