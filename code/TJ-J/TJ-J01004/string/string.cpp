#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n, a[200005], b[200005];
char ac[200005][3], bc[200005][3]

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
	scanf("%d", &n);
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		scanf("%s", ac[i] + 1);
		sum += a[i];
	}
	for (int i = n; i >= 1; i--) {
		b[i] = a[n - i + 1];
		bc[i][1] = ac[n - i + 1][1];
	}
	int pos = 1, len = 0;
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		int now = a[i];
		while (now) {
			if (now >= b[pos] - len) {
				now -= b[pos] - len;
				if (ac[i][1] != bc[pos][1]) {
					ans += b[pos] - len;
				}
				len = 0;
				pos++;
			} else {
				len += now;
				if (ac[i][1] != bc[pos][1]) {
					ans += now;
				}
				now = 0;
			}
		}
	}
	printf("%lld", ans / 2);
    return 0;
}
