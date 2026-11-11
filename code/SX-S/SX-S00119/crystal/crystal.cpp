#include <bits/stdc++.h>
using namespace std;
long long a[500001];
int n, m;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	bool d = 1;
	for (int i = 2; i < n; i++)
		if (a[i] - a[i - 1] != a[i - 1] - a[i - 2]) {
			d = 0;
			break;
		}
	if (d) {
		long long x = 0, ans = 1;
		for (int i = n - 1; i; i--)
			if (x + ans * (a[n] - a[n - 1]) > m)
				break;
			else {
				x += ans * (a[n] - a[n - 1]);
				ans++;
			}
		if (ans == 1)
			printf("0");
	} else {
		int ans = 0;
		for (int i = 2; i <= n; i++) {
			unsigned long long q = 0;
			int num = 1;
			for (int j = i - 1; j; j--) {
				q += a[i] - a[j];
				if (q > m)
					break;
				num++;
			}
			if (num > 1)
				ans = max(ans, num);
		}
		printf("%d", ans);
	}
}
