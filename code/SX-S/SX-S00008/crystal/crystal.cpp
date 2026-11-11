#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int a[500010];
int Max;
int diff;
bool flag2 = 1;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]), Max = max(Max, a[i]);
	sort(a + 1, a + n + 1);
	if (n >= 2)
		diff = a[2] - a[1];
	bool flag1 = 1;
	for (int i = 3; i <= n; i++)
		if (a[i] - a[i - 1] != diff)
			flag1 = 0;
	if (flag1) {
		int tot = 1;
		int sum = 0;
		if (!diff)
			printf("%lld", n), exit(0);
		while (sum + tot * diff <= m) {
			sum += tot * diff;
			tot++;
		}
		printf("%lld", tot), exit(0);
	}
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		int num = 0;
		int t = 1;
		for (int j = i - 1; j >= 1; j--) {
			num += (a[j + 1] - a[j]);
			if (num + sum > m)
				break;
			sum += num;
			t++;
		}
		ans = max(ans, t);
	}
	printf("%lld", ans);
}