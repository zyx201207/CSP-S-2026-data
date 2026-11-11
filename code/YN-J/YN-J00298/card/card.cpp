#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 7, M = 3e5 + 7;
int n, m, a[N], mask[M], pre[N], cnt[N], ans[M], vis[N];

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = n; i >= 1; i--) {
		if (mask[a[i]]) {
			pre[i] = mask[a[i]];
		} else {
			pre[i] = i + 1, vis[a[i]] = i;
		}
		mask[a[i]] = i, cnt[i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[a[i]] == i) {
			ans[a[i]] = cnt[i];
		}
		cnt[pre[i]] += cnt[i];
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << ' ';
	}
	return 0;
}