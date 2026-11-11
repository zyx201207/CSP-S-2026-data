#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

int n, m, a[500005], s[500005];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) 
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) 
		 s[i] = s[i - 1] + a[i];
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int L = 0, R = i;
		while (L + 1 < R) {
			int M = (L + R) / 2;
			if ((i - M + 1) * a[i] - (s[i] - s[M - 1]) <= m) R = M;
			else L = M;
		}
		ans = max(ans, i - R + 1); 
	}
	printf("%lld", ans);
}
