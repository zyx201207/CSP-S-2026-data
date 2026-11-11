#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ull unsigned long long

const int N = 2e6 + 5;

ll c, t, n, m, a[N], dis[N], f[N], tl[N], vis[N], T;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	if (c == 11 || c == 12) {
		while (t--) {
			scanf("%lld%lld", &n, &m);
			for (int i = 1; i <= n; i++)scanf("%lld", &a[i]);
			if(n == 1){
				printf("0\n");
				continue;
			}
			ll d = m / (a[2] - a[1]);
			if(d <= 1){
				printf("0\n");
				continue;
			}
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				if(i + 2 * d - 1 <= n)ans++;
			}
			printf("%d\n", ans);
		}
		return 0;
	}
	while (t--) {
		scanf("%lld%lld", &n, &m);
		for (int i = 1; i <= n; i++)scanf("%lld", &a[i]);
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			T++;
			for (int j = i - 1; j <= n; j++) dis[j] = 0x3f3f3f3f, f[j] = 0;
			dis[i] = 0, f[i] = 1, f[i + 1] = -1;
			int mx = 0;
			for (int j = i, r = i + 1; j <= n; j++) {
				if (dis[j] > N)break;
				while (r <= n && a[j] + m >= a[r]) {
					dis[r] = dis[j] + 1;
					if (vis[dis[r]] != T)
						vis[dis[r]] = T, tl[dis[r]] = r;
					mx = dis[r], r++;
				}
			}
			for (int j = i, r = i + 1; j <= n; j++) {
				if (dis[j] > N)break;
				f[j] += f[j - 1];
				if (f[j] == 2) {
					ans++;
				}
				if (dis[j] == mx) continue;
				while (r <= n && a[j] + m >= a[r]) r++;
				f[tl[dis[j] + 1]] += min(f[j], 10151500ll), f[r] -= min(f[j], 10151500ll);
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}
/*
0 1
10 272727272727272724
-999999999999999976 -727272727272727252 -454545454545454528 -181818181818181804 -90909090909090896 12 181818181818181828 454545454545454552 727272727272727276 1000000000000000000
*/
