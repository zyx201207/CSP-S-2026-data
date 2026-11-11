#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], b[500005], c[500005], v[500005], ans[500005];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = c[a[i]];
		c[a[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		memset(v, 0, sizeof v);
		for (int j = i; j <= n; j++) {
			if (b[j] >= i && v[b[j]] == 0) for (int k = b[j]; k < j; k++) v[k] = 1;
		}
		for (int j = i; j <= n; j++) if (v[j] == 0) ans[a[j]]++;
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
	return 0;
}
