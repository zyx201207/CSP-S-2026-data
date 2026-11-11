#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int n, m, cnt[maxn], ci;
bool flag;
long long a[maxn], p = 1, ans, ans0;

int main() {

	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	while (a[n] > p)
		p *= 2;
	ans0 = p;
	int R = 1;
	for (int i = n; i >= R; i--) {
		if (a[i] >= p) {
			cnt[++ci] = i;
		} else {
			if (ci < m)
				continue;
			if (ci > m) {
				ans0 = max(ans0, p);
				int j = 1;
				for (int i = n; i >= n - ci + 1; i--) {
					a[i] = a[cnt[j++]];
				}
				R = n - ci + 1;
				continue;
			}
			if (ci == m) {
				ans = a[cnt[ci]];
				ci--;
				while (ci--) {
					ans = ans & a[cnt[ci]];
				}
			}
			p /= 2;
		}
	}
	if (ans != 0)
		printf("%lld", ans);
	else
		printf("%lld", ans0);

	return 0;
}