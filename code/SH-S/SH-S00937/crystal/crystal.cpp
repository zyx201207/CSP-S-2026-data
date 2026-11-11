#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, ans = 1;
int a[500005], pre[500005];
bool check(int x, int y) {
	int sum = a[y] * (y - x + 1) - (pre[y] - pre[x - 1]);
	return (sum <= m);
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
	for (int i = 1; i <= n; i++) {
		int l = i, r = n, temp = 1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (check(i, mid)) {
				temp = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		ans = max(ans, temp - i + 1);
	}
	cout << ans << "\n";
	return 0;
} 
