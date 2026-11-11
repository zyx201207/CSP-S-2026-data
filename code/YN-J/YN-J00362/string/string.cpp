#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e8 + 10000;
long long n;
long long m[maxn];
char c[maxn];
long long ans = 0;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	memset(m, 0, sizeof(m));
	memset(c, 0, sizeof(c));
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld %c", &m[i], &c[i]);
	}
	for (int i = 1; i <= (n + 1) / 2; i++) {
		if (c[i] == c[n +  1 - i]) {
			if (m[i] != m[n + 1 - i]) {
				long long l = m[i];
				long long p = m[n + 1 - i];
				if (l >= p) {
					cout << l << " ";
					ans += l;
				} else {
					cout << p << " ";
					ans += p;
				}
			}
		} else {
			long long l = m[i];
			long long p = m[n + 1 - i];
			if (l >= p) {

				ans += l;
			} else {
				ans += p;
			}
		}
	}
	printf("%lld", ans);
	return 0;
}