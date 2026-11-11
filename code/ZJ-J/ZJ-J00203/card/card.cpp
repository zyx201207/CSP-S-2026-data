#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5, M = 3e3 + 5;
int n, m, a[N], p[N][M], mx, ans[M], lst, cnt[M];
int vis[N];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m; lst = n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			p[i][j] = p[i - 1][j];
		}
		p[i][a[i]]++;
	}
	for (int i = n; i >= 1; i--) {
		if (vis[a[i]]) {
			int qq = min(vis[a[i]], lst);
			//cout << i << " " << vis[a[i]] << " " << lst << "\n";
			for (int j = 1; j <= m; j++) {
				cnt[j] -= (p[qq][j] - p[i][j]);
			}
			lst = i;
		} else {
			vis[a[i]] = i;
		}
		cnt[a[i]]++;
		for (int j = 1; j <= m; j++) {
			if (cnt[j]) ans[j]++;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}