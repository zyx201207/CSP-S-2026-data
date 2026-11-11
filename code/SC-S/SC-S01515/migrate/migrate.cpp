#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6 + 10;

int c, t, n, d, a[N], f[N], g[N];

signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%lld %lld", &c, &t);
	while (t --> 0){
		int ans = 0;
		scanf("%lld %lld", &n, &d);
		for (int i = 1; i <= n; i++)
			scanf("%lld", &a[i]);
		for (int i = 1; i <= n; i++){
			for (int j = i + 1; j <= n; j++)
				f[j] = 3e18;
			f[i] = 0, g[i] = 1;
			for (int j = i + 1; j <= n; j++){
				for (int k = j - 1; k >= i; k--){
					if (a[j] - a[k] > d) break ;
					if (f[k] + 1 < f[j])
						f[j] = f[k] + 1, g[j] = g[k];
					else if (f[k] + 1 == f[j]) g[j] += g[k];
				}
				if (g[j] == 2) ans++;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}