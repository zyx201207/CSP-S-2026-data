#include <bits/stdc++.h>
#define File(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout)
#define int long long
#define endl '\n'
using namespace std;
const int N = 5e5 + 10;
int a[N], p[N], s[N];
int flag;
signed main() {
	File("crystal");
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i < n; i ++) s[i] = a[i + 1] - a[i];
	if (n <= 5000) {
		int cost = 0;
		int ans = INT_MIN;
		for (int j = 1; j <= n; j ++) {
			cost = 0;
			for (int i = j; i <= n; i ++) {
				cost += s[i] * i;
				if (cost > m) {
					ans = max(ans, i - j + 1);
					break;
				}
			}
		}
		cout << ans;
	} else {
		sort(s + 1, s + n);
		int ans = 0;
		int d = 1;
		int l = 1, r = n;
		while(l <= r) {
			int mid = l + r >> 1;
			if (mid * (mid + 1) * d / 2 <= m) {
				l = mid + 1;
				ans = mid + 1;
			} else r = mid - 1;
		}
		cout << ans;
	}
	return 0;
}