#include <bits/stdc++.h>
using namespace std;

long long n, m, x;
long long a[500005], b[500005], c[300005], ans[300005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (long long i = 1; i <= n; i++) {
		for (long long y = i; y <= n; y++) {
			b[y] = a[y];
			c[a[y]]++;
			if (c[a[y]] == 2) {
				for (long long j = 1; j <= y; j++) {
					if (x == 1) {
						c[b[j]]--;
						b[j] = 0 ;
					}
					if (b[j] == a[y]) {
						x = 1;
					}
				}
				x = 0;
			}
		}
		for (long long y = i; y <= n; y++) {
			ans[b[y]]++;
		}
		ans[0] = 0;
		for (long long y = 1; y <= n - i + 1; y++) {
			b[y] = 0;
		}
		for (long long y = 1; y <= m; y++) {
			c[y] = 0;
		}
	}
	for (long long i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}