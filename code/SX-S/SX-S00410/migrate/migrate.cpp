#include <bits/stdc++.h>
using namespace std;
int c, t;
const int N = 2e6+10;
long long n, d, ans;
long long x[N];
int f[N];
long long e[N];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while (t--) {
		scanf("%lld%lld", &n, &d);
		ans = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &x[i]);
		}
		for (int i = 1; i <= n; i++) {
			memset(f, 0, sizeof(f));
			memset(e, 0, sizeof(e));
			e[i] = 1;
			for (int j = i + 1; j <= n; j++) {
				for (int k = 1; j - k >= i && x[j] - x[j - k] <= d; k++) {
					if (f[j] == 0)
						f[j] = f[j - k];
					if (f[j] == f[j - k]) {
						e[j] += e[j - k];
					} else if (f[j] > f[j - k]) {
						e[j] = e[j - k];
						f[j] = f[j - k];
					}
				}
				f[j]++;
				if (e[j] == 2) {
					ans++;
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}//18.25 24->??
//真写不动了，如果不睡觉发呆说不定特殊性质和t4还能再得一点分
//空悲切
//t3看着简单，但应该有紫题水平了
//t2这次好像真的挺难的
