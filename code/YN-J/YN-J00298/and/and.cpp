#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 7;
int n, a[N], cnt[40], ans, m;
bool vis[N][40], flg[N];

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		int x = a[i];
		for (int j = 0; x; j++, x >>= 1) {
			vis[i][j] = (x & 1);
		}
	}
	for (int t = 30; t >= 0; t--) {
		for (int i = 1; i <= n; i++) {
			if (flg[i])
				continue;
			cnt[t] += vis[i][t];
		}
		if (cnt[t] >= m) {
			for (int i = 1; i <= n; i++) {
				if (!vis[i][t])
					flg[i] = true;
			}
			ans += (1 << t);
		}
	}
	cout << ans << '\n';
	return 0;
}