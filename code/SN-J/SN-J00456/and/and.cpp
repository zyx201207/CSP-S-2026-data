#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
bool flag[200005];
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int k = 30; k >= 0; k--) {
		int cnt = 0;
		for (int i = 1; i <= n; i++) if (!flag[i] && ((a[i] >> k) & 1) == 1) cnt++;
//		cout << cnt << "\n";
		if (cnt < m) continue;
		else {
			ans += (1 << k);
			for (int i = 1; i <= n; i++) if (!flag[i] && ((a[i] >> k) & 1) == 0) flag[i] = 1;
		}
	}
	cout << ans;
	return 0;
}
