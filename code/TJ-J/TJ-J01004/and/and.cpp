#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int B = 400; 

int n, m, a[200005], bres[605];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	if (n <= 20) {
		ll ans = 0;
		for (int i = 0; i < (1 << n); i++) {
			ll res = (1 << 20) - 1;
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				if (i & (1 << j)) {
					res &= a[j + 1];
					cnt++;
				}
			}
			if (cnt == m)
				ans = max(ans, res);
		}
		printf("%lld\n", ans);
	} else if (n <= 2000) {
		if (m == 1) {
			ll ans = 0;
			for (int i = 1; i <= n; i++)
				ans = max(ans, (ll)a[i]);
			printf("%lld\n", ans);
		} else if (m == n) {
			ll ans = a[1];
			for (int i = 2; i <= n; i++) {
				ans &= a[i];
			} 
			printf("%lld\n", ans);
		} else {
			ll ans = 0;
			for (int i = 1; i <= n; i++) 
				for (int j = 1; j <= n; j++) if (i != j) 
					ans = max(ans, (ll)a[i] & a[j]);
			printf("%lld\n", ans);
		}
	} else {
		if (m == n - 1) {
			for (int i = 1; i <= 500; i++)
				bres[i] = (1 << 20) - 1;
			for (int i = 1; i <= n; i++) {
				int t = (i - 1) / B + 1;
				bres[t] &= a[i];
			}
			ll ans = 0;
			for (int i = 1; i <= n; i++) {
				ll res = (1 << 20) - 1;
				int t = (i - 1) / B + 1;
				for (int j = 1; j <= 500; j++) if (j != t) {
					res &= bres[j];
				}
				for (int j = (t - 1) * B + 1; j <= t * B && j <= n; j++) if (j != i) {
					res &= a[j];
				}
				ans = max(ans, res);
			}
			printf("%lld\n", ans);
		} else {
			int maxa = 0;
			for (int i = 1; i <= n; i++)
				maxa = max(maxa, a[i]);
			if (maxa < 4) {
				int b[10] = {};
				for (int i = 1; i <= n; i++) 
					b[a[i]]++;
				if (b[3] >= m) 
					printf("3\n");
				else if (b[2] + b[3] >= m)
					printf("2\n");
				else if (b[1] + b[3] >= m)
					printf("1\n");
				else
					printf("0\n");
			} else if (maxa < (1 << 20)) {
				if (a[3] != 2) {
					sort(a + 1, a + n + 1, cmp);
					printf("%d\n", a[m]);
				} else {
					if (m > n / 2) {
						printf("0\n");
					} else {
						int cnt = 1;
						ll res = 0;
						while (m <= (n >> cnt)) {
							res = res * 2 + 1;
							cnt++;
						}
						for (int i = cnt; (n >> i) > 0; i++)
							res <<= 1;
						printf("%lld\n", res); 
					}
				}
			} else {
				printf("0\n");
			}
		}
	}
    return 0;
}
