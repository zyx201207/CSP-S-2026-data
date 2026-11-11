#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], s[500005], sum, sum1 = 1, ans ;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		s[i] = a[i] - a[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			sum += s[j] * (j - i);
			if (sum > m) {
				break;
			}
			sum1++;
		}
		printf("%lld ", sum);
		ans = max(ans, sum1);
		sum = 0;
		sum1 = 1;
	}
	printf("%lld", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
