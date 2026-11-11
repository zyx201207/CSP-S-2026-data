#include <iostream>
#define int long long
using namespace std;
int n, m, a[500050], cnt[500010], g[500010], top, k[500010];
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		top = 0;
		for (int j = i; j <= n; j++) {
			if (k[a[j]] == 0 || k[a[j]] > top) {
				if (g[++top] && k[g[top]] == top)
					k[g[top]] = 0;
				g[top] = a[j];
				k[a[j]] = top;
			}
			else
				top = k[a[j]];
		}
		for (int i = 1; i <= top; i++)
			cnt[g[i]]++;
	}
	for (int i = 1; i <= m; i++)
		printf("%d ", cnt[i]);
	return 0;
}