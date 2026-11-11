#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int a[500010], x[500010], cnt;
int ans[500010];
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		cnt = 0;
		for (int j = i; j <= n; j++) {
			for (int k = 1; k <= cnt; k++) 
				if (a[j] == x[k]) {
					cnt = k - 1;
					break;
				}
			x[++cnt] = a[j];
		}
		for (int j = 1; j <= cnt; j++) ans[x[j]]++;
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
	return 0;
}
