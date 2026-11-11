#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

long long int dp[200010];
long long int dp2[200010];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	int n, m;
	scanf("%d %d", &n, &m);
	long long int v[n + 10] = {0};
	for (int i = 0; i < n; i++) {
		scanf("%lld", &v[i]);
	}
	sort(v, v + n);
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 1; j--) {
			if (j == 1) {
				dp[j] = v[i - 1];
			} else {
				dp[j] = max((dp2[j - 1] & v[i - 1]), dp2[j]);
			}
			dp2[j] = dp[j];
		}

	}
	printf("%lld", dp[m]);

	return 0;
}