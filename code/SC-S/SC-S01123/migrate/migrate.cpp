#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 10;
long long loc[maxn], cnt[maxn], dis[maxn], sum[maxn];
int l[maxn];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, T;
	scanf("%d%d", &c, &T);
	while (T--) {
		int n;
		long long d, ans = 0;
		scanf("%d%lld", &n, &d);
		for (int i = 1; i <= n; i++) scanf("%lld", loc + i);
		if (c == 11 || c == 12) {
			long long D = loc[2] - loc[1];
			long long k = d / D;
			if (k < 2) puts("0");
			else {
				if (n < 2 * k) puts("0");
				else printf("%lld\n", 1ll * n - 2 * k + 1);	
			}
		} else {
			int p = 1;
			for (int i = 1; i <= n; i++) {
				while (loc[i] - loc[p] > d) p++;
				l[i] = p;
			}
			for (int i = 1; i <= n; i++) {
				memset(sum, 0, sizeof sum);
				cnt[i] = 1, sum[i] = 1;
				for (int j = i + 1; j <= n; j++) {
					if (l[j] == j) break;
					dis[j] = dis[max(l[j], i)] + 1;
					if (dis[j] > dis[j - 1]) {
						for (int k = j - 1; dis[k] == dis[j - 1] && k >= i; k--)
							sum[k] = sum[k + 1] + cnt[k];					
					}
					cnt[j] = sum[max(l[j], i)];
					if (cnt[j] == 2) ans++;
				}
			}
			printf("%lld\n", ans);			
		}
	}
	return 0;
}