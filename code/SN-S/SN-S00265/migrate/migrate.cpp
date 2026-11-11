#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

int c, t;
int n, d, a[2000001];

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%lld%lld", &c, &t);
	while (t--) {
		scanf("%lld%lld", &n, &d);
		for (int i = 1; i <= n; i++)
			scanf("%lld", &a[i]);
		if (c == 11 || c == 12) {
			int x = d / (a[2] - a[1]);
			if (x == 1) {
				puts("0");
				continue;
			}
			int ans = 0;
			for (int i = 1; i <= n; i++)
				if (n - i >= x + x - 1) ans++;
			printf("%lld\n", ans);
		} else if (c == 13 || c == 14) {
			
		} else if (c <= 10) {
			
		} 
	}
}
