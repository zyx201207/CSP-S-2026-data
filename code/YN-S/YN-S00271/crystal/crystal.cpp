#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10;
int n, m, ans;
long long a[maxn], c[maxn], cnt;

int main() {

	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++)
		c[i] = a[i] - a[i - 1];
	for (int i = n; i >= 1; i--) {
		if (c[i] > m)
			continue;
		cnt = 0;
		for (int j = i - 1; j >= 1; j--) {
			if (c[i] * (i - j) <= m - cnt) {
				ans = max(ans, i - j + 1);
				cnt += c[i] * (i - j);
			} else {
				continue;
			}
		}
	}
	printf("%d", ans);

	return 0;
}