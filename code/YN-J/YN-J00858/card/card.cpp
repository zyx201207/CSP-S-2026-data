#include <bits/stdc++.h>
using namespace std;
long long n, m;
const int N = 5e5 + 10;
long long a[N], b[N], c[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (long long i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	for (long long i = 1; i <= n; i++) {
		for (long long j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (b[k] == a[j + i - 1] ) {
					for (int l = k; l < j; l++) {
						b[l] = 0;
					}
					break;
				}
			}
			b[j] = a[j + i - 1];
		}
		for (int j = 1; j <= n; j++) {
			if (b[j] != 0) {
				c[b[j]]++;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (c[i] > 0) {
			printf("%lld ", c[i]);
		}
	}
	return 0;
}