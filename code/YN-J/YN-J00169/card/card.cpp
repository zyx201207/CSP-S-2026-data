#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 5e5 + 15;
const int maxnm = 3e5 + 15;
int n, m, a[maxn];
int ans [maxnm];

signed main () {
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		scanf ("%lld", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] != a[i + 1])
			ans[a[i]] = i;
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << " ";
	return 0;
}